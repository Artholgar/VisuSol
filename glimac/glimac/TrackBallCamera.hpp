#pragma once

#include <glimac/common.hpp>
#include <iostream>
#include "Camera.hpp"

namespace glimac {

class TrackBallCamera : public Camera {
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;

public:

    TrackBallCamera() : m_fDistance(5), m_fAngleX(0), m_fAngleY(0) {}
    void moveFront(float delta);
    void rotateLeft(float degrees);
    void rotateUp(float degrees);

    void printValue()
    {

    }

    glm::mat4 getViewMatrix() const override;
};

}