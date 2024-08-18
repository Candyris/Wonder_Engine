#pragma once
#include "../src/Application.h"
#include "../src/coreEngine.h"

class Game : public IApplication
{
public:
	void Init() override;
	void input() override;
	void update() override;
	void render() override;
private:
	TransformComponent objectTransform;
	TransformComponent lightTransform;
	VAO objectVao;
	VAO lightVao;
	Shader* objectShader;
	Shader* lightShader;
	unsigned int VBO;
};