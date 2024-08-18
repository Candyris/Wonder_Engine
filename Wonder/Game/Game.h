#pragma once
#include "../src/Application.h"
#include "../src/coreEngine.h"
#include "../src/Cube.h"

class Game : public IApplication
{
public:
	void Init() override;
	void input() override;
	void update() override;
	void render() override;
private:
	TransformComponent Box;
	Cube cube;
};