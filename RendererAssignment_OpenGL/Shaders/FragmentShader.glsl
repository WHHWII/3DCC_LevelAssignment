#version 430 // GLSL 4.30
out vec4 Pixel;
// an ultra simple glsl fragment shader
// TODO: Part 3a
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

uniform uint uTransformIndex;
uniform uint uMaterialIndex;

layout (binding = 0, std430, row_major) buffer SSBO
{
	mat4 allTransforms[100];
	OBJ_ATTRIBUTES allMaterials[100];
};

in vec3 worldNorm;
in vec3 surfacePos;
flat in int instanceID; // unused atm

void main() 
{	
	OBJ_ATTRIBUTES curMat = allMaterials[uMaterialIndex];
	float lighRatio = clamp(dot(worldNorm,-(sunDirection.xyz)), 0, 1);
	vec4 newColor = sunColor * lighRatio * vec4(curMat.Kd,1);
	
	vec3 viewdir = normalize(camPos.xyz - surfacePos);
	vec3 halfvec = normalize(-(sunDirection.xyz) + viewdir);
	float intensity = max(clamp(pow(dot(worldNorm, halfvec),curMat.Ns), 0, 1), 0 );
	vec4 reflectedlight = sunColor * vec4(curMat.Ks,1) * intensity;
	newColor = clamp(newColor + sunAmbient, 0, 1) * vec4(curMat.Kd,1)  + reflectedlight;
	Pixel = newColor;
}