//Keith Lappins Source File
#include "stdio.h"
#include "fonts.h"
#include "cstring"
#include "cmath"
#include "vector"
#include "myglobal.h"
//extern Global g;

//variable declarations
int enemycount;
int enemylascount;
int playerlascount;
bool playerexists;
bool gameover;

//General Prototypes
void checkCollisions();
void spawner();

//class forward declarations
class Laser;
class Enemy;
class Player;

//functions are grouped with classes by association, most are not
//part of the actual class that they are grouped with.
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
        

};

//Laser Prototypes
void cleanupLasers();
void deleteLaser(Laser*);
void createEnemyLaser(const int, const int);
void createPlayerLaser(const int, const int);
void checkLasers();
void drawLasers();


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
        double radius;
        Enemy *prev;
        Enemy *next;
        
};

Enemy *headenemy;

//Enemy declarations
void createEnemy();
void deleteEnemy(Enemy*);
void cleanupEnemies();
void checkEnemies();

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
        node->radius = 20;
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


void checkEnemies()
{
    checkCollisions();
  
    Enemy *node = headenemy;

    //update all positions
    //enemies will move like space invaders. Move to the right, drop down,
    //increase speed and reverse.
    while (node) {
        //if at one of the edges, drop down, speed up, reverse direction
        if (node->pos[0] > (g.xres-20) || node->pos[0] < 20)
        {
            node->direction = -node->direction;
            node->pos[1] -= 20;
            node->vel = node->vel * 1.20;
        }
        //Dont think we'll hit any significant floating point precision
        //problems. Keep an eye out for them.
        node->pos[0] += (20 *(node->direction) * (node->vel));
    }    
    
    node = headenemy;
    
    //check if enemies reach player ship
    while (node) {
        if (node->pos[1] <= 50)
        {
            deleteEnemy(node);
            gameover = True;
            break;
        }
    node = node->next;
    }

    //add chance of enemies firing a laser



}
    
/*---------END ENEMIES--------*/



/*---------PLAYER SHIP--------*/

//Ship has no health pool, one shot and you're done.
//Toggle the game over variable
class Player {
    public:
        Vec pos;
        double color[3];
        double radius;
        Player() {
            pos[0] = (Flt)(g.xres/2);
            pos[1] = (Flt)(g.yres/8);
            radius = 10.0;
            color[0] = 0.1;
            color[1] = 0.1;
            color[2] = 1.0;
        }
} PShip;
//Dont tie functions to this class, its just for  display and determining
//collisions and player laser spawn locations. Very simple


/*---------END PLAYER SHIP----*/

/*--BEGIN GENERAL FUNCTIONS---*/
void checkCollisions()
{
    Flt xd,yd,distance;
    //go through lasers, check if within area of an enemy if type==0
    Laser *lasers = headlaser;
    Laser *savedLaser;
    Enemy *savedEnemy;

    while (lasers)
    {
        Enemy *enemies = headenemy;
        //if players laser
        if (lasers->type == 1) 
        {
            while (enemies)
            {   //using method from Asteroids framework. Its pretty clever
                xd = lasers->pos[0] - enemies->pos[0];
                yd = lasers->pos[1] - enemies->pos[1];
                distance = (xd*xd + yd*yd);
                savedLaser = lasers->next;
                savedEnemy = enemies->next;
                //if possible, add a hit effect/explosion later
                if (distance < (enemies->radius*enemies->radius))
                {
                    --playerlascount;
                    --enemycount;
                    deleteLaser(lasers);
                    deleteEnemy(enemies);
                    SCORE += 100;
                }
                lasers = savedLaser;
                enemies = savedEnemy;
                continue;

             }
        }
        //if enemy laser
        if (lasers->type == 0)
        {
            xd = lasers->pos[0] - PShip.pos[0];
            yd = lasers->pos[1] - PShip.pos[1];
            distance = (xd*xd + yd*yd);
            if (distance < (PShip.radius*PShip.radius))
            {
                //player is hit, end game.
                gameover = True;
                break;
            }
            lasers = lasers->next;
        }


    }
}


void spawner()
{
   //run random for a chance at spawning an enemy
}
