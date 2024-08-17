#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
inline const char* SCR_TITTLE = "WONDER ENGINE";
class Window
{
public:
	static void Init();
	static void Clear();
	static void enableVSync();
	bool isRunning();
	GLFWwindow* getWindow() const;
	void clearColor()const;
	void setClearColor(const float& r = 1.0f, const float& g = 1.0f, const float& b = 1.0f);
	void swapBuffer();
	~Window();
	static Window* Get()
	{
		static std::unique_ptr<Window> s_Window(new Window);
		
		return s_Window.get();
	}
private:
	Window();
	float m_Red;
	float m_Green;
	float m_Blue;
	GLFWwindow* m_Window;
};