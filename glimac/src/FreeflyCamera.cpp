#include "glimac/FreeflyCamera.hpp"

glimac::FreeflyCamera::FreeflyCamera() : m_Position(0), m_fPhi(glm::pi<float>()), m_fTheta(0)
{
	computeDirectionVectors();
}

void glimac::FreeflyCamera::computeDirectionVectors()
{
	m_Front.x = cos(m_fTheta) * sin(m_fPhi);
	m_Front.y = sin(m_fTheta);
	m_Front.z = cos(m_fTheta) * cos(m_fPhi);

	m_Front = glm::normalize(m_Front);

	glm::vec3 worldUp(0, 1, 0);
	//m_Left = glm::vec3(glm::sin(m_fPhi + glm::pi<float>() / 2), 0, glm::cos(m_fPhi + glm::pi<float>() / 2));

	m_Left = glm::normalize(glm::cross(worldUp, m_Front));

	m_Up = glm::cross(m_Front, m_Left);
}

void glimac::FreeflyCamera::moveLeft(float t)
{
	m_Position += t * m_Left;
}

void glimac::FreeflyCamera::moveFront(float t)
{
	m_Position -= t * m_Front;
}

void glimac::FreeflyCamera::rotateLeft(float degrees)
{
	m_fPhi += glm::radians(degrees);
	computeDirectionVectors();
}

void glimac::FreeflyCamera::rotateUp(float degrees)
{
	m_fTheta += glm::radians(degrees);
	computeDirectionVectors();
}

glm::mat4 glimac::FreeflyCamera::getViewMatrix() const
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}
