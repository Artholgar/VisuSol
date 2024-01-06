#pragma once
#include "glimac/common.hpp"
#include "glimac/Camera.hpp"

#include "AppEngine.hpp"

void initVBO(GLuint* vbo, const GLsizei vertexCount, const glimac::ShapeVertex* dataPointer);

void initVAO(GLuint* vao_ptr, GLuint vbo);