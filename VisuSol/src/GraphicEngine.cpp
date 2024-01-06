#include "include/GraphicEngine.hpp"

void initVBO(GLuint* vbo_ptr, const GLsizei vertexCount, const glimac::ShapeVertex* dataPointer)
{
    glCreateBuffers(1, vbo_ptr);

    glNamedBufferData(*vbo_ptr, vertexCount * sizeof(glimac::ShapeVertex), dataPointer, GL_STATIC_DRAW);
}

void initVAO(GLuint* vao_ptr, GLuint vbo) {
    glCreateVertexArrays(1, vao_ptr);

    glVertexArrayVertexBuffer(*vao_ptr, 0, vbo, 0, sizeof(glimac::ShapeVertex));

    glEnableVertexArrayAttrib(*vao_ptr, 0);
    glEnableVertexArrayAttrib(*vao_ptr, 1);
    glEnableVertexArrayAttrib(*vao_ptr, 2);

    glVertexArrayAttribFormat(*vao_ptr, 0, 3, GL_FLOAT, GL_FALSE, offsetof(glimac::ShapeVertex, position));
    glVertexArrayAttribFormat(*vao_ptr, 1, 3, GL_FLOAT, GL_FALSE, offsetof(glimac::ShapeVertex, normal));
    glVertexArrayAttribFormat(*vao_ptr, 2, 2, GL_FLOAT, GL_FALSE, offsetof(glimac::ShapeVertex, texCoords));

    glVertexArrayAttribBinding(*vao_ptr, 0, 0);
    glVertexArrayAttribBinding(*vao_ptr, 1, 0);
    glVertexArrayAttribBinding(*vao_ptr, 2, 0);
}