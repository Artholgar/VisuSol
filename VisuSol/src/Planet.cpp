#include "include/Planet.hpp"

void Planet::draw() const {
    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
}