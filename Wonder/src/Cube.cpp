#include "Cube.h"

Cube::Cube()
{


	m_Vao.bind();
}

Cube::Cube(TransformComponent& transform)
	: Shape(nullptr, transform, nullptr)
{
}

void Cube::render()
{
}
