#include <GL/glx.h>
#include <vector>
#include <iostream>


#ifndef _x_MYGLOBAL
#define _x_MYGLOBAL


//macros
#define rnd() (((double)rand())/(double)RAND_MAX)
#define random(a) (rand()%a)
#define MakeVector(x, y, z, v) (v)[0]=(x),(v)[1]=(y),(v)[2]=(z)
#define VecZero(v) (v)[0]=0.0,(v)[1]=0.0,(v)[2]=0.0
#define VecCopy(a,b) (b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2]
#define VecDot(a,b)	((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])
#define VecSub(a,b,c) (c)[0]=(a)[0]-(b)[0]; \
                      (c)[1]=(a)[1]-(b)[1]; \
                      (c)[2]=(a)[2]-(b)[2]


typedef double Flt;
typedef double Vec[3];
typedef Flt Matrix[4][4];

//constants
static const float timeslice = 1.0f;
static const float gravity = -0.2f;

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
class Bigfoot {
public:
	Vec pos;
	Vec vel;
	Bigfoot();
};

#endif
