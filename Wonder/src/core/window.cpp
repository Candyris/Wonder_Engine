#include "window.h"
#include <string>
#include <iostream>
Window::Window()
{
	m_Window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,SCR_TITTLE, 0, 0);
	if (!m_Window)
	{
		throw std::string("Failed to Create Window");
	}
	glfwMakeContextCurrent(m_Window);
	m_Color = {0.f,0.f,0.f};
}

void Window::Init()
{
	if (!glfwInit())
	{
		throw std::string("Failed to Initialize Window");
	}
	//GLFWWindowHint
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	Window::Get();
}

void Window::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::enableVSync()
{
	glfwSwapInterval(1);
}

bool Window::isRunning()
{
	return !glfwWindowShouldClose(m_Window);
}

GLFWwindow* Window::getWindow() const
{
	return m_Window;
}

void Window::clearColor() const
{
	glClearColor(m_Color.r, m_Color.g,m_Color.b,1.0f);
}

void Window::setClearColor(const float& r, const float& g, const float& b)
{
	m_Color = { r,g,b };
}


void Window::swapBuffer()
{
	glfwSwapBuffers(m_Window);
	glfwPollEvents();
}

Window::~Window()
{
	glfwDestroyWindow(m_Window);
}
