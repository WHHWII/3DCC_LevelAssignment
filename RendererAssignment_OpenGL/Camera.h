


class Camera {
public:
	float fov = 65.5f;
	GW::MATH::GMATRIXF transform = GW::MATH::GIdentityMatrixF;
	//G2D_PI_F;
	GW::INPUT::GInput inputLib;
	GW::INPUT::GController controllerLib;
	GW::MATH::GMatrix matrixLib;
	Renderer& renderer;

	const float moveSpeed = 0.3f;
	const float sensitivity = 0.1f;

	unsigned int windowHeight = 0;
	unsigned int windowWidth = 0;


	bool isActive = false; // user is currently controlling this camera

	Camera(Renderer &_renderer) : renderer(_renderer) {
		inputLib.Create(renderer.win);
		controllerLib.Create();
		renderer.win.GetHeight(windowHeight);
		renderer.win.GetWidth(windowWidth);

		
	}

	GW::MATH::GMATRIXF UpdateCamera() {
		if (!isActive) return transform;
#pragma region updatePosition



		//udpate position
		GW::MATH::GVECTORF globalMoveVector = GW::MATH::GIdentityVectorF;
		GW::MATH::GVECTORF localMoveVector = GW::MATH::GIdentityVectorF;
		float yMove = 0;
		float xMove = 0;
		float zMove = 0;

#pragma region getInput



		 // should seperate out input into its own thing
		float keyStates[256] = { 0 };
		for (size_t i = 0; i < ARRAYSIZE(keyStates); i++)
		{
			inputLib.GetState(G_KEY_UNKNOWN + i, keyStates[i]);
		}

		float controllerStates[24] = { 0 };
		bool controllerConnected = false;
		controllerLib.IsConnected(0, controllerConnected);
		if (controllerConnected) {
			for (size_t i = 0; i < ARRAYSIZE(controllerStates); i++)
			{
				inputLib.GetState(G_KEY_UNKNOWN + i, controllerStates[i]);
			}
		}
#pragma endregion getInput

		yMove = keyStates[G_KEY_SPACE] - keyStates[G_KEY_LEFTSHIFT] + controllerStates[G_RIGHT_TRIGGER_AXIS] - controllerStates[G_LEFT_TRIGGER_AXIS];
		xMove = keyStates[G_KEY_D] - keyStates[G_KEY_A] + controllerStates[G_LX_AXIS];
		zMove = keyStates[G_KEY_W] - keyStates[G_KEY_S] + controllerStates[G_LY_AXIS];

		if (yMove != 0)
		{
			globalMoveVector.y = yMove * moveSpeed * renderer.deltaTime;
			matrixLib.TranslateGlobalF(transform, globalMoveVector, transform);
		}
		if (xMove != 0 || zMove != 0)
		{
			localMoveVector.x = xMove * moveSpeed * renderer.deltaTime;
			localMoveVector.z = zMove * moveSpeed * renderer.deltaTime;
			matrixLib.TranslateLocalF(transform, localMoveVector, transform);
		}
#pragma endregion updatePosition

#pragma region UpdateRotation



		//Update Rotation
		GW::MATH::GMATRIXF pitchMatrix = GW::MATH::GIdentityMatrixF;
		float thumbSpeed = G2D_PI * renderer.deltaTime;
		float pitchMove = 0;
		float yawMove = 0;
		float xDelta, yDelta = 0;
		GW::GReturn result = inputLib.GetMouseDelta(xDelta, yDelta);
		if (result == GW::GReturn::SUCCESS && result != GW::GReturn::REDUNDANT) {

			pitchMove = fov * sensitivity * yDelta / windowHeight;
			yawMove = fov * sensitivity * xDelta / windowWidth;
			if (controllerConnected) pitchMove += controllerStates[G_RY_AXIS] * thumbSpeed;
			if (controllerConnected) yawMove += controllerStates[G_RX_AXIS] * thumbSpeed;


			matrixLib.RotateXLocalF(transform, pitchMove, transform);
			matrixLib.RotateYGlobalF(transform, yawMove, transform);
		}
#pragma endregion UpdateRotation

		return transform; // will need to be inversed in the renderer to form the view matrix.
	}






};

