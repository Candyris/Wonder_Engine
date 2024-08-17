#version 330 core
out vec4 Fragcolor;
uniform vec3 Color;
uniform vec3 ObjectColor;
uniform vec3 LightColor;
uniform vec3 LightPos;
uniform vec3 viewPos;
in vec3 Normal;
in vec3 FragPos;

void main()
{
	// Ambient Color
	float ambientStength = 0.1f;
	vec3 ambient = ambientStength * LightColor;

	// diffuse 
	vec3 norm = normalize(Normal);
	vec3 LightDir = normalize(LightPos - FragPos);
	float diff = max(dot(norm,LightDir),0.0f);
	vec3 diffuse = diff * LightColor;

	//specular
	float specularStrength = 0.5f;

	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-LightDir,norm);

	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	vec3 specular = specularStrength * spec * LightColor; 

	vec3 result = (ambient + diffuse + specular) * ObjectColor;
	Fragcolor = vec4(result,1.0f);
}