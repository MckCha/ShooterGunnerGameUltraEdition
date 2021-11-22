//Keith Lappins Source File
#include "stdio.h"
#include "fonts.h"
#include "cstring"
#include "cmath"
#include <vector>
#include "myglobal.h"
extern Global g;

int totlas;

class Laser {
    public:
        //type 1 is player laser, type 0 is enemy laser
        int type;
        int linewidth;
        int damage;
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

Laser *headlaser;

void deleteLaser(Laser *node)
{
    //if i am head laser
    if (node->prev == NULL) {
        //and i am alone
        if (node->next == NULL) {
            headlaser = NULL;
        //and there is someone ahead of me
        } else {
            node->next->prev = NULL;
            headlaser = node->next;
        }
    //if i am not head laser
    } else { 
        //if i am at the end of the list
        if (node->next == NULL) {
            node->prev->next = NULL;
        //if there are nodes on both sides of me
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }
    free(node);
    node = NULL;

}

void cleanupLasers()
{
    Laser *s;
    while (headlaser) {
        s = headlaser->next;
        free(headlaser);
        headlaser = s;
    }
    headlaser=NULL;
}

//pass in enemy/player coordinates
void createLaser(const int xval, const int yval)
{
        Laser *node = (Laser *)malloc(sizeof(Laser));
        if (node == NULL) {
            Log("error allocating node.\n");
            exit(EXIT_FAILURE);
        }
        node->type = 0;
        node->prev = NULL;
        node->next = NULL;
        node->pos[0] = xval;
        node->pos[1] = yval;
        VecCopy(node->pos, node->lastpos);
        node->vel[0] =
        node->vel[1] = 0.0f;
        //will keep linewidth = speed. more interesting than all being same
        node->linewidth = random(8)+1;
        node->maxvel[1] = (float)(node->linewidth*16);
        node->length = node->maxvel[1] * 0.2f + rnd();
        //add to linked list
        node->next = headlaser;
        if (headlaser != NULL)
            headlaser->prev = node;
        headlaser = node;
        ++totlas;
}

 
//Call these creates
void createEnemyLaser(const int xval, const int yval)
{
    //Double check type is correct, offset pos, and set color
    createLaser(xval, yval);
    headlaser->type = 0;
    headlaser->color[0] = 0.9f;
    headlaser->color[1] = 0.1f;
    headlaser->color[2] = 0.1f;
    headlaser->color[3] = 0.8f;
    headlaser->pos[1] -= 10.0f;

}

void createPlayerLaser(const int xval, const int yval)
{
    //Set correct type, offset pos, and set color
    createLaser(xval, yval);
    headlaser->type = 1;
    headlaser->color[0] = 0.1f;
    headlaser->color[1] = 0.1f;
    headlaser->color[2] = 0.9f;
    headlaser->color[3] = 0.8f;
    headlaser->pos[1] += 10.0f;

}

void checkLasers()
{
    //update positions of all lasers
    Laser *node = headlaser;
    while (node) {
        if (node->type == 0)
            node->vel[1] += gravity;
        else
            node->vel[1] += -gravity;
        
        VecCopy(node->pos, node->lastpos);
        node->pos[0] += node->vel[0] * timeslice;
        node->pos[1] += node->vel[1] * timeslice;
        if (fabs(node->vel[1]) > node->maxvel[1])
            node->vel[1] *= 0.96;
        node->vel[0] *= 0.999;
        node = node->next;
   }
   
   //int n=0;
   node = headlaser;
   
   //now check if any are out of bounds.
   while (node) {
    if (node->pos[1] < -20.0f || node->pos[1] > g.yres) 
    {
       Laser *savenode = node->next;
       deleteLaser(node);
       node = savenode;
       continue;
    }
   }







}
