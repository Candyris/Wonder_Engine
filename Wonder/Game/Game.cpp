#include "Game.h"

void Game::Init()
{
	// Window::Get()->setClearColor(1.0f, 0.44f, 0.7f);
	float vertices[] =
	{
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };
	
    objectVao.bind();
	objectShader = new Shader("asserts/Shader/object/vert.glsl","asserts/Shader/object/frag.glsl");
	objectShader->use();
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	objectVao.linkAttrib(0,3,GL_FLOAT,6 * sizeof(float),(const void*) 0);
	objectVao.linkAttrib(1,3,GL_FLOAT,6 * sizeof(float),(const void*) (3 * sizeof(float)));

    lightVao.bind();
    lightShader = new Shader("asserts/Shader/lighting/vert.glsl", "asserts/Shader/lighting/frag.glsl");
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    lightVao.linkAttrib(0, 3, GL_FLOAT, 6 * sizeof(float), (const void*)0);

    lightTransform.scale = glm::vec3(0.3f);
    lightTransform.position = glm::vec3(1.0f,1.0f,2.0f);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    lightTransform.rotationDir = Vector3D::Up;
}

void Game::input()
{
    if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Left * (float)Time::Get()->DeltaTime * 3.0f;
    }
    if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Right * (float)Time::Get()->DeltaTime * 3.0f;
    }if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_UP) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Up * (float)Time::Get()->DeltaTime * 3.0f;
    }
    if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Down * (float)Time::Get()->DeltaTime * 3.0f;
    }
    if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Near * (float)Time::Get()->DeltaTime * 3.0f;
    }
    if (glfwGetKey(Window::Get()->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
    {
        lightTransform.position += Vector3D::Far * (float)Time::Get()->DeltaTime * 3.0f;
    }
}

void Game::update()
{
	// lightTransform.rotateAngle = float(glfwGetTime() * 30);
	objectTransform.rotateAngle = -1.0f * float(glfwGetTime() * 30);
}

void Game::render()
{
    objectVao.bind();
    objectShader->use();
	glm::mat4 projection = glm::perspective(glm::radians(Camera::GetInstance()->getFov()),float(SCR_WIDTH/SCR_HEIGHT),0.1f,100.0f);
	objectShader->setUniformMat4("u_Model", objectTransform.getModelMatrix());
	objectShader->setUniformMat4("u_View", Camera::GetInstance()->getViewMatrix());
	objectShader->setUniformMat4("u_Projection", projection);
    objectShader->setUniformVec3("ObjectColor", glm::vec3(1.0f, 0.5f, 0.31f));
    objectShader->setUniformVec3("LightColor", glm::vec3(1.0f));
    objectShader->setUniformVec3("LightPos", lightTransform.position);
    objectShader->setUniformVec3("viewPos", Camera::GetInstance()->getPos());

	glDrawArrays(GL_TRIANGLES, 0,36);
    
    lightVao.bind();
    lightShader->use();
	glm::mat4 PVM = projection * Camera::GetInstance()->getViewMatrix() * lightTransform.getModelMatrix();
	lightShader->setUniformMat4("u_PVM", PVM);
	glDrawArrays(GL_TRIANGLES, 0,36);
}
