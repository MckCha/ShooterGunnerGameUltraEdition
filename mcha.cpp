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
    ggprint16(&r, 16, 0x00ffff00, "*CREDITS*");
    ggprint16(&r, 16, 0x00ffff00, "-------------------------");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Mike Cha");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Eduardo Ramos Soriano");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Keith Lappin");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ff0000, "Connor Tennison");
    ggprint16(&r, 16, 0x00ff0000, "    ");
    ggprint16(&r, 16, 0x00ffff00, "-------------------------");
}

//Declares bigfoot Object.
Bigfoot::Bigfoot() {};
Bigfoot bigfoot;
