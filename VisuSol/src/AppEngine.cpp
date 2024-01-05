#include "include/AppEngine.hpp"

int window_width  = 1280;
int window_height = 720;

float rotateLeft = 0.f;
float rotateUp   = 0.f;
float moveFront  = 0.f;
float moveLeft   = 0.f;

int mouseLeftClick = 1;

double cursorPosX;
double cursorPosY;

glimac::TrackBallCamera cam;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    /*if (key == GLFW_KEY_UP) {
        if (action == GLFW_PRESS)
            rotateUp = 1.f;
        else if (action == GLFW_RELEASE)
            rotateUp = 0.f;
    }
    if (key == GLFW_KEY_DOWN) {
        if (action == GLFW_PRESS)
            rotateUp = -1.f;
        else if (action == GLFW_RELEASE)
            rotateUp = 0.f;
    }
    if (key == GLFW_KEY_LEFT) {
        if (action == GLFW_PRESS)
            rotateLeft = 1.f;
        else if (action == GLFW_RELEASE)
            rotateLeft = 0.f;
    }
    if (key == GLFW_KEY_RIGHT) {
        if (action == GLFW_PRESS)
            rotateLeft = -1.f;
        else if (action == GLFW_RELEASE)
            rotateLeft = 0.f;
    }
    if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS)
            moveFront = 0.1f;
        else if (action == GLFW_RELEASE)
            moveFront = 0.f;
    }
    if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS)
            moveFront = -0.1f;
        else if (action == GLFW_RELEASE)
            moveFront = 0.f;
    }
    if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS)
            moveLeft = 0.1f;
        else if (action == GLFW_RELEASE)
            moveLeft = 0.f;
    }
    if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS)
            moveLeft = -0.1f;
        else if (action == GLFW_RELEASE)
            moveLeft = 0.f;
    }*/
}

static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    //if (button == GLFW_MOUSE_BUTTON_LEFT) {
    //    if (action == GLFW_PRESS) {
    //        // set cursor position
    //        glfwGetCursorPos(window, &cursorPosX, &cursorPosY);
    //        mouseLeftClick = 1;
    //    }
    //    else if (action == GLFW_RELEASE) {
    //        mouseLeftClick = 1;
    //    }
    //}
}

static void scroll_callback(GLFWwindow* /*window*/, double /*xoffset*/, double /*yoffset*/)
{
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    // double posX, posY;

    // glfwGetCursorPos(window, &posX, &posY);

    /*if (mouseLeftClick && xpos < cursorPosX) {
        cam.rotateLeft(0.5f);
    }
    if (mouseLeftClick && cursorPosX < xpos) {
        cam.rotateLeft(-0.5f);
    }
    if (mouseLeftClick && ypos < cursorPosY) {
        cam.rotateUp(0.5f);
    }
    if (mouseLeftClick && cursorPosY < ypos) {
        cam.rotateUp(-0.5f);
    }

    cursorPosX = xpos;
    cursorPosY = ypos;*/
}

static void size_callback(GLFWwindow* window, int width, int height)
{
    window_width  = width;
    window_height = height;
}

int initWindow(GLFWwindow** window) {

    *window = glfwCreateWindow(window_width, window_height, "VisuSol", nullptr, nullptr);
    if (!*window) {
        glfwTerminate();
        return 0;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(*window);

    /* Hook input callbacks */
    glfwSetKeyCallback(*window, &key_callback);
    glfwSetMouseButtonCallback(*window, &mouse_button_callback);
    glfwSetScrollCallback(*window, &scroll_callback);
    glfwSetCursorPosCallback(*window, &cursor_position_callback);
    glfwSetWindowSizeCallback(*window, &size_callback);

    return 1;
}