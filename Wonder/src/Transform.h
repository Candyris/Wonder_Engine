#pragma once 
#include <glm/glm.hpp>

class Transform
{
public:
    
    Transform();
    void log();
    glm::mat4 getModelMatrix();

public:
    glm::vec3 position = glm::vec3(0.0f);
    float rotateAngle = 0.0f;
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
    glm::vec3 rotationDir = glm::vec3(0.0f);


};