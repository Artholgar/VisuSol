#pragma once

#include <glimac/common.hpp>
#include <iostream>

namespace glimac {

class Camera {
public:
    virtual glm::mat4 getViewMatrix() const
    {
        std::cout << "Base class default behaviour\n";
        return glm::mat4(1);
    }
};

} // namespace glimac