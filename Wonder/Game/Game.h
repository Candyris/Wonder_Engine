#pragma once
#include "core/Application.h"
#include "core/Engine.h"
#include "Shape/Cube.h"
#include "Shape/Pyramid.h"

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