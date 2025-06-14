#include "../include/Game.h"

void Game::finalstage()
{
    setcolor(WHITE);
    putimage(0, 0, bg3, COPY_PUT);
    boss();
    weakpoint();
    healthsys();
    enemy7();
    enemy8();
    enemy9();
    enemy10();
    enemy11();

    if (GetAsyncKeyState(' ')) {
        playerlaser();
    }
    else {
        finalplayer();
    }
    if (killcount >= 110) {
        stage = 4;
    }
}

void Game::weakpoint()
{
    if (wsstate == 1) {
        circle(wsy, weakspot1, 50);
        if (GetAsyncKeyState(' ') && playerposy > weakspot1-50 && playerposy < weakspot1+50) {
            wsstate = wsstate + 1;
            killcount = killcount + 1;
            healthplus();
        }
    }
    if (wsstate == 2) {
        circle(wsy, weakspot2, 50);
        if (GetAsyncKeyState(' ') && playerposy > weakspot2-50 && playerposy < weakspot2+50) {
            wsstate = wsstate + 1;
            killcount = killcount + 1;
            healthplus();
        }
    }
    if (wsstate == 3) {
        circle(wsy, weakspot3, 50);
        if (GetAsyncKeyState(' ') && playerposy > weakspot3-50 && playerposy < weakspot3+50) {
            wsstate = wsstate + 1;
            killcount = killcount + 1;
            healthplus();
        }
    }
    if (wsstate == 4) {
        circle(wsy, weakspot4, 50);
        if (GetAsyncKeyState(' ') && playerposy > weakspot4-50 && playerposy < weakspot4+50) {
            wsstate = wsstate + 1;
            killcount = killcount + 1;
            healthplus();
        }
    }
    if (wsstate == 5) {
        circle(wsy, weakspot5, 50);
        if (GetAsyncKeyState(' ') && playerposy > weakspot5-50 && playerposy < weakspot5+50) {
            wsstate = wsstate + 1;
            killcount = killcount + 1;
            healthplus();
        }
    }
    if (wsstate > 5) {
        wsstate = 1;
    }
}
