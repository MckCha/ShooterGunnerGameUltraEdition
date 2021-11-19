#include <GL/glx.h>
#include <vector>
#include <iostream>


#ifndef _x_MYGLOBAL
#define _x_MYGLOBAL
class Global {
public:
	int done;
	int xres, yres;
	GLuint bigfootTexture;
	GLuint silhouetteTexture;
	GLuint forestTexture;
	GLuint forestTransTexture;
	GLuint umbrellaTexture;
	int showBigfoot;
	int forest;
	int silhouette;
	int trees;
	int showRain;
	int showUmbrella;
	int deflection;
	Global();
};
typedef double Vec[3];
class Bigfoot {
public:
	Vec pos;
	Vec vel;
	Bigfoot();
};

#endif
