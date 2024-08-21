#include "Editor.h"
#include "core/window.h"
Editor::Editor() : m_IsActive(false)
{
}

Editor::~Editor()
{
    // Destructor implementation
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Editor::init()
{
    const char* glsl_version = "#version 330";

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
         // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    ImGui_ImplGlfw_InitForOpenGL(Window::Get()->getWindow(), true);

    ImGui_ImplOpenGL3_Init(glsl_version);
    // Initialize editor components, load resources, etc.

    

    std::cout << "Editor Initialized" << std::endl;
}

void Editor::update()
{
    if (!m_IsActive)
        return;

    // Update editor logic, handle scene editing, etc.
    std::cout << "Editor Update" << std::endl;
}

void Editor::render()
{
    if (!m_IsActive)
        return;

    bool show_demo_window = true;
    bool show_another_window = false;

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;


    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
    ImGui::Checkbox("Another Window", &show_another_window);

    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
    ImGui::End();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(Window::Get()->getWindow(), &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    // Render editor UI, gizmos, etc.
    std::cout << "Editor Render" << std::endl;
}

void Editor::input()
{
    if (!m_IsActive)
        return;

    // Handle editor-specific input, such as selecting objects, moving UI, etc.
    std::cout << "Editor Input" << std::endl;
}

void Editor::ToggleActive()
{
    m_IsActive = !m_IsActive;
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    std::cout << "Editor " << (m_IsActive ? "Activated" : "Deactivated") << std::endl;
}
