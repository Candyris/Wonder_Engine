#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Time
{
public:
    static Time* Get()
    {
        static Time* time = new Time;
        return time;
    }
    void updateTime()
    {
        DeltaTime = static_cast<float>(glfwGetTime() - m_LastFrame);
        m_LastFrame = static_cast<float>(glfwGetTime());
    }
    double DeltaTime = 0.0f;

private:
    Time() {}
    double m_LastFrame = 0.0f;
};