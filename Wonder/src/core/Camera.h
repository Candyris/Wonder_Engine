#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"


class Camera
{
public:
	void keyboardInput(GLFWwindow* window,float deltaTime);
	void mouseInput(float x ,float y);
	void ScrollInput(float y);
	static Camera* GetInstance()
	{
		static Camera* s_Camera = nullptr;
		if (!s_Camera)
		{
			s_Camera = new Camera;
		}
		return s_Camera;
	}
	glm::mat4 getViewMatrix() const;
	
	// setter / getter
	float getFov() const { return m_Fov;  }
	
	glm::vec3 getPos()const { return m_Position; };

private:
	Camera();

	glm::mat4 m_ViewMat;
	glm::vec3 m_Front;
	glm::vec3 m_Up;
	glm::vec3 m_Position;

	float m_Speed;
	// Mouse
	float m_Pitch = 0.0f;
	float m_Yaw = -90.0f;
	float m_Sensitivity = 0.1f;
	float m_lastX = SCR_WIDTH/2.0f;
	float m_lastY = SCR_HEIGHT/2.0f;
	float m_firstMouse = true;
	float m_Fov = 45.0f;
};