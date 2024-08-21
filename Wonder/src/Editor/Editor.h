#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <iostream>
#include <string>

class Editor
{
public:
    Editor();
    ~Editor();

    void init();
    void update();
    void render();
    void input();

    bool IsActive() const { return m_IsActive; }
    void ToggleActive();

private:
    bool m_IsActive; // Indicates whether the editor mode is active
};
