// Name: Eduardo Ramos Soriano
// Date edited: 11/18/2021
// My source file for group project
// --------------------------------------
// Description:                         |
// This source file includes a function |
// that will display a tutorial menu    |
// when the help key (h) is selected.   |
// --------------------------------------
#include "fonts.h"
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

void displayHelp(int x,int y)
{
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 1;
    ggprint16(&r, 16, 0x0000ff00, "*TUTORIAL*");
    ggprint16(&r, 16, 0x0000ff00, "-----------------------------------------");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "(<- left key) - Move to the left");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "(-> right key) - Move to the right");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "(^ up key) - Move the rocket forward");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "* Hold down up key to accelerate *");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "(v down key) - Move the rocket backward");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "([space] key) - Shoot bullets");
    ggprint16(&r, 16, 0x0000ff00, "-----------------------------------------");
    ggprint16(&r, 16, 0x0000ff00, "    ");
    ggprint16(&r, 16, 0x0000ff00, "(H key) - Exit from help menu");

}

void gameOver(int x, int y){
    Rect r;
    r.bot = y;
    r.left = x;
    r.center = 1;
    ggprint16(&r, 16, 0x000000ff, "GAME OVER!");
    ggprint16(&r, 16, 0x000000ff, "Thank you for playing.");
}
