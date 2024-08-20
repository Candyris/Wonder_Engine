#pragma once
#include "window.h"
#include "Time.h"
#include "Components/Transform.h"
#include "Textures/Texture.h"
#include "Shaders/Shader.h"
#include "VAO.h"
#include "Vector3D.h"
#include "Camera.h"
#include "Renderer.h"

class IApplication
{
public:
	virtual void Init() {}
	virtual void input() {}
	virtual void update() {}
	virtual void render() {}
};