// Eduardo Ramos Soriano
// 9/30/2021
// Lab 6 commit

#include "fonts.h"

void display_credits(int x, int y)
{
	Rect r;
	r.bot = y;
	r.left = x;
	r.center = 1;
	ggprint8b(&r, 16, 0x00000000, "Connor Tennison");
	ggprint8b(&r, 20, 0x00ffff00, "Eduardo Ramos Soriano");
	ggprint8b(&r, 24, 0x00ff00ff, "Keith Lappin");
	ggprint8b(&r, 28, 0xffff0000, "Mike Cha");
}
