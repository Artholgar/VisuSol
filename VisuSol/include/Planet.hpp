#pragma once
#include "Drawable.hpp"
#include "Orbit.hpp"
#include "GraphicEngine.hpp"
#include "Programs.hpp"
#include "AppEngine.hpp"
#include <glimac/Image.hpp>
#include "glimac/common.hpp"
#include "glimac/Sphere.hpp"
#include <vector>

class Orbit;

class Planet : public Drawable {
public:
    Planet(glimac::Sphere sphere, glm::f32 rotate_angle, glm::vec3 rotate_axis, glm::vec3 translate, glm::vec3 scale, std::unique_ptr<glimac::Image> imageTexture)
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
        _imageTexture = std::move(imageTexture);

    }

    void draw(glimac::Camera cam, glm::mat4 model) const override;

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
    std::unique_ptr<glimac::Image> _imageTexture;

};
