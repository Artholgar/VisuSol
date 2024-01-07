#include "include/Planet.hpp"



float cpt = 0.f;
void Planet::draw(glimac::Camera cam, glm::mat4 model) const {
    auto sunModel = model;
    ////GLint uTexture = glGetUniformLocation(_program.m_Program.getGLId(), "uTexture");
    //GLuint texPlanete;
    //glGenTextures(1, &texPlanete);

    //glBindTexture(GL_TEXTURE_2D, texPlanete);
    ////glUniform1i(uTexture, 0);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, vTex.textures[0]->getWidth(), vTex.textures[0]->getHeight(), 0, GL_RGBA, GL_FLOAT, vTex.textures[0]->getPixels());


    glBindVertexArray(_vao);
    glm::mat4 view = cam.getViewMatrix();
    //view = glm::rotate(view, (float)30., glm::vec3(1, 0, 0));
    //view = glm::translate(view, glm::vec3(0, 0, -10));
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    sunModel = glm::translate(sunModel, glm::vec3(0, 0, -10));
    sunModel = glm::rotate(sunModel, (float) glfwGetTime() * 360 / (vTex.lenghtsOfDays[0]), glm::vec3(0, 1, 0));
    

    sunModel = glm::scale(sunModel, _scale);

    glm::mat4 MVMatrix = view * sunModel;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

    glBindTexture(GL_TEXTURE_2D, vTex.tex[0]);

    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);

    // inverting the rotation of the sun, to not rotate planets with the sun
    sunModel = glm::rotate(sunModel, (float)-glfwGetTime() * 360 / (vTex.lenghtsOfDays[0]), glm::vec3(0, 1, 0));

    for (int i = 1; i < 9; i++) {
        glm::mat4 view = cam.getViewMatrix();
        glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);
        
        auto planetModel = sunModel;
        planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.aphelions[i] - vTex.perihelions[i])/2 / (13920 * 3)));
        // model = glm::scale(model, _scale); //glm::vec3(0, 1- vTex.orbitalExentricitys[i], 0)
        planetModel = glm::rotate(planetModel, vTex.orbitalInclinaisons[i], glm::vec3(1, 0, 0));
        planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 /(vTex.orbitalPeriods[i]*24), glm::vec3(0, 1, 0));
        planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.distancesFromSun[i]/100) + 1));
        planetModel = glm::rotate(planetModel, vTex.obliquitys[i], glm::vec3(0, 1, 0));
        planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 / (vTex.lenghtsOfDays[i]), glm::vec3(0, 1, 0));

        planetModel = glm::scale(planetModel, glm::vec3(vTex.diameters[i]/(13920 * 3)));

        glm::mat4 MVMatrix = view * planetModel;
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));


        glBindTexture(GL_TEXTURE_2D, vTex.tex[i]);
        glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
        

    }
    cpt = (cpt + 0.01f);
}


