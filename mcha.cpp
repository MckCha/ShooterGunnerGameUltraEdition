#include "fonts.h"
void showCredits(int x,int y)
{
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 1;
    ggprint8b(&r, 16, 0x00ff0000, "Mike Cha");
    ggprint8b(&r, 16, 0x00ff0000, "Eduardo Ramos Soriano");
    ggprint8b(&r, 16, 0x00ff0000, "Keith Lappin");
    ggprint8b(&r, 16, 0x00ff0000, "Connor Tennison");
}