#pragma once
#include "../src/Application.h"
#include "../src/coreEngine.h"
#include "../src/Shape/Cube.h"
#include "../src/Shape/Pyramid.h"

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
	Pyramid cone;

};