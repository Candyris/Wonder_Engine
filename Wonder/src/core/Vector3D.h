#pragma once
#include <glm/glm.hpp>

namespace Vector3D
{
    const glm::vec3 Right = glm::vec3(1.0f, 0.0f, 0.0f);
    const glm::vec3 Left = glm::vec3(-1.0f, 0.0f, 0.0f);
    const glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
    const glm::vec3 Down = glm::vec3(0.0f, -1.0f, 0.0f);
    const glm::vec3 Far = glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 Near = glm::vec3(0.0f, 0.0f, 1.0f);
}