#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <vector>


struct TextureSto
{
	TextureSto::TextureSto() {};
	void generateTexture()
	{
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\sunmap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\mercurymap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\venusmap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\earthmap1k.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\mars_1k_color.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\jupitermap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\saturnmap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\uranusmap.jpg"));
		textures.emplace_back(glimac::loadImage("C:\\Users\\Paul\\Documents\\openGLroot\\VisuSol\\assets\\models\\textures\\neptunemap.jpg"));
		for (int i = 0; i < 8; i++) {
			randomAngle.push_back(glm::sphericalRand(2.f));

		}
	}

	

	std::vector<std::unique_ptr<glimac::Image>> textures;
	std::vector<std::unique_ptr<glimac::Image>> secondTextures;
	std::vector<glm::vec3> randomAngle;
};