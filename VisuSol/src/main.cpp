#include "include/GraphicEngine.hpp"

#include "glimac/Sphere.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <iostream>

int main() {
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

    GLuint vbo, vao;

    glimac::Sphere sphere(1, 32, 16);

    initVBO(&vbo, sphere.getVertexCount(), sphere.getDataPointer());

    initVAO(&vao, vbo);

    SolarSystem ss(sphere);

    while (!glfwWindowShouldClose(window)) {

        const auto planet = ss.getStar();

        planet.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}