// TODO: Part 1b
//#include "load_data_oriented.h"
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
	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GOpenGLSurface ogl;
	Level_Data &levelData;

	// what we need at a minimum to draw a triangle
	GLuint vertexArray = 0;
	GLuint vertexBufferObject = 0;
	// TODO: Part 1g
	GLuint indexBufferObject = 0;
	GLuint vertexShader = 0;
	GLuint fragmentShader = 0;
	GLuint shaderExecutable = 0;

	// TODO: Part 2c
	GLuint uboBufferObject = 0;
	GLuint uboBindingIndex = 0;
	// TODO: Part 2a
	GW::MATH::GVector vectorLib;
	GW::MATH::GMatrix matrixLib;
	GW::MATH::GMATRIXF worldMatrix =		GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF viewMatrix =			GW::MATH::GIdentityMatrixF;
	GW::MATH::GMATRIXF projectionMatrix =	GW::MATH::GIdentityMatrixF;
	int worldMatrixUniLocation = 0;
	int viewMatrixUniLocation = 0;
	int projectionMatrixUniLocation = 0;
	/// <summary>
	/// degreeToRadian
	/// </summary>
	const float dToR = 0.0174533f;
	const float fov = 65.0f;// need to make this not stored in two seperate places. probably need camera class.

	//light
	GW::MATH::GVECTORF lightDirection = GW::MATH::GIdentityVectorF;
	GW::MATH::GVECTORF lightColor = GW::MATH::GIdentityVectorF;
	GW::MATH::GVECTORF ambientColor = GW::MATH::GIdentityVectorF;
	//frame time
	float deltaTime = 0.0f;
	std::chrono::steady_clock::time_point lastFrameTime;

	// TODO: Part 2b
	struct UBO_DATA
	{
		GW::MATH::GVECTORF sunDirection, sunColor; 
		GW::MATH::GMATRIXF viewMatrix, projectionMatrix;
		GW::MATH::GMATRIXF world;
		H2B::ATTRIBUTES material;
		GW::MATH::GVECTORF sunAmbient, camPos;
		
		
	};

	UBO_DATA ubo;

	// TODO: Part 4e

public:


	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GOpenGLSurface _ogl, Level_Data &_levelData  ) : levelData(_levelData)

	{
		win = _win;
		ogl = _ogl;
		//levelData = _levelData;
		// TODO: part 2a
		matrixLib.Create();
		vectorLib.Create();

		InitializeLight();
		InitializeWorldMatrix(worldMatrix, 0, 0, 0, 0, 0, 0);
		InitializeViewMatrix();
		InitializeProjectionMatrix();
		// TODO: Part 2b
		InitializeUbo();
		// TODO: Part 4e
		InitializeGraphics();
	}

private:
	//constructor helper functions 
	void InitializeGraphics()
	{
#ifndef NDEBUG
		BindDebugCallback(); // In debug mode we link openGL errors to the console
#endif
		IntializeBuffers();
		// TODO: Part 1g
		// TODO: Part 2c
		CompileVertexShader();
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
		// TODO: Part 1c
		CreateVertexBuffer(&levelData.levelVertices[0], levelData.levelVertices.size() * sizeof(H2B::VERTEX));
		CreateIndexBuffer(&levelData.levelIndices[0], levelData.levelIndices.size() * sizeof(unsigned));
		CreateUboBuffer(&ubo, sizeof(ubo));
	}

	void InitializeUbo() {
		ubo.material = levelData.levelMaterials[0].attrib;
		ubo.world = worldMatrix;
		ubo.projectionMatrix = projectionMatrix;
		ubo.viewMatrix = viewMatrix;
		ubo.sunDirection = lightDirection;
		ubo.sunColor = lightColor;
		ubo.sunAmbient = ambientColor;
		ubo.camPos = GW::MATH::GVECTORF{ 0.75f, 0.25f, 1.5f }; // will need to change for moving camera
	}

	void PrintMatrix(GW::MATH::GMATRIXF mat) {
		printf("%f, %f, %f, %f\n", mat.row1.x, mat.row1.y, mat.row1.z, mat.row1.w);
		printf("%f, %f, %f, %f\n", mat.row2.x, mat.row2.y, mat.row2.z, mat.row2.w);
		printf("%f, %f, %f, %f\n", mat.row3.x, mat.row3.y, mat.row3.z, mat.row3.w);
		printf("%f, %f, %f, %f\n", mat.row4.x, mat.row4.y, mat.row4.z, mat.row4.w);
	}

	void InitializeWorldMatrix(GW::MATH::GMATRIXF& matrix, float xt, float yt, float zt, float xr, float yr, float zr) {
		GW::MATH::GVECTORF moveVector = GW::MATH::GIdentityVectorF;
		moveVector.x = xt;
		moveVector.y = yt;
		moveVector.z = zt;
		if (xr != 0) matrixLib.RotateXGlobalF(matrix, xr * dToR, matrix);
		if (yr != 0) matrixLib.RotateYGlobalF(matrix, yr * dToR, matrix);
		if (zr != 0) matrixLib.RotateZGlobalF(matrix, zr * dToR, matrix);
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
		matrixLib.LookAtRHF(GW::MATH::GVECTORF{ 0.75f, 0.25f, 1.5f },
			GW::MATH::GVECTORF{ 0.06f, -0.08f, -0.1f },
			GW::MATH::GVECTORF{ 0.0f, 1.0f, 0.0f },
			viewMatrix);

		//need to fix translation

		//matrixLib.InverseF(viewMatrix, viewMatrix);
	}

	void InitializeProjectionMatrix() {
		float aspectRatio;
		ogl.GetAspectRatio(aspectRatio);
		matrixLib.ProjectionOpenGLRHF(fov * dToR, aspectRatio, 0.1, 100, projectionMatrix);
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

public:
	void Render()
	{
		SetUpPipeline();
		SetupUbo();

		//glDrawElements(GL_TRIANGLES, levelData.levelModels[1].indexCount, GL_UNSIGNED_INT, 0);
		//TODO: need to loop through instances, and then draw the mesh(es) at each transform containted within the instance.
		//later instanced rendering will do this.
		
		for (int i = 0; i < levelData.levelInstances.size(); i++) // loop through all instances (unique models)
		{

			auto instance = levelData.levelInstances[i]; // each unique model is stored in an instance, which is used to draw the same model in different locs/orientations
			auto model = levelData.levelModels[instance.modelIndex]; // the model of the instance
			
			H2B::MESH curMesh; //current submesh of the model
			for (int t = 0; t < instance.transformCount; t++) {  // each unique location/orientation where this model is drawn
				for (int subMeshIdx = 0; subMeshIdx < model.meshCount; subMeshIdx++) { // each sub mesh of the model
					curMesh = levelData.levelMeshes[model.meshStart + subMeshIdx]; 

					
					ubo.material = levelData.levelMaterials[model.materialStart + curMesh.materialIndex].attrib; // this will only grab first material, need to fix later.
					ubo.world = levelData.levelTransforms[instance.transformStart + t];
					glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(UBO_DATA), &ubo);

					//printf("model %s \t\t: indexStart %d mesh: %d indexOffset: %d \n", model.filename, model.indexStart, subMeshIdx,curMesh.drawInfo.indexOffset);

				}
			}
			auto indicies = reinterpret_cast <GLvoid*> (model.indexStart * sizeof(unsigned int));
			glDrawElements(GL_TRIANGLES, model.indexCount, GL_UNSIGNED_INT, indicies);
		}
	
		
		//glDrawElementsInstancedBaseVertex(GL_TRIANGLES, levelData.levelInstances.size(), GL_UNSIGNED_INT, (GLvoid*)0, levelData.levelIndices.size(), 0);

		glBindVertexArray(0); // some video cards(cough Intel) need this set back to zero or they won't display
	}
	void TickFrame() {
		auto curFrameTime = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(curFrameTime - lastFrameTime).count() / 1000000.0f;
		lastFrameTime = curFrameTime;
	}
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
		// TODO: Part 2e
		auto uboIndex = glGetUniformBlockIndex(shaderExecutable, "UboData");
		// TODO: Part 2f
		glBindBufferBase(GL_UNIFORM_BUFFER, uboBindingIndex, uboBufferObject);
		// TODO: Part 2g
		glUniformBlockBinding(shaderExecutable, uboIndex, uboBindingIndex);
	}

public:
	~Renderer()
	{
		// free resources
		glDeleteVertexArrays(1, &vertexArray);
		glDeleteBuffers(1, &vertexBufferObject);
		// TODO: Part 1g
		glDeleteBuffers(1, &indexBufferObject);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(shaderExecutable);
		// TODO: Part 2c
		glDeleteBuffers(1, &uboBufferObject);
	}
};
