#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <iostream>
#include <string>
// Function to convert Postion vector to string
static std::string strPosition(const glm::vec3& pos)
{
    return "x: (" + std::to_string(pos.x) + "), y: (" + std::to_string(pos.y) + "), z: (" + std::to_string(pos.z) + ")";
}
// Function to convert scale vector to string
static std::string strScale(const glm::vec3& scale)
{
    return "Scale - x: (" + std::to_string(scale.x) + "), y: (" + std::to_string(scale.y) + "), z: (" + std::to_string(scale.z) + ")";
}

// Function to convert rotation angle and direction vector to string
static std::string strRotation(float& rotation, const glm::vec3& dir)
{
    return "Rotation - angle: (" + std::to_string(rotation) + "), direction - x: (" + std::to_string(dir.x) + "), y: (" + std::to_string(dir.y) + "), z: (" + std::to_string(dir.z) + ")";
}

void TransformSystem::Log(TransformComponent& transform)
{
    std::cout << "Position: " << strPosition(transform.position) << std::endl;
    std::cout << "Scale: " << strScale(transform.scale) << std::endl;
    std::cout << "Rotate: " << strRotation(transform.rotateAngle, transform.rotationDir) << std::endl;
}

glm::mat4 TransformSystem::GetModelMatrix(TransformComponent& transform)
{
    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, transform.position);
    model = glm::rotate(model, glm::radians(transform.rotateAngle), glm::normalize(transform.rotationDir));
    model = glm::scale(model, transform.scale);

    return model;
}
