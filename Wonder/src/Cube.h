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
};