#version 430 // GLSL 4.30
// an ultra simple glsl vertex shader
// TODO: Part 2b
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


// TODO: Part 4e
// TODO: Part 1f
layout(location = 0) in vec3 local_pos;
layout(location = 1) in vec3 local_uvw;
layout(location = 2) in vec3 local_nrm;
// TODO: Part 4a
out vec3 worldNorm;
out vec3 surfacePos;
flat out int instanceID;
void main()
{
	instanceID = gl_InstanceID;
	mat4 curWorld = allTransforms[uTransformIndex + instanceID];
	surfacePos = (vec4(local_pos, 1) * curWorld).xyz;
	surfacePos.x = -surfacePos.x; // correct transforms for conversion from LHDcoords to RHDcoords
	gl_Position = vec4(surfacePos, 1) * viewMatrix * projectionMatrix;
	// TODO: Part 4b
	worldNorm = normalize(vec3(vec4(local_nrm, 0) * curWorld));
	
}