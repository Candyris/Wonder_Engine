#pragma once
#pragma once
#include "Shape.h"
#include "core/VAO.h"

class Pyramid : public Shape
{
public:
	Pyramid();
	Pyramid(TransformComponent& transform);

	void render() override;
private:
	VAO m_Vao;
	glm::mat4 m_Model;
	glm::mat4 m_View;
	glm::mat4 m_Projection;
};