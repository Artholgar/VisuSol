#pragma once
#include <iostream>
#include "glimac/FreeflyCamera.hpp"

class Drawable {
public:
    virtual void draw(glimac::FreeflyCamera cam, glm::mat4 model) const { std::cout << "Base class default behaviour\n"; };

private:
};