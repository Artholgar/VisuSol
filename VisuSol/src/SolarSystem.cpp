#include "include/SolarSystem.hpp"

const void SolarSystem::drawAll() {
	_star.draw(getCam(), glm::mat4(1));
}

