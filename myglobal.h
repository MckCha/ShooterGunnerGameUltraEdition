#include <GL/glx.h>
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

#endif
