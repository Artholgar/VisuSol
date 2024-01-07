
#include "glimac/Sphere.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>

#include <glad/glad.h>
#include <iostream>

#include "include/SolarSystem.hpp"

int main(int argc, char** argv) {

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
    glEnable(GL_DEPTH_TEST);
    glimac::Sphere sphere(1, 32, 16);

    SolarSystem ss(sphere);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        ss.drawAll();

        updateCam();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}