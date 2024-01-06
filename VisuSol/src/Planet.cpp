#include "include/Planet.hpp"



float cpt = 0.f;
void Planet::draw(glimac::Camera cam, glm::mat4 model) const {
    auto temp = model;
    GLint uTexture = glGetUniformLocation(_program.m_Program.getGLId(), "uTexture");
    GLuint texPlanete;
    glGenTextures(1, &texPlanete);

    glBindTexture(GL_TEXTURE_2D, texPlanete);
    glUniform1i(uTexture, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, vTex.textures[0]->getWidth(), vTex.textures[0]->getHeight(), 0, GL_RGBA, GL_FLOAT, vTex.textures[0]->getPixels());


    glBindVertexArray(_vao);
    glm::mat4 view = cam.getViewMatrix();
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    model = glm::translate(model, glm::vec3(0, 0, -30));
    model = glm::rotate(model, cpt, glm::vec3(0, 1, 0));
    

    model = glm::scale(model, _scale);

    glm::mat4 MVMatrix = view * model;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    glBindTexture(GL_TEXTURE_2D, texPlanete);

    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);

    for (int i = 1; i < 9; i++) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, vTex.textures[i]->getWidth(), vTex.textures[i]->getHeight(), 0, GL_RGBA, GL_FLOAT, vTex.textures[i]->getPixels());
        glm::mat4 view = cam.getViewMatrix();
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

        model = glm::translate(model, glm::vec3(0, 0, (vTex.aphelions[i] - vTex.perihelions[i])/2));
        model = glm::scale(model, _scale); //glm::vec3(0, 1- vTex.orbitalExentricitys[i], 0)
        model = glm::rotate(model, glm::radians(vTex.orbitalInclinaisons[i]), glm::vec3(0, 1, 0));
        model = glm::rotate(model, 2*glm::pi<float>()/(vTex.orbitalPeriods[i]*24), glm::vec3(0, 1, 0));
        model = glm::translate(model, glm::vec3(0, 0, vTex.distancesFromSun[i]/10));
        model = glm::rotate(model, 2 * glm::pi<float>() / (vTex.lenghtsOfDays[i]), glm::vec3(0, (1-(vTex.obliquitys[i]))/90, (vTex.obliquitys[i]) / 90));

        model = glm::scale(model, glm::vec3(vTex.diameters[i]/13920));

        glm::mat4 MVMatrix = view * model;
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));


        glBindTexture(GL_TEXTURE_2D, texPlanete);
        glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
        

    }
    cpt = (cpt + 0.01f);
}


