#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "Texture.h"
#include "Transform.h"
#include <memory>
class Shape
{
public:
public:
	Shape() = default;
	Shape(std::unique_ptr<Shader> shader, TransformComponent transform, std::unique_ptr<Texture> texture)
		: m_Shader(std::move(shader)), m_Transform(transform), m_Texture(std::move(texture)) {}

	virtual void render() = 0;
public:
	void setTransform(const TransformComponent& transform);
	void setTexture(std::unique_ptr<Texture> texture);
	void setShader(std::unique_ptr<Shader> shader);

	TransformComponent getTransform() const;
	Texture* getTexture() const;
	Shader* getShader() const;
protected:
	std::unique_ptr<Shader> m_Shader;
	TransformComponent m_Transform;
	std::unique_ptr<Texture> m_Texture;
};