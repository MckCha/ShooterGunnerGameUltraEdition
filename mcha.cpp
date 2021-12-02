//Mike Cha

#include "fonts.h"
#include "myglobal.h"
#include <string.h>
#include "log.h"
#include <vector>


//Declares bigfoot Object.
Bigfoot::Bigfoot() {};
Bigfoot bigfoot;

Image img[9] = {
"./images/yep.png",
"./images/space.png",
"./images/forestTrans.png",
"./images/umbrella.png",
"./images/Startmenu.png",
"./images/resolution.png",
"./images/resolution1.png",
"./images/resolution2.png",
"./images/resolution3.png"};

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

void createRes1() {
    glBindTexture(GL_TEXTURE_2D, g.resolution1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[6].width, img[6].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[6].data);
}

void createRes2() {
    glBindTexture(GL_TEXTURE_2D, g.resolution1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[7].width, img[7].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[7].data);
}

void createRes3() {
    glBindTexture(GL_TEXTURE_2D, g.resolution1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img[8].width, img[8].height,
									0, GL_RGB, GL_UNSIGNED_BYTE, img[8].data);
}
