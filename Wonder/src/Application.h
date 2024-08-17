#pragma once
#include "window.h"
#include "Time.h"
#include "Transform.h"
#include "Texture.h"
#include "shader.h"
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