#pragma once
#include <iostream>
#include "glimac/Camera.hpp"

class Drawable {
public:
    virtual void draw(glimac::Camera cam, glm::mat4 model) const { std::cout << "Base class default behaviour\n"; };

private:
};