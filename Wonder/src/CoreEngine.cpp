#include "CoreEngine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Time.h"
#include "window.h"
#include "Camera.h"
#include "Renderer.h"

#include <iostream>


// callback for input
static void framebuffer_size_callback(GLFWwindow* window,int width, int height);
static void scroll_callback(GLFWwindow* window,double offsetX, double offsetY);
static void mouse_callback(GLFWwindow* window, double x ,double y);

Engine::Engine()
{
	try
	{
		Init();
		callback();
	}
	catch (std::string error)
	{
		std::cout << "[Initialize Error] : " << error << " ! " << std::endl;
	}
}

void Engine::start()
{
	std::cout << "Started the Engine" << std::endl;
	std::cout << "OpenGL Version :"<<glGetString(GL_VERSION) << std::endl;
}

void Engine::stop()
{
	delete app;
	glfwTerminate();
	std::cout << "Ended the Engine" << std::endl;
}

void Engine::mainLoop()
{
	while (Window::Get()->isRunning())
	{
		input();
		Window::Get()->clearColor();
		Window::Clear();
		update();
		render();
		Window::Get()->swapBuffer();
		#if SHOW_FPS 
			std::cout << "[FPS] -> (" << 1.0f / Time::Get()->DeltaTime <<')' << std::endl;
		#endif
	}
}

void Engine::run()
{
	try 
	{
		start();
		mainLoop();
		stop();
	}
	catch (std::string error)
	{
		std::cout << "[Error] : " << error <<" ! "<< std::endl;
	}

}

void Engine::Init()
{
	Window::Init();
	Window::enableVSync();
	Renderer::Init();
	Game* game = new Game;
	app = game;
	app->Init();
}

void Engine::input()
{
	GLFWwindow* window = Window::Get()->getWindow();
	enableCamera();

	// When Editor Mode using the Camera Input
	if (CameraState)
	{
		Camera::GetInstance()->keyboardInput(window, static_cast<float>(Time::Get()->DeltaTime));
	}
	else //if (!CameraState) 
	{
		app->input();
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	// When Editor Mode Don't using the App input
}

void Engine::render()
{
	app->render();
}

void Engine::update()
{
	Time::Get()->updateTime();
	if (!CameraState)	app->update();
}

void Engine::callback()
{
	glfwSetFramebufferSizeCallback(Window::Get()->getWindow(), framebuffer_size_callback);
}

void Engine::UpdateDeltaTime()
{
	m_DeltaTime = static_cast<float>(glfwGetTime() - m_LastFrame);
	m_LastFrame = static_cast<float>(glfwGetTime());
}

	
// callback
void Engine::enableCamera()
{
	
	if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		CameraState = (CameraState ? false : true);
		if (CameraState)
		{
			glfwSetInputMode(Window::Get()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPosCallback(Window::Get()->getWindow(), mouse_callback);
			glfwSetScrollCallback(Window::Get()->getWindow(), scroll_callback);
		}
		else
		{
			glfwSetInputMode(Window::Get()->getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			glfwSetCursorPosCallback(Window::Get()->getWindow(), nullptr);
			glfwSetScrollCallback(Window::Get()->getWindow(), nullptr);

		}
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//glViewport(width/8,height/4, width/1.5, height/1.5);
	glViewport(0,0, width, height);
}

void scroll_callback(GLFWwindow* window, double offsetX, double offsetY)
{
	Camera::GetInstance()->ScrollInput(static_cast<float>(offsetY));
}

void mouse_callback(GLFWwindow* window, double x, double y)
{
	Camera::GetInstance()->mouseInput(static_cast<float>(x),static_cast<float>(y));
}
