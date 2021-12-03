#include "myglobal.h"
#include "log.h"
//This is Connor's source file.
// this is a test
//Worked on Android for lab 10 got button and swipe down to close functionality working.

Global::Global() {
		logOpen();
		done=0;
		xres=800;
		yres=600;
		showBigfoot=0;
		forest=1;
		silhouette=1;
		trees=1;
		showRain=0;
		showUmbrella=0;
		deflection=0;
		credits=0;
		help=0;
	}
//Global::~Global() {
//		logClose();
//	}
//Global g;

void showCredits(int x,int y)
{
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 1;
    ggprint16(&r, 16, 0x0000ff00, "*CREDITS*");
    ggprint16(&r, 16, 0x0000ff00, "-------------------------");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "Mike Cha");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "Eduardo Ramos Soriano");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "Keith Lappin");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "Connor Tennison");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "-------------------------");
	
	glBindTexture(GL_TEXTURE_2D, g.credits);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[1].width, img[1].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[1].data);
}
void genPlay() {
		glBindTexture(GL_TEXTURE_2D, g.play);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, img[1].width, img[1].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[1].data);
}
