#include "include/Planet.hpp"



float cpt = 0.f;
void Planet::draw(glimac::FreeflyCamera cam, glm::mat4 model) const {
    auto sunModel = model;

    glBindVertexArray(_vao);
    glm::mat4 view = cam.getViewMatrix();
    //view = glm::rotate(view, (float)30., glm::vec3(1, 0, 0));
    //view = glm::translate(view, glm::vec3(0, 0, -10));
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    // sunModel = glm::translate(sunModel, glm::vec3(0, 0, -10));
    sunModel = glm::rotate(sunModel, (float) (glfwGetTime() * 360. / (vTex.lenghtsOfDays[0])), glm::vec3(0, 1, 0));
    

    sunModel = glm::scale(sunModel, _scale);

    glm::mat4 MVMatrix = view * sunModel;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

    glm::vec3 Kd(1., 1., 1.);
    glm::vec3 Ks(.5, 5., .5);
    float Shininess = 1.f;
    glm::vec3 LightPos(0);
    glm::vec3 LightPos_vs(1);
    glm::vec3 LightIntensity(1., 1., 1.);

    LightPos_vs = view * glm::vec4(LightPos, 0);

    _program.m_Program.use();

    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
    glUniform3fv(_program.uKd, 1, &Kd[0]);
    glUniform3fv(_program.uKs, 1, &Ks[0]);
    glUniform1f(_program.uShininess, Shininess);
    glUniform3fv(_program.uLightPos_vs, 1, &LightPos_vs[0]);
    glUniform3fv(_program.uLightIntensity, 1, &LightIntensity[0]);

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
        LightPos_vs = view * glm::vec4(LightPos, 0);

        _program.m_Program.use();

        glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glUniform3fv(_program.uKd, 1, &Kd[0]);
        glUniform3fv(_program.uKs, 1, &Ks[0]);
        glUniform1f(_program.uShininess, Shininess);
        glUniform3fv(_program.uLightPos_vs, 1, &LightPos_vs[0]);
        glUniform3fv(_program.uLightIntensity, 1, &LightIntensity[0]);


        glBindTexture(GL_TEXTURE_2D, vTex.tex[i]);
        glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
        

    }
    cpt = (cpt + 0.01f);
}


