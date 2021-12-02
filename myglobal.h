#include <GL/glx.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <unistd.h>

#ifndef _x_MYGLOBAL
#define _x_MYGLOBAL


//defined types
typedef double Flt;
typedef double Vec[3];
typedef Flt	Matrix[4][4];



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
//constants
const float timeslice = 1.0f;
const float gravity = -0.4f;
const int MAX_ENEMIES = 10;
const int MAX_ENEMYLAS = 15;
const int MAX_PLAYERLAS = 5;
#define ALPHA 1

//variables
int SCORE;
int enemycount;
int enemylascount;
int playerlascount;
bool playerexists;
bool gameover;


class Global {
public:
	int done;
	int help;
	int xres, yres;
	GLuint bigfootTexture;
	GLuint silhouetteTexture;
	GLuint forestTexture;
	GLuint forestTransTexture;
	GLuint umbrellaTexture;
	GLuint startMenu;
	GLuint settingPage;
	int credits;
	int showBigfoot;
	int forest;
	int silhouette;
	int menu;
	int settings;
	int trees;
	int showRain;
	int showUmbrella;
	int deflection;
	Global();
};

class Laser {
    public:
        //type 1 is player laser, type 0 is enemy laser
        int type;
        int linewidth;
        Vec pos;
        Vec lastpos;
        Vec vel;
        Vec maxvel;
        Vec force;
        float length;
        float color[4];
        Laser *prev;
        Laser *next;

};

class Enemy {
    public:
        Vec pos;
        double direction;
        double vel;
        double color[3];
        double radius;
        Enemy *prev;
        Enemy *next;
};

class Player {
    public:
        Vec pos;
        double color[3];
        double radius;
        Player();
} PShip;

typedef double Vec[3];
class Bigfoot {
public:
	Vec pos;
	Vec vel;
	Bigfoot();
};

class Image {
public:
	int width, height;
	unsigned char *data;
	~Image() { delete [] data; }
	Image(const char *fname) {
		if (fname[0] == '\0')
			return;
		//printf("fname **%s**\n", fname);
		int ppmFlag = 0;
		char name[40];
		strcpy(name, fname);
		int slen = strlen(name);
		char ppmname[80];
		if (strncmp(name+(slen-4), ".ppm", 4) == 0)
			ppmFlag = 1;
		if (ppmFlag) {
			strcpy(ppmname, name);
		} else {
			name[slen-4] = '\0';
			//printf("name **%s**\n", name);
			sprintf(ppmname,"%s.ppm", name);
			//printf("ppmname **%s**\n", ppmname);
			char ts[100];
			//system("convert eball.jpg eball.ppm");
			sprintf(ts, "convert %s %s", fname, ppmname);
			system(ts);
		}
		//sprintf(ts, "%s", name);
		FILE *fpi = fopen(ppmname, "r");
		if (fpi) {
			char line[200];
			fgets(line, 200, fpi);
			fgets(line, 200, fpi);
			//skip comments and blank lines
			while (line[0] == '#' || strlen(line) < 2)
				fgets(line, 200, fpi);
			sscanf(line, "%i %i", &width, &height);
			fgets(line, 200, fpi);
			//get pixel data
			int n = width * height * 3;			
			data = new unsigned char[n];			
			for (int i=0; i<n; i++)
				data[i] = fgetc(fpi);
			fclose(fpi);
		} else {
			printf("ERROR opening image: %s\n",ppmname);
			exit(0);
		}
		if (!ppmFlag)
			unlink(ppmname);
	}
};

extern Image img[];



#endif
