#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glimac/FreeflyCamera.hpp"
#include "glimac/TrackBallCamera.hpp"

#include "SolarSystem.hpp"

static int getWindowWidth();
static int getWindowHeight();

static glimac::Camera getCam();

int initWindow(GLFWwindow** window);
