#pragma once
#include "Shape.h"
#include "VAO.h"

class Cube : public Shape
{
public:
	Cube();
	Cube(TransformComponent& transform);
		
	void render() override;
private:
	VAO m_Vao;
	glm::mat4 m_Model;
	glm::mat4 m_View;
	glm::mat4 m_Projection;
};