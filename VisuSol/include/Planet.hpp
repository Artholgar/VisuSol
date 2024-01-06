#pragma once
#include "Drawable.hpp"
#include "Orbit.hpp"

#include <glad/glad.h>
#include "glimac/common.hpp"
#include "glimac/Sphere.hpp"
#include <vector>

class Orbit;

class Planet : public Drawable {
public:
    Planet(const glimac::Sphere &sphere) {
        _dataPointer = sphere.getDataPointer();
        _vertexCount = sphere.getVertexCount();
        _model = glm::mat4(1);
        _orbites = std::vector<Orbit>();
    }

    void draw() const override;

private:
    const glimac::ShapeVertex* _dataPointer;
    GLsizei              _vertexCount;
    glm::mat4            _model;
    std::vector<Orbit>   _orbites;
};
