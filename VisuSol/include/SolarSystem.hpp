#pragma once
#include "Planet.hpp"

#include "glimac/common.hpp"
#include <vector>

class SolarSystem {
public:
    SolarSystem() 
    {}

    Planet getStar() { return _star; }

private:
    Planet _star;
};
