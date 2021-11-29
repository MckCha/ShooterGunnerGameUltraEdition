//Keith Lappins Source File
#include "stdio.h"
#include "fonts.h"
#include "cstring"
#include "cmath"
#include "vector"
#include "myglobal.h"
//extern Global g;

int enemycount;
int enemylascount;
int playerlascount;
bool playerexists;

/*---------LASERS---------*/
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
        void cleanupLasers();
        void deleteLaser(Laser*);
        void createEnemyLaser(const int, const int);
        void createPlayerLaser(const int, const int);
        void checkLasers();
        void drawLasers();
    private:
        void createLaser(const int, const int);
        

};

Laser *headlaser;

void deleteLaser(Laser *node)
{
    if (node->type == 0)
    {    enemylascount--;}
    else if (node->type == 1)
    {    playerlascount--;}
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
    enemylascount = 0;
    playerlascount = 0;
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
}

 
//Call these creates
void createEnemyLaser(const int xval, const int yval)
{
    if (enemylascount < MAX_ENEMYLAS)
    {
        createLaser(xval, yval);
        headlaser->type = 0;
        headlaser->color[0] = 0.9f;
        headlaser->color[1] = 0.1f;
        headlaser->color[2] = 0.1f;
        headlaser->color[3] = 0.8f;
        headlaser->pos[1] -= 10.0f;
        enemylascount++;
    }

}

void createPlayerLaser(const int xval, const int yval)
{
    if (playerlascount < MAX_PLAYERLAS)
    {
        createLaser(xval, yval);
        headlaser->type = 1;
        headlaser->color[0] = 0.1f;
        headlaser->color[1] = 0.1f;
        headlaser->color[2] = 0.9f;
        headlaser->color[3] = 0.8f;
        headlaser->pos[1] += 10.0f;
        playerlascount++;
    }
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
   
    int n=0;
    node = headlaser;
   
   //now check if any are out of bounds.
   //also check if contact with ship once that logic is in
    while (node) {
        n++;
        if (node->pos[1] < -20.0f || node->pos[1] > g.yres) 
        {
            Laser *savenode = node->next;
            deleteLaser(node);
            node = savenode;
            continue;
        }
    node = node->next;
    }
}

void drawLasers()
{
    Laser *node = headlaser;
    while (node) {
        glPushMatrix();
        glTranslated(node->pos[0],node->pos[1],node->pos[2]);
        glColor4fv(node->color);
        glLineWidth(node->linewidth);
        glBegin(GL_LINES);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(0.0f, node->length);
        glEnd();
        glPopMatrix();
        node = node->next;
    }

    glLineWidth(1);
        
}
/*---------END LASERS---------*/


/*---------ENEMIES------------*/


class Enemy {
    public:
        Vec pos;
        double direction;
        double vel;
        double color[3];
        Enemy *prev;
        Enemy *next;
        
};

Enemy *headenemy;

void createEnemy()
{
    if (enemycount < MAX_ENEMIES)
    {
        Enemy *node = (Enemy *)(malloc(sizeof(Enemy)));
        if (node == NULL)
        {
            Log("error allocating enemy.\n");
            exit(EXIT_FAILURE);
        }
        node->pos[0] = (Flt)(g.xres/random(10));
        node->pos[1] = (Flt)(g.yres-(random(50)));
        node->pos[2] = 0;
        node->vel = 1.0;
        node->direction = 1.0;
        node->color[0] = 1.0;
        node->color[1] = 1.0;
        node->color[2] = 1.0;
        node->next = headenemy;
        if (headenemy != NULL)
            headenemy->prev = node;
        headenemy = node;
        ++enemycount;        
    }

}

void deleteEnemy(Enemy *node)
{
    if (node->prev == NULL) {
        if (node->next == NULL) {
            headlaser = NULL;
        } else {
            node->next->prev = NULL;
            headenemy = node->next;
        }
   } else {
       if (node->next == NULL) {
           node->prev->next = NULL;
       } else {
           node->prev->next = node->next;
           node->next->prev = node->prev;
       }
   }
   free(node);
   node = NULL;
}

void cleanupEnemies()
{
    Enemy * s;
    while (headenemy) {
        s = headenemy->next;
        free(headenemy);
        headenemy = s;
    }
    headenemy=NULL;
}
/*
void checkCollisions()
{

}

void checkEnemies()
{
    checkCollissions();
  
    Enemy *node = headenemy;

    //update all positions
    //enemies will move like space invaders. Move to the right, drop down,
    //increase speed and reverse.
    while (node) {
        if (
        

}
    
*/
/*---------END ENEMIES--------*/



/*---------PLAYER SHIP--------*/


/*---------END PLAYER SHIP----*/
