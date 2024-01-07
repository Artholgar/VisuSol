#pragma once
#include "glimac/Program.hpp"

//struct PlanetProgram {
//    glimac::Program m_Program;
//
//    GLint uMVPMatrix;
//    GLint uMVMatrix;
//    GLint uNormalMatrix;
//
//    PlanetProgram(const glimac::FilePath& applicationPath) :
//        m_Program(glimac::loadProgram("./VisuSol/shaders/vertex.vs.glsl",
//            "./VisuSol/shaders/fragment.fs.glsl")) {
//        m_Program.use();
//        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
//        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
//        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
//    }
//};

struct PlanetProgram {
    glimac::Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    GLint uKd;
    GLint uKs;
    GLint uShininess;
    GLint uLightPos_vs;
    GLint uLightIntensity;

    PlanetProgram(const glimac::FilePath& applicationPath)
        : m_Program(glimac::loadProgram("./VisuSol/shaders/vertex.vs.glsl",
            "./VisuSol/shaders/fragment.fs.glsl")) 
    {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uKd = glGetUniformLocation(m_Program.getGLId(), "uKd");
        uKs = glGetUniformLocation(m_Program.getGLId(), "uKs");
        uShininess = glGetUniformLocation(m_Program.getGLId(), "uShininess");
        uLightPos_vs = glGetUniformLocation(m_Program.getGLId(), "uLightPos_vs");
        uLightIntensity = glGetUniformLocation(m_Program.getGLId(), "uLightIntensity");
    }
};