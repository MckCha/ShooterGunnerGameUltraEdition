//Mike Cha

#include "fonts.h"
#include "myglobal.h"
#include <string.h>
#include "log.h"
#include <vector>
void showCredits(int x,int y)
{
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 1;
    ggprint16(&r, 16, 0x00ff0000, "*CREDITS*");
    ggprint16(&r, 16, 0x00ff0000, "-------------------------");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Mike Cha");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Eduardo Ramos Soriano");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Keith Lappin");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Connor Tennison");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "-------------------------");
}

//Declares bigfoot Object.
Bigfoot::Bigfoot() {};
Bigfoot bigfoot;

Image img[6] = {
//"./images/bigfoot.png",
"./images/yep.png",
"./images/space.png",
"./images/forestTrans.png",
"./images/umbrella.png",
"./images/Startmenu.png",
"./images/resolution.png"};
//"./images/yep.png" };

extern Global g;

void createMenu() {
    glBindTexture(GL_TEXTURE_2D, g.startMenu);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[4].width, img[4].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[4].data);
}

void createSettings() {
    glBindTexture(GL_TEXTURE_2D, g.settingPage);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[5].width, img[5].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[5].data);
}

