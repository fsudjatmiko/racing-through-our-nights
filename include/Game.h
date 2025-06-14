#ifndef GAME_H
#define GAME_H

#include <cstdlib>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <winuser.h>
#include <windows.h>
#include <mmsystem.h>

class Game
{
public:
    // Constructor
    Game();
    
    // Game dimensions and positioning
    int scale;
    int midxt, midxb, midyt, midyb;
    int dir;
    
    // Animation counters
    int aniwalkr, aniwalkl, anijumpr, aniatk1;
    int aniorcr, aniorcl, anibscr, anibscl;
    int anishamr, anishaml, aniknir, aniknil;
    int aniboss, aniplayer, anilaser, anirobot, anishark;
    
    // Game state variables
    int dsprite, jumpstate, speed, bullet1;
    int stage, enemydefeat, stagestart, health, floor;
    int killcount, firstrun;
    
    // Enemy positions
    int enemy1pos, enemy1lpos, enemy2pos, enemy2lpos;
    int enemy3pos, enemy3lpos, shamanr, shamanl;
    int enemyypos, enemyypos1, enemyypos2, enemyypos3, enemyypos4;
    int enemy7pos, enemy8pos, enemy9pos, enemy10pos, enemy11pos;
    
    // Player and game elements
    int xtb, xbb, bulletreachborder;
    int bg1xt, bg1xb, bg2xt, bg2xb, bgyt, bgyb;
    int playerposx, playerposy, laserpos;
    int weakspot1, weakspot2, weakspot3, weakspot4, weakspot5;
    int wsstate, wsy;
    
    // Background storage
    void *bg1, *bg2, *bg3;
    unsigned int area;
    
    // Main game functions
    void startgame();
    void finalstage();
    
    // Movement and positioning
    void decidefloor();
    void changefloor();
    void gerakr();
    void gerakl();
    void lockpos();
    
    // Background and graphics
    void savebg();
    void bgdraw();
    void bgline();
    void haha();
    
    // Player actions
    void idle();
    void run();
    void walkr();
    void walkl();
    void jumpr();
    void atk1();
    void finalplayer();
    void playerlaser();
    
    // Enemy functions
    void enemy1r();
    void enemy1l();
    void enemy2r();
    void enemy2l();
    void enemy3r();
    void enemy3l();
    void enemy4r();
    void enemy4l();
    void enemy4();
    void enemy7();
    void enemy8();
    void enemy9();
    void enemy10();
    void enemy11();
    void boss();
    void printshark(int x, int y);
    void checkdamage(int x, int y);
    
    // Combat and health
    void enemyrangehit();
    void healthminus();
    void healthplus();
    void healthsys();
    void weakpoint();
};

#endif // GAME_H
