#pragma once
#include "Drawable.hpp"
#include "Orbit.hpp"
#include "GraphicEngine.hpp"
#include "Programs.hpp"
#include "AppEngine.hpp"
#include <glimac/Image.hpp>
#include "glimac/common.hpp"
#include "glimac/Sphere.hpp"
#include "TextureSto.hpp"
#include "Satellite.hpp"
#include <vector>

class Orbit;

class Planet : public Drawable {
public:
    Planet(glimac::Sphere sphere, glm::f32 rotate_angle, glm::vec3 rotate_axis, glm::vec3 translate, glm::vec3 scale)
        : _program(glimac::FilePath("./VisuSol/")) 
        , _rotate_angle(rotate_angle)
        , _rotate_axis(rotate_axis)
        , _translate(translate)
        , _scale(scale)

    {
        _dataPointer = sphere.getDataPointer();
        _vertexCount = sphere.getVertexCount();
        _orbites = std::vector<Orbit>();

        initVBO(&_vbo, _vertexCount, _dataPointer);

        initVAO(&_vao, _vbo);

    }

    void draw(glimac::FreeflyCamera cam, glm::mat4 model) const override;

    void drawPlanetes(glimac::FreeflyCamera cam, glm::mat4 model, int nPlanet) const;

    void Planet::drawSattelite(glimac::FreeflyCamera cam, glm::mat4 model, int numPlat, int help) const;




private:
    const glimac::ShapeVertex* _dataPointer;
    GLsizei                    _vertexCount;
    GLuint               _vbo;
    GLuint               _vao;
    PlanetProgram        _program;
    glm::f32             _rotate_angle;
    glm::vec3            _rotate_axis;
    glm::vec3            _translate;
    glm::vec3            _scale;
    std::vector<Orbit>   _orbites;
    TextureSto vTex;
    Satellite sattelites;

};
