#include "../include/Game.h"

void Game::enemy1r()
{
    if (aniorcr >= 1 && aniorcr < 4) {
        readimagefile("assets/enemies/orc1r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (aniorcr >= 4 && aniorcr < 7) {
        readimagefile("assets/enemies/orc2r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (aniorcr >= 7 && aniorcr < 10) {
        readimagefile("assets/enemies/orc3r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy1pos = enemy1pos - 10;
    }
    aniorcr++;
    if (aniorcr > 9) {
        aniorcr = 1;
    }
    enemyrangehit();
}

void Game::enemy1l()
{
    if (aniorcl >= 1 && aniorcl < 4) {
        readimagefile("assets/enemies/orc1l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (aniorcl >= 4 && aniorcl < 7) {
        readimagefile("assets/enemies/orc2l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (aniorcl >= 7 && aniorcl < 10) {
        readimagefile("assets/enemies/orc3l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy1lpos = enemy1lpos + 10;
    }
    aniorcl++;
    if (aniorcl > 9) {
        aniorcl = 1;
    }
    enemyrangehit();
}

void Game::enemy2l()
{
    if (anibscl >= 1 && anibscl < 4) {
        readimagefile("assets/enemies/bsc1l.gif", enemy2lpos-150, midyt, enemy2lpos+150, midyb);
    }
    if (anibscl >= 4 && anibscl < 7) {
        readimagefile("assets/enemies/bsc2l.gif", enemy2lpos-150, midyt, enemy2lpos+150, midyb);
    }
    if (anibscl >= 7 && anibscl < 10) {
        readimagefile("assets/enemies/bsc3l.gif", enemy2lpos-150, midyt, enemy2lpos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy2lpos = enemy2lpos + 17;
    }
    anibscl++;
    if (anibscl > 9) {
        anibscl = 1;
    }
    enemyrangehit();
}

void Game::enemy2r()
{
    if (anibscr >= 1 && anibscr < 4) {
        readimagefile("assets/enemies/bsc1r.gif", enemy2pos-150, midyt, enemy2pos+150, midyb);
    }
    if (anibscr >= 4 && anibscr < 7) {
        readimagefile("assets/enemies/bsc2r.gif", enemy2pos-150, midyt, enemy2pos+150, midyb);
    }
    if (anibscr >= 7 && anibscr < 10) {
        readimagefile("assets/enemies/bsc3r.gif", enemy2pos-150, midyt, enemy2pos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy2pos = enemy2pos - 17;
    }
    anibscr++;
    if (anibscr > 9) {
        anibscr = 1;
    }
    enemyrangehit();
}

void Game::enemy3r()
{
    if (anishamr >= 1 && anishamr < 4) {
        readimagefile("assets/enemies/sham1r.gif", enemy3pos-150, midyt, enemy3pos+150, midyb);
    }
    if (anishamr >= 4 && anishamr < 7) {
        readimagefile("assets/enemies/sham2r.gif", enemy3pos-150, midyt, enemy3pos+150, midyb);
    }
    if (anishamr >= 7 && anishamr < 10) {
        readimagefile("assets/enemies/sham3r.gif", enemy3pos-150, midyt, enemy3pos+150, midyb);
    }
    if (anishamr == 12) {
        readimagefile("assets/enemies/sham6r.gif", enemy3pos-150, midyt, enemy3pos+150, midyb);
    }
    anishamr++;
    
    if (enemydefeat == 0) {
        if (enemy3pos <= 1240) {
            enemy3pos == 1240;
            anishamr = 12;
        }
        else {
            enemy3pos = enemy3pos - 10;
        }
    }

    if (anishamr > 9 && anishamr < 11) {
        anishamr = 1;
    }
    if (anishamr == 12) {
        readimagefile("assets/enemies/shambul.gif", shamanr-150, midyt, shamanr+150, midyb);
        if (enemydefeat == 0) {
            shamanr = shamanr - 18;
            if (shamanr <= midxb - 30) {
                enemy3pos = 1340;
                anishamr = 1;
                shamanr = 1240;
                if (GetAsyncKeyState('E')) {
                    killcount = killcount + 1;
                }
                else {
                    healthminus();
                }
            }
        }
        enemyrangehit();
    }
}

void Game::enemy3l()
{
    if (anishaml >= 1 && anishaml < 4) {
        readimagefile("assets/enemies/sham1l.gif", enemy3lpos-150, midyt, enemy3lpos+150, midyb);
    }
    if (anishaml >= 4 && anishaml < 7) {
        readimagefile("assets/enemies/sham2l.gif", enemy3lpos-150, midyt, enemy3lpos+150, midyb);
    }
    if (anishaml >= 7 && anishaml < 10) {
        readimagefile("assets/enemies/sham3l.gif", enemy3lpos-150, midyt, enemy3lpos+150, midyb);
    }
    if (anishaml == 12) {
        readimagefile("assets/enemies/sham6l.gif", enemy3lpos-150, midyt, enemy3lpos+150, midyb);
    }
    anishaml++;
    
    if (enemydefeat == 0) {
        if (enemy3lpos >= 200) {
            enemy3lpos == 200;
            anishaml = 12;
        }
        else {
            enemy3lpos = enemy3lpos + 10;
        }
    }

    if (anishaml > 9 && anishaml < 11) {
        anishaml = 1;
    }
    if (anishaml == 12) {
        readimagefile("assets/enemies/shambula.gif", shamanl-150, midyt, shamanl+150, midyb);
        if (enemydefeat == 0) {
            shamanl = shamanl + 18;
            if (shamanl >= midxt + 50) {
                enemy3lpos = 100;
                anishaml = 1;
                shamanl = 200;
                if (GetAsyncKeyState('E')) {
                    healthplus();
                    killcount = killcount + 1;
                }
                else {
                    healthminus();
                }
            }
        }
    }
}

void Game::enemy4r()
{
    if (aniorcr >= 1 && aniorcr < 4) {
        readimagefile("assets/enemies/kni1r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (aniorcr >= 4 && aniorcr < 7) {
        readimagefile("assets/enemies/kni2r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (aniorcr >= 7 && aniorcr < 10) {
        readimagefile("assets/enemies/kni3r.gif", enemy1pos-150, midyt, enemy1pos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy1pos = enemy1pos - 20;
    }
    aniorcr++;
    if (aniorcr > 9) {
        aniorcr = 1;
    }
    enemyrangehit();
}

void Game::enemy4l()
{
    if (aniorcl >= 1 && aniorcl < 4) {
        readimagefile("assets/enemies/kni1l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (aniorcl >= 4 && aniorcl < 7) {
        readimagefile("assets/enemies/kni2l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (aniorcl >= 7 && aniorcl < 10) {
        readimagefile("assets/enemies/kni3l.gif", enemy1lpos-150, midyt, enemy1lpos+150, midyb);
    }
    if (enemydefeat == 0) {
        enemy1lpos = enemy1lpos + 20;
    }
    aniorcl++;
    if (aniorcl > 9) {
        aniorcl = 1;
    }
    enemyrangehit();
}

void Game::enemy4()
{
    circle(enemy1pos, 300, 150);
    enemyrangehit();
}

void Game::boss()
{
    if (aniboss >= 1 && aniboss < 4) {
        readimagefile("assets/enemies/boss1.gif", 500, -200, 1900, 1200);
    }
    if (aniboss >= 4 && aniboss < 7) {
        readimagefile("assets/enemies/boss2.gif", 500, -200, 1900, 1200);
    }
    if (aniboss >= 7 && aniboss < 10) {
        readimagefile("assets/enemies/boss3.gif", 500, -200, 1900, 1200);
    }
    if (aniboss >= 10 && aniboss < 13) {
        readimagefile("assets/enemies/boss4.gif", 500, -200, 1900, 1200);
    }
    if (aniboss >= 13 && aniboss < 16) {
        readimagefile("assets/enemies/boss5.gif", 500, -200, 1900, 1200);
    }
    aniboss++;
    if (aniboss > 15) {
        aniboss = 1;
    }
}

void Game::printshark(int x, int y)
{
    if (anishark == 1) {
        readimagefile("assets/enemies/shark1.gif", x-150, y-150, x+150, y+150);
    }
    if (anishark == 2) {
        readimagefile("assets/enemies/shark2.gif", x-150, y-150, x+150, y+150);
    }
    if (anishark == 3) {
        readimagefile("assets/enemies/shark3.gif", x-150, y-150, x+150, y+150);
    }
    if (anishark == 4) {
        readimagefile("assets/enemies/shark4.gif", x-150, y-150, x+150, y+150);
    }
    if (anishark == 5) {
        readimagefile("assets/enemies/shark5.gif", x-150, y-150, x+150, y+150);
    }
    if (anishark == 6) {
        readimagefile("assets/enemies/shark6.gif", x-150, y-150, x+150, y+150);
    }
    anishark++;
    if (anishark > 6) {
        anishark = 1;
    }
}

void Game::checkdamage(int x, int y)
{
    if (x < playerposx && y >= playerposy-5 && y <= playerposy+5)
        healthminus();
}

void Game::enemy7()
{
    printshark(enemyypos, enemy7pos);
    checkdamage(enemyypos, enemy7pos);
    enemyypos = enemyypos - 22;
    if (enemyypos < 0) {
        enemyypos = 1500;
    }
}

void Game::enemy8()
{
    printshark(enemyypos1, enemy8pos);
    checkdamage(enemyypos1, enemy8pos);
    enemyypos1 = enemyypos1 - 22;
    if (enemyypos1 < 0) {
        enemyypos1 = 1900;
    }
}

void Game::enemy9()
{
    printshark(enemyypos2, enemy9pos);
    checkdamage(enemyypos2, enemy9pos);
    enemyypos2 = enemyypos2 - 22;
    if (enemyypos2 < 0) {
        enemyypos2 = 1800;
    }
}

void Game::enemy10()
{
    printshark(enemyypos3, enemy10pos);
    checkdamage(enemyypos3, enemy10pos);
    enemyypos3 = enemyypos3 - 22;
    if (enemyypos3 < 0) {
        enemyypos3 = 1700;
    }
}

void Game::enemy11()
{
    printshark(enemyypos4, enemy11pos);
    checkdamage(enemyypos4, enemy11pos);
    enemyypos4 = enemyypos4 - 22;
    if (enemyypos4 < 0) {
        enemyypos4 = 1000;
    }
}

void Game::enemyrangehit()
{
    int enemyranger = midxb;
    int enemyrangel = midxt;
    
    if(enemy1pos <= enemyranger && enemy1pos >= enemyrangel && GetAsyncKeyState('E') && dir == 0) {
        enemy1pos = 2000;
        killcount = killcount + 1;
    }
    if(enemy1pos <= -100) {
        enemy1pos = 2000;
        healthminus();
    }
    if(enemy1lpos <= enemyranger && enemy1lpos >= enemyrangel && GetAsyncKeyState('E') && dir == 1) {
        enemy1lpos = -1000;
        killcount = killcount + 1;
    }
    if(enemy1lpos >= 1540) {
        enemy1lpos = -1000;
        healthminus();
    }
    if(enemy2pos <= enemyranger && enemy2pos >= enemyrangel && GetAsyncKeyState('E') && dir == 0) {
        enemy2pos = 2000;
        killcount = killcount + 1;
        healthplus();
    }
    if(enemy2pos <= -100) {
        enemy2pos = 2000;
        healthminus();
    }
    if(enemy2lpos <= enemyranger && enemy2lpos >= enemyrangel && GetAsyncKeyState('E') && dir == 1) {
        enemy2lpos = -1000;
        killcount = killcount + 1;
        healthplus();
    }
    if(enemy2lpos >= 1540) {
        enemy2lpos = -1000;
        healthminus();
    }
}
