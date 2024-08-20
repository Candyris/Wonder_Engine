#pragma once
#include "glad/glad.h"
#include "VAO.h"
#include "Shaders/shader.h"
#include "Components/Transform.h"
class Renderer
{
public:
	static Renderer* Get();
	static void Init();
	static void renderVAO(VAO& vao,Shader& shader,TransformComponent& transform, const GLuint& count);
private:
	Renderer();
};