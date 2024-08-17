#include "Camera.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "window.h"
glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(m_Position,m_Position + m_Front,m_Up);
}
//enum Movement {};
Camera::Camera()
{
	m_Position = glm::vec3(0.0f,0.0f,3.0f);
	m_Front = glm::vec3(0.0f,0.0f,-1.0f);
	m_Up = glm::vec3(0.0f,1.0f,0.0f);
	m_ViewMat = glm::mat4(1.0f);

	m_Speed = 2.5f;
}

void Camera::keyboardInput(GLFWwindow* window, float deltaTime)
{
	float velocity = deltaTime * m_Speed;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		m_Position += m_Front * velocity;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		m_Position -= m_Front * velocity;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		m_Position -= glm::normalize(glm::cross(m_Front, m_Up)) * velocity;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		m_Position += glm::normalize(glm::cross(m_Front, m_Up)) * velocity;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		m_Position += m_Up * velocity;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		m_Position -= m_Up * velocity;

	}
}

void Camera::mouseInput(float x,float y)
{
	if (m_firstMouse)
	{
		m_lastX = x;
		m_lastY = y;
		m_firstMouse = false;
	}

	float offsetX = (x - m_lastX) * m_Sensitivity;
	float offsetY = (m_lastY - y) * m_Sensitivity;

	m_lastX = x;
	m_lastY = y;

	m_Yaw += offsetX;
	m_Pitch += offsetY;
	if (m_Pitch > 89.0f)
	{
		m_Pitch = 89.0f;
	}
	else if (m_Pitch < -89.0f)
	{
		m_Pitch = -89.0f;
	}

	glm::vec3 direction(0.0f);
	direction.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	direction.y = sin(glm::radians(m_Pitch));
	direction.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = direction;
}

void Camera::ScrollInput(float y)
{
	m_Fov += y;
	if (m_Fov > 45.0f)
	{
		m_Fov = 45.0f;
	}
	else if (m_Fov < 0.0f)
	{
		m_Fov = 0.0f;
	}
}
