#include "../include/Game.h"

Game::Game() : scale(150), dir(0), aniwalkr(1), aniwalkl(1), anijumpr(1), 
               aniatk1(1), aniorcr(1), aniorcl(1), anibscr(1), anibscl(1),
               anishamr(1), anishaml(1), aniknir(1), aniknil(1), dsprite(50),
               jumpstate(0), speed(8), bullet1(0), stage(1), enemydefeat(0),
               enemy1pos(1440), enemy1lpos(-500), enemy2pos(1600), enemy2lpos(-700),
               enemy3pos(1440), enemy3lpos(-800), shamanr(1240), shamanl(200),
               stagestart(0), health(5), floor(2), killcount(0), firstrun(0),
               aniboss(1), aniplayer(1), anilaser(1), anirobot(1), anishark(1),
               enemyypos(1500), enemyypos1(1800), enemyypos2(1700), enemyypos3(1600),
               enemyypos4(1900), enemy7pos(150), enemy8pos(300), enemy9pos(600),
               enemy10pos(750), enemy11pos(450), weakspot1(100), weakspot2(600),
               weakspot3(400), weakspot4(800), weakspot5(200), wsstate(1), wsy(1100)
{
    midxt = 300 - scale;
    midxb = 300 + scale;
    midyt = (getmaxy()/2) - scale;
    midyb = (getmaxy()/2) + scale;
    xtb = midxt;
    xbb = midxb;
    bulletreachborder = 0;
    
    // Background borders
    bg1xt = 0;
    bg1xb = getmaxx();
    bg2xt = getmaxx();
    bg2xb = 2 * getmaxx();
    bgyt = 0;
    bgyb = getmaxy();
    
    // Initialize background pointers
    bg1 = nullptr;
    bg2 = nullptr;
    bg3 = nullptr;
    area = 0;
}

void Game::startgame()
{
    cleardevice();
    if (stage < 3) {
        if (firstrun == 0) {
            savebg();
        }
        bgdraw();
        healthsys();

        if (GetAsyncKeyState('D')) {
            run();
            walkr();
            gerakr();
            dir = 0;
        }
        else if (GetAsyncKeyState('A')) {
            run();
            walkl();
            gerakl();
            dir = 1;
        }
        else if (GetAsyncKeyState('E')) {
            atk1();
        }
        else {
            idle();
        }
        firstrun = 1;
    }
    
    if (stage == 3) {
        finalstage();
    }
    
    if (stage == 4) {
        readimagefile("assets/backgrounds/bgend.gif", 0, 0, getmaxx(), getmaxy());
        if (GetAsyncKeyState('D')) {
            run();
            walkr();
            gerakr();
            dir = 0;
        }
        else if (GetAsyncKeyState('A')) {
            run();
            walkl();
            gerakl();
            dir = 1;
        }
        else if (GetAsyncKeyState(VK_ESCAPE)) {
            stage = 5;
        }
        else {
            idle();
        }
    }
    
    if (stage == 5) {
        readimagefile("assets/backgrounds/bgdesu.gif", 0, 0, getmaxx(), getmaxy());
    }
}

void Game::decidefloor()
{
    if (floor == 2) {
        midyt = (getmaxy()/2) - scale;
        midyb = (getmaxy()/2) + scale;
    }
    else if (floor == 1) {
        midyt = midyt - 150;
        midyb = midyb - 150;
    }
    else if (floor == 3) {
        midyt = midyt + 150;
        midyb = midyb + 150;
    }
}

void Game::changefloor()
{
    // Implementation for floor changing
}

void Game::haha()
{
    bg1xt--;
    bg1xb--;
    bg2xt--;
    bg2xb--;
}

void Game::gerakr()
{
    for (int i = 1; i < speed; i++) {
        midxt++;
        midxb++;
    }
    if (midxt > 1290) {
        midxt = -300;
        midxb = 0;
        stage = stage + 1;
    }
}

void Game::gerakl()
{
    for (int i = 1; i < speed; i++) {
        midxt--;
        midxb--;
    }
    if (midxt < -150) {
        midxt = 1290;
        midxb = 1590;
        stage = stage - 1;
        if (stage < 1) {
            midxt = -150;
            midxb = 150;
            stage = 1;
        }
    }
}

void Game::bgline()
{
    line(0, 530, 1440, 530);
    line(0, 715, 1440, 715);
    line(0, 622.5, 1440, 622.5);
    line(0, 807.5, 1440, 807.5);
    line(144, 530, 144, 900);
    line(288, 530, 288, 900);
    line(432, 530, 432, 900);
    line(576, 530, 576, 900);
    line(720, 530, 720, 900);
    line(864, 530, 864, 900);
    line(1008, 530, 1008, 900);
    line(1152, 530, 1152, 900);
    line(1296, 530, 1296, 900);
    line(1440, 530, 1440, 900);
}

void Game::savebg()
{
    readimagefile("assets/backgrounds/newbg1.gif", 0, 0, getmaxx(), getmaxy());
    readimagefile("assets/ui/hud1.gif", 0, 0, getmaxx(), getmaxy());
    area = imagesize(0, 0, getmaxx(), getmaxy());
    bg1 = malloc(area);
    getimage(0, 0, getmaxx(), getmaxy(), bg1);
    cleardevice();
    
    readimagefile("assets/backgrounds/newbg3.gif", 0, 0, getmaxx(), getmaxy());
    readimagefile("assets/ui/hud2.gif", 0, 0, getmaxx(), getmaxy());
    area = imagesize(0, 0, getmaxx(), getmaxy());
    bg2 = malloc(area);
    getimage(0, 0, getmaxx(), getmaxy(), bg2);
    cleardevice();
    
    readimagefile("assets/backgrounds/bg3.gif", 0, 0, getmaxx(), getmaxy());
    readimagefile("assets/ui/hud3.gif", 0, 0, getmaxx(), getmaxy());
    area = imagesize(0, 0, getmaxx(), getmaxy());
    bg3 = malloc(area);
    getimage(0, 0, getmaxx(), getmaxy(), bg3);
    cleardevice();
}

void Game::bgdraw()
{
    if (stage == 1) {
        setbkcolor(MAGENTA);
        setcolor(YELLOW);
        putimage(0, 0, bg1, COPY_PUT);
        if (midxt >= getmaxx()/2) {
            stagestart = 1;
        }

        if (killcount <= 35 && stagestart == 1) {
            enemy1r();
            enemy1l();
        }
        if (killcount >= 17 && killcount <= 35 && stagestart == 1) {
            enemy2l();
            enemy2r();
        }
    }
    else if (stage == 2) {
        setbkcolor(CYAN);
        putimage(0, 0, bg2, COPY_PUT);

        if (midxt >= getmaxx()/2) {
            stagestart = 2;
        }

        if (killcount <= 70 && stagestart == 2) {
            enemy3r();
            enemy3l();
        }
        if (killcount >= 60 && killcount <= 70 && stagestart == 2) {
            enemy4r();
            enemy4l();
        }
    }
    else if (stage == 3) {
        setbkcolor(BLACK);
        putimage(0, 0, bg3, COPY_PUT);
        enemy4();
    }
    setlinestyle(SOLID_LINE, 1, 3);
}

void Game::lockpos()
{
    midxt = getmaxx() - 150;
    midxb = getmaxx() + 150;
}

void Game::idle()
{
    if (dir == 0) {
        readimagefile("assets/characters/idler.gif", midxt, midyt, midxb, midyb);
    }
    if (dir == 1) {
        readimagefile("assets/characters/idlel.gif", midxt, midyt, midxb, midyb);
    }
}

void Game::run()
{
    if (GetAsyncKeyState(VK_SHIFT)) {
        speed = 15;
    }
    else {
        speed = 8;
    }
}

void Game::healthminus()
{
    health = health - 1;
}

void Game::healthplus()
{
    health = health + 1;
}

void Game::healthsys()
{
    if (health >= 1) {
        circle(480, 827, 23);
    }
    if (health >= 2) {
        circle(530, 827, 23);
    }
    if (health >= 3) {
        circle(580, 827, 23);
    }
    if (health >= 4) {
        circle(630, 827, 23);
    }
    if (health == 5) {
        circle(680, 827, 23);
    }
    if (health > 5) {
        health = 5;
    }
}
