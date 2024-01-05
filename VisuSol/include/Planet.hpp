#pragma once
#include "Drawable.hpp"
#include "Orbit.hpp"

#include <glad/glad.h>
#include "glimac/common.hpp"
#include <vector>

class Orbit;

class Planet : public Drawable {
public:
    void draw() const override;

private:
    glimac::ShapeVertex* _dataPointer;
    GLsizei              _vertexCount;
    glm::mat4            _model;
    std::vector<Orbit>   _orbites;
};
