#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glimac/FreeflyCamera.hpp"
#include "glimac/TrackBallCamera.hpp"

int getWindowWidth();
int getWindowHeight();

glimac::Camera getCam();

int initWindow(GLFWwindow** window);
