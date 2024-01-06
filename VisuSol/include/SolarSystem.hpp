#pragma once
#include "Planet.hpp"

#include "glimac/common.hpp"
#include "glimac/Sphere.hpp"
#include <vector>

class SolarSystem {
public:
    SolarSystem(const glimac::Sphere &sphere) : _star(sphere) {
        //_star = Planet(sphere);
    }

    Planet getStar() { return _star; }

private:
    Planet _star;
};
