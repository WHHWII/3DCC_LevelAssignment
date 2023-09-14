#version 330 // GLSL 3.30
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
	vec4 sunDirection, sunColor;
	mat4 viewMatrix, projectionMatrix;
	mat4 worldMatrix;
	OBJ_ATTRIBUTES material;
	vec4 sunAmbient, camPos;
};
// TODO: Part 4e
// TODO: Part 4b
in vec3 worldNorm;
in vec3 surfacePos;
void main() 
{	
	//Pixel = vec4(170/255.0f, 100/255.0f, 44/255.0f, 1); // TODO: Part 1a (optional)
	// TODO: Part 3a

	// TODO: Part 4c
	float lighRatio = clamp(dot(worldNorm, vec3(sunDirection)), 0, 1);
	vec4 newColor = sunColor * lighRatio * vec4(material.Kd,1);
	
	vec4 viewdir = normalize(camPos - vec4(surfacePos,1));
	vec4 halfvec = normalize(-sunDirection + viewdir);
	float intensity = max(pow(clamp(dot(vec4(worldNorm, 1), halfvec), 1, 0), material.Ns), 0 );
	vec4 reflectedlight = sunColor * vec4(material.Ks,1) * intensity;
	newColor = clamp(newColor + sunAmbient + reflectedlight, 0, 1);
	Pixel = newColor;
	// TODO: Part 4e
	// TODO: Part 4f (half-vector or reflect method)
}