#include "include/GraphicEngine.hpp"

void initVBO(GLuint* vbo_ptr, const GLsizei vertexCount, const glimac::ShapeVertex* dataPointer)
{
    glGenBuffers(1, vbo_ptr);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo_ptr);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glimac::ShapeVertex) * vertexCount, dataPointer, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void initVAO(GLuint* vao_ptr, GLuint vbo) {

    glGenVertexArrays(1, vao_ptr);
    glBindVertexArray(*vao_ptr);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, position));
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, normal));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(glimac::ShapeVertex), (const GLvoid*)offsetof(glimac::ShapeVertex, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
