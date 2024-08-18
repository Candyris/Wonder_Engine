#vertex shader
#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 u_PVM;
void main()
{
	gl_Position = u_PVM *vec4( aPos,1.0f);
}

#fragment shader
#version 330 core
out vec4 FragColor;
uniform vec3 u_Color;
void main()
{
	FragColor = vec4(u_Color,1.0f);
}