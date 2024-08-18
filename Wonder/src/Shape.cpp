#include "Shape.h"

void Shape::setTransform(const TransformComponent& transform)
{
	m_Transform = transform;
}

void Shape::setTexture(std::unique_ptr<Texture> texture)
{
	m_Texture = std::move(texture);
}

void Shape::setShader(std::unique_ptr<Shader> shader)
{
	m_Shader = std::move(shader);
}

TransformComponent Shape::getTransform() const
{
	return m_Transform;
}

Texture* Shape::getTexture() const
{
	return m_Texture.get();
}

Shader* Shape::getShader() const
{
	return m_Shader.get();
}
