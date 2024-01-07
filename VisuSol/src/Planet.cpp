#include "include/Planet.hpp"


void Planet::draw(glimac::FreeflyCamera cam, glm::mat4 model) const {
    auto sunModel = model;

    glBindVertexArray(_vao);
    glm::mat4 view = cam.getViewMatrix();
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
        
        drawPlanetes(cam, model, i);
    }
}




void Planet::drawPlanetes(glimac::FreeflyCamera cam, glm::mat4 model, int nPlanet) const
{
    glm::mat4 view = cam.getViewMatrix();
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    auto planetModel = model;
    planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.aphelions[nPlanet] - vTex.perihelions[nPlanet]) / 2 / (13920 * 3)));
    planetModel = glm::rotate(planetModel, vTex.orbitalInclinaisons[nPlanet], glm::vec3(1, 0, 0));
    planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 / (vTex.orbitalPeriods[nPlanet] * 24), glm::vec3(0, 1, 0));
    planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.distancesFromSun[nPlanet] / 100) + 1));
    planetModel = glm::rotate(planetModel, vTex.obliquitys[nPlanet], glm::vec3(0, 1, 0));
    planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 / (vTex.lenghtsOfDays[nPlanet]), glm::vec3(0, 1, 0));

    planetModel = glm::scale(planetModel, glm::vec3(vTex.diameters[nPlanet] / (13920 * 3)));

    glm::mat4 MVMatrix = view * planetModel;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));


    glBindTexture(GL_TEXTURE_2D, vTex.tex[nPlanet]);
    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
    int cpt = 1;
    for (const auto& numPlat : sattelites.nbOfSat)
    {   

        if(cpt == nPlanet)
        for (const auto& numSat : numPlat)
        {
         
            drawSattelite(cam, planetModel, numSat, nPlanet);
        }
        cpt++;
    }
    /*if (nPlanet == 6) //Anneaux de saturne
    {

        std::vector<glm::vec3> randomAngle;
        float count_ring = 0.f;
        for (int i = 0; i < 150; i++) {

            glm::mat4 view = cam.getViewMatrix();
            randomAngle.push_back(glm::sphericalRand(2.f));
            randomAngle[i].y = 0;
            ProjMatrix = glm::perspective<float>(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);
            MVMatrix = glm::translate<float>(glm::mat4(1), glm::vec3(0, 0, -5));
            NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

            MVMatrix = glm::rotate(MVMatrix, (float)glfwGetTime(), glm::vec3(0, 1, 0)); // Translation * Rotation
            MVMatrix = glm::translate(MVMatrix, randomAngle[i]);       // Translation * Rotation * Translation
            MVMatrix = glm::scale(MVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale
            MVMatrix = MVMatrix * view;
            glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
            glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
            glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));


            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, vTex.tex[3]);
            glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
            count_ring += 0.5f;

        }

        
    }*/
}

void Planet::drawSattelite(glimac::FreeflyCamera cam, glm::mat4 model, int numSatt, int nPlanet) const
{
    glm::mat4 view = cam.getViewMatrix();
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), (float)(getWindowWidth()) / getWindowHeight(), 0.1f, 100.f);

    auto planetModel = model;
    planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.aphelions[nPlanet] - vTex.perihelions[nPlanet]) / 2 / (13920 * 3)));
    planetModel = glm::rotate(planetModel, sattelites.orbitalInclinaisons[numSatt], glm::vec3(1, 0, 0));
    planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 / (sattelites.orbitalPeriods[numSatt] * 24), glm::vec3(0, 1, 0));
    planetModel = glm::translate(planetModel, glm::vec3(0, 0, (vTex.distancesFromSun[nPlanet] / 100) + 1));
    planetModel = glm::rotate(planetModel, vTex.obliquitys[nPlanet], glm::vec3(0, 1, 0));
    planetModel = glm::rotate(planetModel, (float)glfwGetTime() * 360 / (vTex.lenghtsOfDays[nPlanet]), glm::vec3(0, 1, 0));

    planetModel = glm::scale(planetModel, glm::vec3(sattelites.diameters[numSatt] / (13920 * 3)));

    glm::mat4 MVMatrix = view * planetModel;
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
    glUniformMatrix4fv(_program.uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
    glUniformMatrix4fv(_program.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
    glUniformMatrix4fv(_program.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));


    glBindTexture(GL_TEXTURE_2D, sattelites.tex[numSatt]);
    glDrawArrays(GL_TRIANGLES, 0, _vertexCount);
}



