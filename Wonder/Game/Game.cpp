#include "Game.h"
#include <iostream>
#include <random>
void Game::Init()
{
	cube.setTransform(Box);
}

void Game::input()
{
}

void Game::update()
{

	std::random_device rd;
	std::mt19937 rd_machine(rd());
	std::uniform_real_distribution<float> urd(0.0f, 1.0f);

	cube.setColor(urd(rd_machine), urd(rd_machine), urd(rd_machine));

	TransformComponent transform = cube.getTransform();
	transform.scale = glm::vec3(1.0f, sin(glfwGetTime()), 1.0f);
	cube.setTransform(transform);
}

void Game::render()
{
	cube.render();
}
