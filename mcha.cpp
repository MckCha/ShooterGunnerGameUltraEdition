#include "fonts.h"
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glu.h>

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
// Source: https://docs.gl/es2/glTexImage2D
// Trying to still get an image from glTexImage2d Function
void glTexImage2D(
         GLenum  target,
         GLint   level,
         GLint   internalformat,
         GLsizei width,
         GLsizei height,
         GLint   border,
         GLint   format,
         GLenum  type,
         const GLvoid  *data
);
