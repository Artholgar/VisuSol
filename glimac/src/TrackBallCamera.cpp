#include "glimac/TrackBallCamera.hpp"

void glimac::TrackBallCamera::moveFront(float delta)
{
    m_fDistance += delta;
}

void glimac::TrackBallCamera::rotateLeft(float degrees)
{
    m_fAngleX += degrees;
}

void glimac::TrackBallCamera::rotateUp(float degrees)
{
    m_fAngleY += degrees;
}

glm::mat4 glimac::TrackBallCamera::getViewMatrix() const
{
    float angleX = glm::radians(m_fAngleX);
    float angleY = glm::radians(m_fAngleY);

    glm::mat4 view(1);
    view = glm::translate(view, glm::vec3(0, 0, -m_fDistance));
    view = glm::rotate(view, angleY, glm::vec3(1, 0, 0));
    view = glm::rotate(view, angleX, glm::vec3(0, 1, 0));
    view = glm::translate(view, glm::vec3(0, 0, 0));

    return view;
}

