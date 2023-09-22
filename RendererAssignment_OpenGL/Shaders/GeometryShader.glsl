#version 430 // GLSL 4.30


struct OBJ_ATTRIBUTES
{
	vec3		Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	vec3		Ks; // specular reflectivity
	float       Ns; // specular exponent
	vec3		Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	vec3		Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	vec3	    Ke; // emissive reflectivity
	uint		illum; // illumination model

};

layout(row_major) uniform UboData
{
	mat4 viewMatrix, projectionMatrix;
	vec4 sunDirection, sunColor;
	vec4 sunAmbient, camPos;
};


layout (binding = 0, std430, row_major) buffer SSBO
{
	mat4 allTransforms[100];
	OBJ_ATTRIBUTES allMaterials[100];
};



uniform uint uTransformIndex;
uniform uint uMaterialIndex;



out vec3 worldNorm;
out vec3 surfacePos;
flat out int instanceID;



in DATA{
	vec3 worldNorm;
	vec3 surfacePos;
	int instanceID;
} data_in[];

layout (triangles) in;

layout (triangle_strip, max_vertices = 3) out;



void main()
{
	vec3 vector0 = vec3(gl_in[0].gl_Position - gl_in[1].gl_Position);
	vec3 vector1 = vec3(gl_in[2].gl_Position - gl_in[1].gl_Position);
	vec4 surfaceNorm = vec4(normalize(cross(vector0,vector1)),0.0f);


	int i;
	for (i = 0; i < gl_in.length(); i++)
    {
        gl_Position = (gl_in[i].gl_Position + surfaceNorm) * projectionMatrix;
		worldNorm = data_in[0].worldNorm;
		surfacePos = data_in[i].surfacePos;
		instanceID = data_in[i].instanceID;
        EmitVertex();
    }
	EndPrimitive();
}