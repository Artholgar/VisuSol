#include "include/GraphicEngine.hpp"
#include "include/AppEngine.hpp"
#include "glimac/Sphere.hpp"
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>

#include <glad/glad.h>
#include <iostream>

int main(int argc, char* argv[]) {
    std::unique_ptr<glimac::Image> pSoleil;

    pSoleil = glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\sunmap.jpg");
    /* Initialize the library */
    if (!glfwInit()) {
        return -1;
    }

    /* Create a window and its OpenGL context */
#ifdef __APPLE__
    /* We need to explicitly ask for a 3.3 context on Mac */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    GLFWwindow* window;

    if (!initWindow(&window)) {
        return -1;
    }

    /* Intialize glad (loads the OpenGL functions) */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        return -1;
    }
    glimac::FilePath applicationPath(argv[0]);
    glimac::Program  program = glimac::loadProgram("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\VisuSol\\shaders\\vertex.vs.glsl",
        "C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\VisuSol\\shaders\\fragment.fs.glsl");
    program.use();
    GLint   pId = program.getGLId();
    GLint uMVMatrix = glGetUniformLocation(pId, "uMVMatrix");
    GLint uMVPMatrix = glGetUniformLocation(pId, "uMVPMatrix");
    GLint uNormalMatrix = glGetUniformLocation(pId, "uNormalMatrix");


    glEnable(GL_DEPTH_TEST);
    glm::mat4 ProjMatrix(1);
    glm::mat4 MVMatrix(1);
    glm::mat4 NormalMatrix(1);
    GLint uTexture = glGetUniformLocation(pId, "uTexture");
    GLuint sunTextId;
    glGenTextures(1, &sunTextId);

    glBindTexture(GL_TEXTURE_2D, sunTextId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, pSoleil->getWidth(), pSoleil->getHeight(), 0, GL_RGBA, GL_FLOAT, pSoleil->getPixels());

    glUniform1i(uTexture, 0);
    GLuint vbo, vao;

    glimac::Sphere sphere(1, 32, 16);

    initVBO(&vbo, sphere.getVertexCount(), sphere.getDataPointer());

    initVAO(&vao, vbo);

    SolarSystem ss(sphere);
    float cpt = 1.f;
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(vao);
        const auto planet = ss.getStar();
        ProjMatrix = glm::perspective<float>(glm::radians(70.f), (float)(1280 / 720), 0.1f, 100.f);
        MVMatrix = glm::translate<float>(glm::mat4(1), glm::vec3(0, 0, -5));
        MVMatrix = glm::rotate(MVMatrix, cpt, glm::vec3(0, 1, 0)); // Translation * Rotation
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));
        glBindTexture(GL_TEXTURE_2D, sunTextId);
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
        cpt += 0.1f;
    }

    glfwTerminate();

    return 0;
}