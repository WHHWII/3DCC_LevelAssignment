#version 330 // GLSL 3.30
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
	vec4 sunDirection, sunColor;
	mat4 viewMatrix, projectionMatrix;
	mat4 worldMatrix;
	OBJ_ATTRIBUTES material;
	vec4 sunAmbient, camPos;
};



// TODO: Part 4e
// TODO: Part 1f
layout(location = 0) in vec3 local_pos;
layout(location = 1) in vec3 local_uvw;
layout(location = 2) in vec3 local_nrm;
// TODO: Part 4a
out vec3 worldNorm;
out vec3 surfacePos;
void main()
{
	// TODO: Part 1f
	// TODO: Part 1f
	// TODO: Part 1h
	// TODO: Part 2h
	gl_Position = vec4(local_pos, 1) * worldMatrix * viewMatrix * projectionMatrix;
	// TODO: Part 4b
	worldNorm = vec3(vec4(local_nrm, 1) * worldMatrix);
	surfacePos = local_pos;
}