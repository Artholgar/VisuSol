#include "include/Planet.hpp"

void Planet::draw(glimac::Camera cam, glm::mat4 model) const {
    glm::mat4 view = cam.getViewMatrix();
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    model = glm::rotate(model, _rotate_angle, _rotate_axis);
    model = glm::translate(model, _translate);
    model = glm::scale(model, _scale);

    glm::mat4 MVMatrix = view * model;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    glBindVertexArray(_vao);

    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);

    glBindVertexArray(0);
}