#include "include/Planet.hpp"




void Planet::draw(glimac::Camera cam, glm::mat4 model) const {
    GLint uTexture = glGetUniformLocation(_program.m_Program.getGLId(), "uTexture");
    GLuint texPlanete;
    glGenTextures(1, &texPlanete);

    glBindTexture(GL_TEXTURE_2D, texPlanete);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _imageTexture->getWidth(), _imageTexture->getHeight(), 0, GL_RGBA, GL_FLOAT, _imageTexture->getPixels());


    glBindVertexArray(_vao);
    glm::mat4 view = cam.getViewMatrix();
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    model = glm::rotate(model, _rotate_angle, _rotate_axis);
    model = glm::translate(model, _translate);
    model = glm::translate(model, glm::vec3(0, 0, -5));

    model = glm::scale(model, _scale);

    glm::mat4 MVMatrix = view * model;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    glBindTexture(GL_TEXTURE_2D, texPlanete);

    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);

    glBindVertexArray(0);
}


