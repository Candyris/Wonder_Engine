#pragma once
//#include "Window.h"
#define SHOW_FPS 0

#include "../Game/Game.h"
#include "Application.h"
#include <glm/glm.hpp>
#include "ECS/ECS.h"
#include <Editor/Editor.h>
class Engine
{
public:
	// public functions
	Engine();
	void run();
private:
// private
	void start();
	void stop();
	void mainLoop();

	void Init();
	void input();
	void render();
	void update();


	void callback();

private:
	// Editor 
	Editor m_Editor;

	void enableCamera();
	void UpdateDeltaTime();

	ECS ecs;
	bool CameraState = false;
	float m_DeltaTime;
	float m_LastFrame;
	IApplication* app ;
	// Application

};