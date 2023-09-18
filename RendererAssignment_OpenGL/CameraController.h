//
//class CameraController {
//	GW::INPUT::GInput inputLib;
//	GW::INPUT::GController controllerLib;
//	GW::MATH::GMatrix matrixLib;
//	unsigned int windowHeight = 0;
//	unsigned int windowWidth = 0;
//	const float moveSpeed = 0.3f;
//	const float sensitivity = 0.1f;
//	Renderer &renderer;
//	GW::MATH::GMATRIXF *viewMatrix;
//	const float pi = 3.14159265359f; // does gateware really not have pi? its gotta but i cant find it 
//	const float fov = 65.0f; // need to make this not stored in two seperate places. probably need camera class.
//public:
//	CameraController(GWindow& _win, GW::MATH::GMATRIXF &_viewMatrix, Renderer &_renderer) : renderer(_renderer)  {
//		inputLib.Create(_win);
//		controllerLib.Create();
//		matrixLib.Create();
//		_win.GetHeight(windowHeight);
//		_win.GetWidth(windowWidth);
//		viewMatrix = viewMatrix;
//	}
//
//	void UpdateCamera() {
//
//
//		//udpate position
//		GW::MATH::GMATRIXF cameraMatrix;
//		matrixLib.InverseF(viewMatrix, cameraMatrix);
//		GW::MATH::GVECTORF globalMoveVector = GW::MATH::GIdentityVectorF;
//		GW::MATH::GVECTORF localMoveVector = GW::MATH::GIdentityVectorF;
//		float yMove = 0;
//		float xMove = 0;
//		float zMove = 0;
//
//		float outStates[4] = { 0 };
//
//
//		float keyStates[256] = { 0 };
//		for (size_t i = 0; i < ARRAYSIZE(keyStates); i++)
//		{
//			inputLib.GetState(G_KEY_UNKNOWN + i, keyStates[i]);
//		}
//
//		float controllerStates[24] = { 0 };
//		bool controllerConnected = false;
//		controllerLib.IsConnected(0, controllerConnected);
//		if (controllerConnected) {
//			for (size_t i = 0; i < ARRAYSIZE(controllerStates); i++)
//			{
//				inputLib.GetState(G_KEY_UNKNOWN + i, controllerStates[i]);
//			}
//		}
//
//		yMove = keyStates[G_KEY_SPACE] - keyStates[G_KEY_LEFTSHIFT] + controllerStates[G_RIGHT_TRIGGER_AXIS] - controllerStates[G_LEFT_TRIGGER_AXIS];
//		xMove = keyStates[G_KEY_D] - keyStates[G_KEY_A] + controllerStates[G_LX_AXIS];
//		zMove = keyStates[G_KEY_W] - keyStates[G_KEY_S] + controllerStates[G_LY_AXIS];
//
//		if (yMove != 0)
//		{
//			globalMoveVector.y = yMove * moveSpeed * renderer.deltaTime;
//			matrixLib.TranslateGlobalF(cameraMatrix, globalMoveVector, cameraMatrix);
//		}
//		if (xMove != 0 || zMove != 0)
//		{
//			localMoveVector.x = xMove * moveSpeed * renderer.deltaTime;
//			localMoveVector.z = zMove * moveSpeed * renderer.deltaTime;
//			matrixLib.TranslateLocalF(cameraMatrix, localMoveVector, cameraMatrix);
//		}
//
//		//Update Rotation
//		GW::MATH::GMATRIXF pitchMatrix = GW::MATH::GIdentityMatrixF;
//		float thumbSpeed = pi * renderer.deltaTime;
//		float pitchMove = 0;
//		float yawMove = 0;
//		float xDelta, yDelta = 0;
//		GW::GReturn result = inputLib.GetMouseDelta(xDelta, yDelta);
//		if (result == GW::GReturn::SUCCESS && result != GW::GReturn::REDUNDANT) {
//
//			pitchMove = fov * sensitivity * yDelta / windowHeight;
//			yawMove = fov * sensitivity * xDelta / windowWidth;
//			if (controllerConnected) pitchMove += controllerStates[G_RY_AXIS] * thumbSpeed;
//			if (controllerConnected) yawMove += controllerStates[G_RX_AXIS] * thumbSpeed;
//
//
//			matrixLib.RotateXLocalF(cameraMatrix, pitchMove, cameraMatrix);
//			matrixLib.RotateYGlobalF(cameraMatrix, yawMove, cameraMatrix);
//		}
//
//		matrixLib.InverseF(cameraMatrix, viewMatrix);
//	}
//
//
//};