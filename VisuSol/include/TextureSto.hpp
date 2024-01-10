#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <vector>


struct TextureSto
{
	TextureSto() 
	{
		generateTexture();
		generatePerihelions();
		generateAphelions();
		generateOrbitalExentr();
		generateOrbitalInclinaisons();
		generateOrbitalPeriod();
		generateDistancesFromSun();
		generateLenghstOfDays();
		generateObliquitys();
		generateDiameters();
	};
	void generateTexture()
	{
		textures.emplace_back(glimac::loadImage("../assets/models/textures/sunmap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/mercurymap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/venusmap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/earthmap1k.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/mars_1k_color.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/jupitermap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/saturnmap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/uranusmap.jpg"));
		textures.emplace_back(glimac::loadImage("../assets/models/textures/neptunemap.jpg"));

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

	void generatePerihelions()
	{
		perihelions = {0, 46.0f , 107.5f, 147.1f, 206.7f, 440.6f, 1350.6f, 2732.7f, 4471.1f};
	}
	void generateAphelions()
	{
		aphelions = {0, 69.8,	108.9,	152.1, 249.3,	816.4,	1506.5,	3001.4,	4558.9};
	}
	void generateOrbitalExentr()
	{
		orbitalExentricitys = {0, 0.206,	0.007,	0.017,	0.094,	0.049,	0.052,	0.047,	0.010 };
	}
	void generateOrbitalInclinaisons()
	{
		orbitalInclinaisons = { 0, 7.0,	3.4,	0.0,	1.8,	1.3,	2.5,	0.8,	1.8 };
	}
	void generateOrbitalPeriod()
	{
		orbitalPeriods = { 0, 88.0,	224.7,	365.2, 687.0,	4331,	10.747,	30.589,	59.800 };
	}
	void generateDistancesFromSun()
	{
		distancesFromSun = {0, 57.9,	108.2,	149.6, 228.0,	778.5,	1432.0,	2867.0,	4515.0 };

	}
	void generateLenghstOfDays()
	{
		lenghtsOfDays = { 25.0 , 4222.6,	2802.0,	24.0,	24.7,	9.9,	10.7,	17.2,	16.1 };
	}
	void generateObliquitys()
	{
		obliquitys = { 0, 0.034,	177.4,	23.4,	25.2,	3.1,	26.7,	97.8,	28.3,	119.5, };
	}
	void generateDiameters()
	{
		diameters = { 0, 4879,	12104,	12756,	6792,	142984,	120536,	51118,	49528 };
	}
	std::vector<GLuint> tex;
	std::vector<std::unique_ptr<glimac::Image>> textures;
	std::vector<std::unique_ptr<glimac::Image>> secondTextures;
	std::vector<glm::vec3> randomAngle;
	std::vector<float> perihelions;
	std::vector<float> aphelions;
	std::vector<float> orbitalExentricitys;
	std::vector<float> orbitalInclinaisons;

	std::vector<float> orbitalPeriods;
	std::vector<float> distancesFromSun;
	std::vector<float> lenghtsOfDays;
	std::vector<float> obliquitys;
	std::vector<float> diameters;
};