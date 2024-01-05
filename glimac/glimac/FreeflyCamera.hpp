#pragma once

#include <glimac/common.hpp>
#include <iostream>
#include "Camera.hpp"

namespace glimac {

class FreeflyCamera : public Camera {
    glm::vec3 m_Position;
    float m_fPhi;   // Axe Z -> Y
    float m_fTheta; // Axe X -> Y

    glm::vec3 m_Front;
    glm::vec3 m_Left;
    glm::vec3 m_Up;

    void computeDirectionVectors();

public:
    FreeflyCamera();
    void moveLeft(float t);
    void moveFront(float t);
    void rotateLeft(float degrees);
    void rotateUp(float degrees);

    glm::mat4 getViewMatrix() const override;
};

}