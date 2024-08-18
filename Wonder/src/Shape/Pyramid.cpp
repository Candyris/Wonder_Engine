#include "Pyramid.h"



#include "Cube.h"
#include "../Camera.h"
#include "../window.h"
#include <iostream>

Pyramid::Pyramid(TransformComponent& transform)
	: Shape(nullptr, transform, nullptr)
{
	float vertices[] = {
	-0.5f, 0.0f, -0.5f,  // Bottom-left
	 0.5f, 0.0f, -0.5f,  // Bottom-right
	 0.5f, 0.0f,  0.5f,  // Top-right
	-0.5f, 0.0f,  0.5f,  // Top-left
	 0.0f, 1.0f,  0.0f   // Apex
	};
	unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
	};
	m_Vao.bind();
	m_Shader = std::make_unique<Shader>("asserts/DefaultShader/Shape3D/NormalCube.glsl");
	unsigned int VBO;
	glGenBuffers(GL_ARRAY_BUFFER, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

	m_Vao.linkAttrib(0, 3, GL_FLOAT, 6 * sizeof(float), (const void*)0);
	m_Vao.linkAttrib(1, 3, GL_FLOAT, 6 * sizeof(float), (const void*)12);
	// matrix 

	m_Model = TransformSystem::GetModelMatrix(m_Transform);
	m_View = Camera::GetInstance()->getViewMatrix();
	m_Projection = glm::perspective(glm::radians(Camera::GetInstance()->getFov()), static_cast<float>(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
}
Pyramid::Pyramid()
{
	float vertices[] = {
	-0.5f, 0.0f, -0.5f,  // Bottom-left
	 0.5f, 0.0f, -0.5f,  // Bottom-right
	 0.5f, 0.0f,  0.5f,  // Top-right
	-0.5f, 0.0f,  0.5f,  // Top-left
	 0.0f, 1.0f,  0.0f   // Apex
	};
	unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
	};
	m_Vao.bind();
	m_Shader = std::make_unique<Shader>("asserts/DefaultShader/Shape3D/NormalCube.glsl");
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

	m_Vao.linkAttrib(0, 3, GL_FLOAT, 3 * sizeof(float), (const void*)0);
	// matrix 

	m_Model = TransformSystem::GetModelMatrix(m_Transform);
	m_View = Camera::GetInstance()->getViewMatrix();
	m_Projection = glm::perspective(glm::radians(Camera::GetInstance()->getFov()), static_cast<float>(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
}

void Pyramid::render()
{
	m_Shader->use();
	m_Vao.bind();
	m_Model = TransformSystem::GetModelMatrix(m_Transform);
	m_View = Camera::GetInstance()->getViewMatrix();
	m_Projection = glm::perspective(glm::radians(Camera::GetInstance()->getFov()), static_cast<float>(SCR_WIDTH / SCR_HEIGHT), 0.1f, 100.0f);
	m_Shader->setUniformVec3("u_Color", m_Color.r, m_Color.g, m_Color.b);
	m_Shader->setUniformMat4("u_PVM", m_Projection * m_View * m_Model);
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
}
