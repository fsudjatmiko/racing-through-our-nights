#include "../include/Game.h"

void Game::walkr()
{
    if (aniwalkr == 1) {
        readimagefile("assets/characters/walkr_1.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 2) {
        readimagefile("assets/characters/walkr_2.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 3) {
        readimagefile("assets/characters/walkr_3.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 4) {
        readimagefile("assets/characters/walkr_4.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 5) {
        readimagefile("assets/characters/walkr_5.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 6) {
        readimagefile("assets/characters/walkr_6.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 7) {
        readimagefile("assets/characters/walkr_7.gif", midxt, midyt, midxb, midyb);
    }
    else if (aniwalkr == 8) {
        readimagefile("assets/characters/walkr_8.gif", midxt, midyt, midxb, midyb);
    }
    aniwalkr++;
    if (aniwalkr > 8) {
        aniwalkr = 1;
    }
}

void Game::walkl()
{
    if (aniwalkl == 1) {
        readimagefile("assets/characters/walkl_1.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 2) {
        readimagefile("assets/characters/walkl_2.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 3) {
        readimagefile("assets/characters/walkl_3.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 4) {
        readimagefile("assets/characters/walkl_4.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 5) {
        readimagefile("assets/characters/walkl_5.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 6) {
        readimagefile("assets/characters/walkl_6.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 7) {
        readimagefile("assets/characters/walkl_7.gif", midxt, midyt, midxb, midyb);
    }
    if (aniwalkl == 8) {
        readimagefile("assets/characters/walkl_8.gif", midxt, midyt, midxb, midyb);
    }
    aniwalkl++;
    if (aniwalkl > 8) {
        aniwalkl = 1;
    }
}

void Game::jumpr()
{
    if (anijumpr == 1) {
        readimagefile("assets/characters/jumpr_1.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 2) {
        readimagefile("assets/characters/jumpr_2.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 3) {
        readimagefile("assets/characters/jumpr_3.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 4) {
        readimagefile("assets/characters/jumpr_4.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 5) {
        readimagefile("assets/characters/jumpr_5.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 6) {
        readimagefile("assets/characters/jumpr_6.gif", midxt, midyt, midxb, midyb);
    }
    if (anijumpr == 7) {
        readimagefile("assets/characters/jumpr_7.gif", midxt, midyt, midxb, midyb);
    }
    anijumpr++;
    if (anijumpr > 7) {
        anijumpr = 1;
    }
    midyb = midyb - 1;
    midyt = midyt - 1;
    if (midyb <= 200) {
        midyb = (getmaxy()/2) - scale;
        midyt = (getmaxy()/2) - scale;
    }
}

void Game::atk1()
{
    if (dir == 0) {
        if (aniatk1 >= 1 && aniatk1 < 2) {
            readimagefile("assets/characters/atk11.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 2 && aniatk1 < 4) {
            readimagefile("assets/characters/atk12.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 4 && aniatk1 < 6) {
            readimagefile("assets/characters/atk13.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 6 && aniatk1 < 8) {
            readimagefile("assets/characters/atk14.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 8 && aniatk1 < 10) {
            readimagefile("assets/characters/atk15.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 10 && aniatk1 < 12) {
            readimagefile("assets/characters/atk16.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 12 && aniatk1 < 14) {
            readimagefile("assets/characters/atk17.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 14 && aniatk1 < 16) {
            readimagefile("assets/characters/atk18.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 16 && aniatk1 < 18) {
            readimagefile("assets/characters/atk19.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 18 && aniatk1 < 20) {
            readimagefile("assets/characters/atk110.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 20 && aniatk1 < 22) {
            readimagefile("assets/characters/atk111.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 22 && aniatk1 < 24) {
            readimagefile("assets/characters/atk112.gif", midxt, midyt, midxb, midyb);
        }
        aniatk1++;

        if (aniatk1 > 23) {
            aniatk1 = 1;
        }
    }
    
    if (dir == 1) {
        if (aniatk1 >= 1 && aniatk1 < 2) {
            readimagefile("assets/characters/atk21.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 2 && aniatk1 < 4) {
            readimagefile("assets/characters/atk22.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 4 && aniatk1 < 6) {
            readimagefile("assets/characters/atk23.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 6 && aniatk1 < 8) {
            readimagefile("assets/characters/atk24.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 8 && aniatk1 < 10) {
            readimagefile("assets/characters/atk25.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 10 && aniatk1 < 12) {
            readimagefile("assets/characters/atk26.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 12 && aniatk1 < 14) {
            readimagefile("assets/characters/atk27.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 14 && aniatk1 < 16) {
            readimagefile("assets/characters/atk28.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 16 && aniatk1 < 18) {
            readimagefile("assets/characters/atk29.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 18 && aniatk1 < 20) {
            readimagefile("assets/characters/atk210.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 20 && aniatk1 < 22) {
            readimagefile("assets/characters/atk211.gif", midxt, midyt, midxb, midyb);
        }
        if (aniatk1 >= 22 && aniatk1 < 24) {
            readimagefile("assets/characters/atk212.gif", midxt, midyt, midxb, midyb);
        }
        aniatk1++;

        if (aniatk1 > 23) {
            aniatk1 = 1;
        }
    }
}

void Game::finalplayer()
{
    playerposx = 300;
    playerposy = mousey();
    if (aniplayer >= 1 && aniplayer < 4) {
        readimagefile("assets/characters/fly1.gif", playerposx-150, playerposy-150, playerposx+150, playerposy+150);
    }
    if (aniplayer >= 4 && aniplayer < 7) {
        readimagefile("assets/characters/fly2.gif", playerposx-150, playerposy-150, playerposx+150, playerposy+150);
    }
    if (aniplayer >= 7 && aniplayer < 10) {
        readimagefile("assets/characters/fly3.gif", playerposx-150, playerposy-150, playerposx+150, playerposy+150);
    }
    aniplayer++;
    if (aniplayer > 9) {
        aniplayer = 1;
    }
}

void Game::playerlaser()
{
    playerposx = 300;
    playerposy = mousey();
    laserpos = -200;

    readimagefile("assets/characters/shoot1.gif", playerposx-150, playerposy-150, playerposx+150, playerposy+150);
    if (anilaser >= 1 && anilaser < 4) {
        readimagefile("assets/ui/laser1.gif", laserpos, playerposy-150, laserpos+1700, playerposy+150);
    }
    if (anilaser >= 4 && anilaser < 7) {
        readimagefile("assets/ui/laser2.gif", laserpos, playerposy-150, laserpos+1700, playerposy+150);
    }
    if (anilaser >= 7 && anilaser < 10) {
        readimagefile("assets/ui/laser3.gif", laserpos, playerposy-150, laserpos+1700, playerposy+150);
    }
    anilaser++;
    if (anilaser > 9) {
        anilaser = 1;
    }
}
