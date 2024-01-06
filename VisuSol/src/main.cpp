#include "include/GraphicEngine.hpp"
#include "include/AppEngine.hpp"
#include "glimac/Sphere.hpp"
#include <glimac/FilePath.hpp>

#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>

#include <glad/glad.h>
#include <iostream>

int main(int argc, char* argv[]) {
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