

#include <filesystem>
namespace fs = std::filesystem;
void PrintLabeledDebugString(const char* label, const char* toPrint)
{
	std::cout << label << toPrint << std::endl;
#if defined WIN32 //OutputDebugStringA is a windows-only function 
	OutputDebugStringA(label);
	OutputDebugStringA(toPrint);
#endif
}

// Used to print debug infomation from OpenGL, pulled straight from the official OpenGL wiki.
#ifndef NDEBUG
void APIENTRY
MessageCallback(GLenum source, GLenum type, GLuint id,
	GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam) {


	std::string errMessage;
	errMessage = (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "");
	errMessage += " type = ";
	errMessage += type;
	errMessage += ", severity = ";
	errMessage += severity;
	errMessage += ", message = ";
	errMessage += message;
	errMessage += "\n";

	PrintLabeledDebugString("GL CALLBACK: ", errMessage.c_str());
}
#endif

// Creation, Rendering & Cleanup
class Renderer
{
public:
	// proxy handles
	GW::SYSTEM::GWindow win;
private:
	GW::GRAPHICS::GOpenGLSurface ogl;
	Level_Data &levelData;

	// what we need at a minimum to draw a triangle
	GLuint vertexArray = 0;
	GLuint vertexBufferObject = 0;
	// TODO: Part 1g
	GLuint indexBufferObject = 0;
	GLuint vertexShader = 0;
	GLuint fragmentShader = 0;
	GLuint geometryShader = 0;
	GLuint shaderExecutable = 0;


	GLuint uboBufferObject = 0;
	GLuint uboBindingIndex = 0;

	GLuint ssboBufferObject = 0;
	GLuint ssboBindingIndex = 0;

	GW::MATH::GVector vectorLib;
	GW::MATH::GMatrix matrixLib;
	GW::MATH::GMATRIXF worldMatrix =		GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF viewMatrix =			GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF projectionMatrix =	GW::MATH::GIdentityMatrixF;

	//passed from instances during draw calls
	int transfromIndexUniLocation = 0;
	int materialIndexUniLocation = 0;
	
#pragma region CameraVars
	//camera
	GW::INPUT::GInput inputLib;
	GW::INPUT::GController controllerLib;
	unsigned int windowHeight = 0;
	unsigned int windowWidth = 0;
	const float moveSpeed = 2.0f;
	const float sensitivity = 0.1f;
	float fov = 65.0f;
	GW::MATH::GMATRIXF camTransform = GW::MATH::GIdentityMatrixF; // used for keeping track of cameras position indipendently of view Matrix
#pragma endregion CameraVars

#pragma region  InputVars
	//input
	float keyStates[256] = { 0 };
	float controllerStates[24] = { 0 };
	bool controllerConnected = false;
	std::chrono::steady_clock::time_point lastFrameTime;
#pragma endregion InputVars

	//light
	GW::MATH::GVECTORF lightDirection = GW::MATH::GIdentityVectorF;
	GW::MATH::GVECTORF lightColor = GW::MATH::GIdentityVectorF;
	GW::MATH::GVECTORF ambientColor = GW::MATH::GIdentityVectorF;
	
	

	// TODO: Part 2b
	struct UBO_DATA
	{
		GW::MATH::GMATRIXF viewMatrix, projectionMatrix;
		GW::MATH::GVECTORF sunDirection, sunColor; 
		GW::MATH::GVECTORF sunAmbient, camPos;
		
		
	};
	UBO_DATA ubo;

	struct SSBO_DATA
	{
		GW::MATH::GMATRIXF allTransforms[100] = { GW::MATH::GIdentityVectorF };
		H2B::ATTRIBUTES allMaterials[100];
	};
	SSBO_DATA ssbo;

	const float dtor = 0.0174533f;
public:


	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GOpenGLSurface _ogl, Level_Data &_levelData) : levelData(_levelData)
	{
		win = _win;
		ogl = _ogl;

		matrixLib.Create();
		vectorLib.Create();
		inputLib.Create(win);
		controllerLib.Create();

		win.GetHeight(windowHeight);
		win.GetWidth(windowWidth);

		InitializeLight();
		SetMatrixPosRot(worldMatrix, 0, 0, 0, 0, 0, 0);
		InitializeViewMatrix();
		InitializeProjectionMatrix();
		// TODO: Part 2b

		
		// TODO: Part 4e
		InitializeGraphics();
		LocateUniforms();
	}

private:
	//constructor helper functions 
	void InitializeGraphics()
	{
#ifndef NDEBUG
		BindDebugCallback(); // In debug mode we link openGL errors to the console
#endif
		InitializeUbo();
		InitializeSSBO();

		IntializeBuffers();

		CompileVertexShader();
		CompileGeometryShader();
		CompileFragmentShader();
		CreateExecutableShaderProgram();

		SetVertexAttributes();
	}

#ifndef NDEBUG
	void BindDebugCallback()
	{
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);
	}
#endif

	void IntializeBuffers()
	{
		CreateVertexBuffer(&levelData.levelVertices[0], levelData.levelVertices.size() * sizeof(H2B::VERTEX));
		CreateIndexBuffer(&levelData.levelIndices[0], levelData.levelIndices.size() * sizeof(unsigned)); // sizeof data did not work for some reason
		CreateUboBuffer(&ubo, sizeof(ubo));
		CreateSSBOBuffer();
	}

	void InitializeUbo() {
		ubo.projectionMatrix = projectionMatrix;
		ubo.viewMatrix = viewMatrix;
		ubo.sunDirection = lightDirection;
		ubo.sunColor = lightColor;
		ubo.sunAmbient = ambientColor;
		ubo.camPos = camTransform.row4; 
	}

	//copy transforms and materials over into SSBO
	void InitializeSSBO() {
		for (int t = 0; t < levelData.levelTransforms.size(); t++) {
			ssbo.allTransforms[t] = levelData.levelTransforms[t];
		}
		for (int m = 0; m < levelData.levelMaterials.size(); m++) {
			ssbo.allMaterials[m] = levelData.levelMaterials[m].attrib;
		}

	}

	void PrintMatrix(GW::MATH::GMATRIXF mat) {
		printf("%f, %f, %f, %f\n", mat.row1.x, mat.row1.y, mat.row1.z, mat.row1.w);
		printf("%f, %f, %f, %f\n", mat.row2.x, mat.row2.y, mat.row2.z, mat.row2.w);
		printf("%f, %f, %f, %f\n", mat.row3.x, mat.row3.y, mat.row3.z, mat.row3.w);
		printf("%f, %f, %f, %f\n", mat.row4.x, mat.row4.y, mat.row4.z, mat.row4.w);
	}

	void SetMatrixPosRot(GW::MATH::GMATRIXF& matrix, float xt, float yt, float zt, float xr, float yr, float zr) {
		GW::MATH::GVECTORF moveVector = GW::MATH::GIdentityVectorF;
		moveVector.x = xt;
		moveVector.y = yt;
		moveVector.z = zt;
		if (xr != 0) matrixLib.RotateXGlobalF(matrix,  xr * dtor, matrix);
		if (yr != 0) matrixLib.RotateYGlobalF(matrix,  yr * dtor, matrix);
		if (zr != 0) matrixLib.RotateZGlobalF(matrix,  zr * dtor, matrix);
		//printf("%f,%f,%f,%f\n", worldVector.x, worldVector.y, worldVector.z, worldVector.w);
		matrixLib.TranslateGlobalF(matrix, moveVector, matrix);
	}

	void InitializeLight() {
		lightDirection.x = -1;
		lightDirection.y = -1;
		lightDirection.z = -2;
		vectorLib.NormalizeF(lightDirection, lightDirection);

		lightColor.x = 0.9f;
		lightColor.y = 0.9f;
		lightColor.z = 1;

		ambientColor.x = .25f;
		ambientColor.y = .25f;
		ambientColor.z = .35f;
	}

	void InitializeViewMatrix() {
		matrixLib.LookAtRHF(GW::MATH::GVECTORF{ 0.75f, 10.0f, -5.0f },
			GW::MATH::GVECTORF{ 0.15f, 0.75f, 0.0f },
			GW::MATH::GVECTORF{ 0.0f, 1.0f, 0.0f },
			viewMatrix);
		//lookate places matrix in view space, this updates transfrom by re-inverting the viewMatrix
		matrixLib.InverseF(viewMatrix, camTransform);
	}

	void InitializeProjectionMatrix() {
		float aspectRatio;
		ogl.GetAspectRatio(aspectRatio);
		matrixLib.ProjectionOpenGLRHF(fov * dtor, aspectRatio, 0.1, 100, projectionMatrix);
	}

	void CreateVertexBuffer(const void* data, unsigned int sizeInBytes)
	{
		glGenVertexArrays(1, &vertexArray);
		glGenBuffers(1, &vertexBufferObject);
		glBindVertexArray(vertexArray);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeInBytes, data, GL_STATIC_DRAW);
	}

	void CreateIndexBuffer(const void* data, unsigned int sizeInBytes)
	{
		glGenBuffers(1, &indexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeInBytes, data, GL_STATIC_DRAW);
	}

	void CreateUboBuffer(const void* data, unsigned int sizeInBytes) {
		glGenBuffers(1, &uboBufferObject);
		glBindBuffer(GL_UNIFORM_BUFFER, uboBufferObject);
		glBufferData(GL_UNIFORM_BUFFER, sizeInBytes, data, GL_DYNAMIC_DRAW);
	}

	void CreateSSBOBuffer() {
		glGenBuffers(1, &ssboBufferObject);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssboBufferObject);
		glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(SSBO_DATA), &ssbo, GL_DYNAMIC_COPY);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

		GLuint loc = glGetProgramResourceIndex(shaderExecutable, GL_SHADER_STORAGE_BLOCK, "SSBO");
		glShaderStorageBlockBinding(shaderExecutable, loc, ssboBindingIndex);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, ssboBindingIndex, ssboBufferObject);
	}

	void CompileVertexShader()
	{
		char errors[1024];
		GLint result;

		vertexShader = glCreateShader(GL_VERTEX_SHADER);

		std::string vertexShaderSource = ReadFileIntoString("../Shaders/VertexShader.glsl");
		const GLchar* strings[1] = { vertexShaderSource.c_str() };
		const GLint lengths[1] = { vertexShaderSource.length() };
		glShaderSource(vertexShader, 1, strings, lengths);

		glCompileShader(vertexShader);
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(vertexShader, 1024, NULL, errors);
			PrintLabeledDebugString("Vertex Shader Errors:\n", errors);
			abort();
			return;
		}
	}

	void CompileGeometryShader()
	{
		char errors[1024];
		GLint result;

		geometryShader = glCreateShader(GL_GEOMETRY_SHADER);

		std::string geometryShaderSource = ReadFileIntoString("../Shaders/GeometryShader.glsl");
		const GLchar* strings[1] = { geometryShaderSource.c_str() };
		const GLint lengths[1] = { geometryShaderSource.length() };
		glShaderSource(geometryShader, 1, strings, lengths);

		glCompileShader(geometryShader);
		glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(geometryShader, 1024, NULL, errors);
			PrintLabeledDebugString("Geometry Shader Errors:\n", errors);
			abort();
			return;
		}
	}

	void CompileFragmentShader()
	{
		char errors[1024];
		GLint result;

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		std::string fragmentShaderSource = ReadFileIntoString("../Shaders/FragmentShader.glsl");
		const GLchar* strings[1] = { fragmentShaderSource.c_str() };
		const GLint lengths[1] = { fragmentShaderSource.length() };
		glShaderSource(fragmentShader, 1, strings, lengths);

		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(fragmentShader, 1024, NULL, errors);
			PrintLabeledDebugString("Fragment Shader Errors:\n", errors);
			abort();
			return;
		}
	}



	void CreateExecutableShaderProgram()
	{
		char errors[1024];
		GLint result;

		shaderExecutable = glCreateProgram();
		glAttachShader(shaderExecutable, vertexShader);
		glAttachShader(shaderExecutable, geometryShader);
		glAttachShader(shaderExecutable, fragmentShader); 
		glLinkProgram(shaderExecutable);
		glGetProgramiv(shaderExecutable, GL_LINK_STATUS, &result);
		if (result == false)
		{
			glGetProgramInfoLog(shaderExecutable, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}
	}

	void SetVertexAttributes()
	{
		//TODO: Part 1e
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)offsetof(H2B::VERTEX, pos));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)offsetof(H2B::VERTEX, uvw));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(H2B::VERTEX), (void*)offsetof(H2B::VERTEX, nrm));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
	}

	void LocateUniforms() {
		transfromIndexUniLocation = glGetUniformLocation(shaderExecutable, "uTransformIndex");
		materialIndexUniLocation = glGetUniformLocation(shaderExecutable, "uMaterialIndex");
	}
public:
	float deltaTime = 0.0f;
	void Render()
	{
		SetUpPipeline();
		SetupUbo();
		SetupSSBO();
		
		
		

		for (int i = 0; i < levelData.levelInstances.size(); i++) // loop through all instances (unique models)
		{

			auto instance = levelData.levelInstances[i]; // each unique model is stored in an instance, which is used to draw the same model in different locs/orientations
			auto model = levelData.levelModels[instance.modelIndex]; // the model of the instance

			glUniform1ui(transfromIndexUniLocation, instance.transformStart);

			for (int subMeshIdx = 0; subMeshIdx < model.meshCount; subMeshIdx++)  // each sub mesh of the model
			{ 
				auto curMesh = levelData.levelMeshes[model.meshStart + subMeshIdx]; 

				
				glUniform1ui(materialIndexUniLocation, model.materialStart + curMesh.materialIndex);
				

				auto indicies = reinterpret_cast <GLvoid*> ((model.indexStart + curMesh.drawInfo.indexOffset) * sizeof(unsigned int));
				glDrawElementsInstancedBaseVertex(GL_TRIANGLES, curMesh.drawInfo.indexCount, GL_UNSIGNED_INT, indicies, instance.transformCount, model.vertexStart);

			}

			//H2B::MESH curMesh; //current submesh of the model
			//for (int t = 0; t < instance.transformCount; t++) {  // each unique location/orientation where this model is drawn
			//	for (int subMeshIdx = 0; subMeshIdx < model.meshCount; subMeshIdx++) { // each sub mesh of the model
			//		curMesh = levelData.levelMeshes[model.meshStart + subMeshIdx]; 
			//
			//		
			//		ubo.material = levelData.levelMaterials[model.materialStart + curMesh.materialIndex].attrib; // this will only grab first material, need to fix later.
			//		ubo.world = levelData.levelTransforms[instance.transformStart + t];
			//		
			//		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(UBO_DATA), &ubo);
			//		
			//
			//		auto indicies = reinterpret_cast <GLvoid*> ((model.indexStart + curMesh.drawInfo.indexOffset) * sizeof(unsigned int));
			//		glDrawElementsInstancedBaseVertex(GL_TRIANGLES, curMesh.drawInfo.indexCount, GL_UNSIGNED_INT, indicies, 1, model.vertexStart);
			//	}
			//
			//}

		}
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		glBindVertexArray(0); // some video cards(cough Intel) need this set back to zero or they won't display
		glUseProgram(0);
	}



#pragma region stowaways



	//should seperate out int different class
	void TickFrame() {
		auto curFrameTime = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(curFrameTime - lastFrameTime).count() / 1000000.0f;
		lastFrameTime = curFrameTime;
	}
	//should seperate out into different class
	void UpdateCamera() {
		//udpate position
		GW::MATH::GVECTORF globalMoveVector = GW::MATH::GIdentityVectorF;
		GW::MATH::GVECTORF localMoveVector = GW::MATH::GIdentityVectorF;

		float yMove = keyStates[G_KEY_SPACE] - keyStates[G_KEY_LEFTSHIFT] + controllerStates[G_RIGHT_TRIGGER_AXIS] - controllerStates[G_LEFT_TRIGGER_AXIS];
		float xMove = keyStates[G_KEY_D] - keyStates[G_KEY_A] + controllerStates[G_LX_AXIS];
		float zMove = keyStates[G_KEY_W] - keyStates[G_KEY_S] + controllerStates[G_LY_AXIS];

		if (yMove != 0)
		{
			globalMoveVector.y = yMove * moveSpeed * deltaTime;
			matrixLib.TranslateGlobalF(camTransform, globalMoveVector, camTransform);
		}
		if (xMove != 0 || zMove != 0)
		{
			localMoveVector.x = xMove * moveSpeed * deltaTime;
			localMoveVector.z = -zMove * moveSpeed * deltaTime;
			matrixLib.TranslateLocalF(camTransform, localMoveVector, camTransform);
		}

		//Update Rotation
		GW::MATH::GMATRIXF pitchMatrix = GW::MATH::GIdentityMatrixF;
		float thumbSpeed = G2D_PI_F * deltaTime;
		float pitchMove = 0;
		float yawMove = 0;
		float xDelta, yDelta = 0;
		GW::GReturn result = inputLib.GetMouseDelta(xDelta, yDelta);
		if (keyStates[G_BUTTON_LEFT] == 1 && result == GW::GReturn::SUCCESS && result != GW::GReturn::REDUNDANT) {

			pitchMove = fov * sensitivity * yDelta / windowHeight;
			yawMove = fov * sensitivity * xDelta / windowWidth;

			matrixLib.RotateXLocalF(camTransform, -pitchMove, camTransform);
			matrixLib.RotateYGlobalF(camTransform, -yawMove, camTransform);
		}
		else if (controllerConnected && (controllerStates[G_RY_AXIS] != 0 || controllerStates[G_RX_AXIS] != 0)) {
			pitchMove += controllerStates[G_RY_AXIS] * thumbSpeed;
			yawMove -= controllerStates[G_RX_AXIS] * thumbSpeed;

			matrixLib.RotateXLocalF(camTransform, pitchMove, camTransform);
			matrixLib.RotateYGlobalF(camTransform, yawMove, camTransform);
		}

		matrixLib.InverseF(camTransform, viewMatrix);
	}
	//should sperate out into differnt class
	void ChangeLevel() 
	{
		if (keyStates[G_KEY_F1] == 0) return;
		//add debounce?
		printf("F1 pressed for changing levels");

		HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
			COINIT_DISABLE_OLE1DDE);
		if (SUCCEEDED(hr))
		{
			IFileOpenDialog* pFileOpen;

			//pulled from the winapi examples
			// Create the FileOpenDialog object.
			hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
				IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

			if (SUCCEEDED(hr))
			{
				// Show the Open dialog box.
				hr = pFileOpen->Show(NULL);

				// Get the file name from the dialog box.
				if (SUCCEEDED(hr))
				{
					IShellItem* pItem;
					hr = pFileOpen->GetResult(&pItem);
					if (SUCCEEDED(hr))
					{
						PWSTR pszFilePath;
						hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

						// Display the file name to the user.
						if (SUCCEEDED(hr))
						{
							char charPath[255];
							WideCharToMultiByte(CP_ACP,
								0,
								pszFilePath,
								-1,
								charPath,
								sizeof(charPath),
								NULL,
								NULL);

							//create relative path from absPath gotten from fileDialouge so we can make gateware happy
							fs::path p(charPath);
							fs::path base("./");
							strcpy(charPath, fs::relative(p, base).string().c_str());


							GW::SYSTEM::GLog log; // handy for logging any messages/warning/errors
							// begin loading level
							log.Create("../LevelLoaderLog.txt");
							log.EnableConsoleLogging(true); // mirror output to the console
							log.Log("Loading New Level.");

							Level_Data newLevel;
							if (newLevel.LoadLevel(charPath, MODEL_PATH, log)) {
								levelData.UnloadLevel();
								levelData = newLevel;
								InitializeGraphics();
							}
						
							CoTaskMemFree(pszFilePath);
						}
						pItem->Release();
					}
				}
				pFileOpen->Release();
			}
			CoUninitialize();
		}
		return;
	}
	//should seperate out into different class
	void ReadInput() { 

		for (size_t i = 0; i < ARRAYSIZE(keyStates); i++)
		{
			inputLib.GetState(G_KEY_UNKNOWN + i, keyStates[i]);
		}
		int controllers;
		controllerLib.GetNumConnected(controllers);
		for (int c = 0; c < controllers; c++) { // yeah probably shouldnt be checking this every frame
			controllerLib.IsConnected(c, controllerConnected); 
			if (controllerConnected) {
				for (size_t i = 0; i < ARRAYSIZE(controllerStates); i++)
				{
					controllerLib.GetState(c, G_KEY_UNKNOWN + i, controllerStates[i]);
				}
				break;
			}

		} 

	}

	void HandleInput() {
		ReadInput();
		UpdateCamera();
		ChangeLevel();
	}
#pragma endregion stowaways

private:


	//Render helper functions
	void SetUpPipeline()
	{
		// TODO: Part 1h
		glUseProgram(shaderExecutable);
		glBindVertexArray(vertexArray);
	}
	void SetupUbo() 
	{		
		//pass camera info for movement
		ubo.camPos = camTransform.row4;
		ubo.viewMatrix = viewMatrix;
		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(UBO_DATA), &ubo);

		// TODO: Part 2e
		auto uboIndex = glGetUniformBlockIndex(shaderExecutable, "UboData");
		// TODO: Part 2f
		glBindBufferBase(GL_UNIFORM_BUFFER, uboBindingIndex, uboBufferObject);
		// TODO: Part 2g
		glUniformBlockBinding(shaderExecutable, uboIndex, uboBindingIndex);

		

	}
	void SetupSSBO() {


		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssboBufferObject);
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(SSBO_DATA), &ssbo);		// used to update buffer if need be
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

		glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssboBufferObject);

	}

public:
	~Renderer()
	{
		// free resources
		glDeleteVertexArrays(1, &vertexArray);
		glDeleteBuffers(1, &vertexBufferObject);

		glDeleteBuffers(1, &indexBufferObject);
		glDeleteShader(vertexShader);
		glDeleteShader(geometryShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(shaderExecutable);

		glDeleteBuffers(1, &uboBufferObject);
		glDeleteBuffers(1, &ssboBufferObject);
	}
};
