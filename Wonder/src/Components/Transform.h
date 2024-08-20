#pragma once 
#include <glm/glm.hpp>

struct TransformComponent
{
    glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 rotationDir = glm::vec3(0.0f,1.0f,0.0f);
    float rotateAngle = 0.0f;
};


class TransformSystem
{
public:
    static void Log(TransformComponent& transform);
    static glm::mat4 GetModelMatrix(TransformComponent& transform);
};