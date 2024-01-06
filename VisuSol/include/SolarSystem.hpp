#pragma once
#include "Planet.hpp"
#include "AppEngine.hpp"

#include "glimac/common.hpp"
#include "glimac/Sphere.hpp"
#include <vector>

class SolarSystem {
public:
    SolarSystem(glimac::Sphere sphere) 
    : _star(sphere, 0, glm::vec3(1), glm::vec3(0), glm::vec3(1), glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\earthmap1k.jpg"))
    {
    }

    const void drawAll();

private:
    Planet _star;
};
