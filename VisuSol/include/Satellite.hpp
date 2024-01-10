
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <vector>

struct Satellite
{
	Satellite()
	{
		generateTexture();
	};

	void generateTexture()
	{
		
		textures.emplace_back(glimac::loadImage("../assets/models/textures/moonmap1k.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/phobosbump.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/deimosbump.jpg"));
		for (const auto& img : textures) {
			GLuint texPlanete;
			glGenTextures(1, &texPlanete);

			glBindTexture(GL_TEXTURE_2D, texPlanete);
			//glUniform1i(uTexture, 0);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->getWidth(), img->getHeight(), 0, GL_RGBA, GL_FLOAT, img->getPixels());
			tex.emplace_back(texPlanete);
		}
	}


	std::vector<GLuint> tex;
	std::vector<std::unique_ptr<glimac::Image>> textures;
	std::vector<std::vector<int>> nbOfSat = { {},{},{0}, {1,2}};


	std::vector<float> orbitalInclinaisons = { 5.1, 1.08, 1.79 };

	std::vector<float> orbitalPeriods = { 27.3, 0.31891, 1.26244 };
	//std::vector<float> distancesFromSun = { 0.384 };
	//std::vector<float> lenghtsOfDays = { 708.7 };
	//std::vector<float> obliquitys = { 6.7 };
	std::vector<float> diameters = { 3475 ,22.2, 12.4  };

};