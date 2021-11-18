//Mike Cha

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
