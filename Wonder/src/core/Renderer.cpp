#include "Renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <string>
#include "Camera.h"
#include "window.h"

Renderer* Renderer::Get()
{
	static std::unique_ptr<Renderer> renderer(new Renderer);
	return renderer.get();
}

void Renderer::Init()
{

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw std::string("Failed to Initialize OpenGL (Glad)");
	}
	glEnable(GL_DEPTH_TEST); // Enable 3d Drawing 
}

void Renderer::renderVAO(VAO& vao, Shader& shader, TransformComponent& transform,const GLuint& count)
{
	vao.bind();
	glm::mat4 projection = glm::perspective(glm::radians(Camera::GetInstance()->getFov()), float(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
	glm::mat4 PVM = projection * Camera::GetInstance()->getViewMatrix() * TransformSystem::GetModelMatrix(transform);
	shader.setUniformMat4("u_PVM", PVM);
	glDrawArrays(GL_TRIANGLES, 0, count);
}

Renderer::Renderer()
{

}