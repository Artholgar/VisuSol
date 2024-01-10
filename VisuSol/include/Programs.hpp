#pragma once
#include "glimac/Program.hpp"

struct PlanetProgram {
    glimac::Program m_Program;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;
    //GLint uTexture;

    PlanetProgram(const glimac::FilePath& applicationPath) :
        m_Program(glimac::loadProgram("../VisuSol/shaders/vertex.vs.glsl",
            "../VisuSol/shaders/fragment.fs.glsl")) {
        m_Program.use();
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        //uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};