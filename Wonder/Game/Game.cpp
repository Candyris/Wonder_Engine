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
	static bool change = false;
	std::random_device rd;
	std::mt19937 rd_machine(rd());
	std::uniform_real_distribution<float> urd(0.0f, 1.0f);
	 
	
		if (static_cast<int>(glfwGetTime()) % 2 == 0)
		{
			if (!change)
			{
				change = true;
				cube.setColor(urd(rd_machine), urd(rd_machine), urd(rd_machine));
			}
		}
		else
		{
			change = false;
		}
	
		TransformComponent transform = cube.getTransform();
		transform.scale = glm::vec3(1.0f, sin(glfwGetTime()), 1.0f);
		cube.setTransform(transform);
	
}

void Game::render()
{
	cube.render();
	cone.render();
}
