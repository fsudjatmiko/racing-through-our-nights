#include <cstdlib>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <winuser.h>
#include <windows.h>
#include <mmsystem.h>

class game
{
public:
    int scale = 150;
    int midxt = 300-scale;
    int midxb = 300+scale;
    int midyt = (getmaxy()/2)-scale;
    int midyb = (getmaxy()/2)+scale;
    int dir = 0;

    int aniwalkr = 1;
    int aniwalkl = 1;
    int anijumpr = 1;
    int aniatk1 = 1;
    int aniorcr = 1;
    int aniorcl = 1;
    int anibscr = 1;
    int anibscl = 1;
    int anishamr = 1;
    int anishaml = 1;
    int aniknir=1;
    int aniknil=1;

    int dsprite = 50;
    int jumpstate = 0;

    int speed = 8;

    int bullet1 = 0;

    int stage = 1;
    int enemydefeat = 0;
    int enemy1pos = 1440;
    int enemy1lpos = -500;
    int enemy2pos = 1600;
    int enemy2lpos = -700;
    int enemy3pos = 1440;
    int enemy3lpos = -800;
    int shamanr = 1240;
    int shamanl = 200;
    int stagestart = 0;

    int health = 5;

    int floor = 2;

    int xtb = midxt;
    int xbb = midxb;
    int bulletreachborder = 0;

    //bg 1 borders x
    int bg1xt = 0;
    int bg1xb = getmaxx();

    //bg 2 borders x
    int bg2xt = getmaxx();
    int bg2xb = 2*getmaxx();

    //bg borders y
    int bgyt = 0;
    int bgyb = getmaxy();

    int killcount = 0;
    int firstrun = 0;
    void startgame()
    {
        cleardevice();
        if (stage<3){
        if (firstrun==0)
        {
            savebg();
        }
        bgdraw();
        healthsys();

        if (GetAsyncKeyState('D'))
        {
            run();
            walkr();
            gerakr();
            dir = 0;
        }
        else if (GetAsyncKeyState('A'))
        {
            run();
            walkl();
            gerakl();
            dir = 1;
        }
        else if (GetAsyncKeyState('E'))
        {
            atk1();
            //gerakr();
        }

        else
        {
            idle();
        }
        firstrun = 1;
        }
        if (stage == 3)
        {
            finalstage();
        }
        if (stage == 4)
        {
            readimagefile("bgend.gif",0,0,getmaxx(),getmaxy());
            if (GetAsyncKeyState('D'))
            {
                run();
                walkr();
                gerakr();
                dir = 0;
            }
            else if (GetAsyncKeyState('A'))
            {
                run();
                walkl();
                gerakl();
                dir = 1;
            }
            else if (GetAsyncKeyState(VK_ESCAPE))
            {
                stage = 5;
            }
            else
            {
                idle();
            }
        }
        if (stage == 5)
        {
            readimagefile("bgdesu.gif",0,0,getmaxx(),getmaxy());
        }
    }


    void decidefloor()
    {
        if (floor == 2)
        {
            midyt = (getmaxy()/2)-scale;
            midyb = (getmaxy()/2)+scale;
        }
        else if (floor == 1)
        {
            midyt = midyt-150;
            midyb = midyb-150;
        }
        else if (floor == 3)
        {
            midyt = midyt+150;
            midyb = midyb+ 150;
        }
    }
    void changefloor()
    {

    }
    void haha()
    {
            bg1xt--;
            bg1xb--;
            bg2xt--;
            bg2xb--;
    }
    void gerakr()
    {
        for (int i=1;i<speed;i++)
        {
            midxt++;
            midxb++;
        }
        if (midxt > 1290)
        {
            midxt = -300;
            midxb = 0;
            stage=stage+1;
        }
    }
    void gerakl()
    {
        for (int i=1;i<speed;i++)
        {
            midxt--;
            midxb--;
        }
        if (midxt < -150)
        {
            midxt = 1290;
            midxb = 1590;
            stage=stage-1;
            if (stage < 1)
            {
                midxt = -150;
                midxb = 150;
                stage = 1;
            }
        }
    }
    void bgline()
    {
        line(0,530,1440,530);
        line(0,715,1440,715);
        line(0,622.5,1440,622.5);
        line(0,807.5,1440,807.5);
        line (144,530,144,900);
        line (288,530,288,900);
        line (432,530,432,900);
        line (576,530,576,900);
        line (720,530,720,900);
        line (864,530,864,900);
        line (1008,530,1008,900);
        line (1152,530,1152,900);
        line (1296,530,1296,900);
        line (1440,530,1440,900);
    }
    void *bg1,*bg2,*bg3;
    unsigned int area;
    void savebg()
    {
        readimagefile("newbg1.gif",0,0,getmaxx(),getmaxy());
        readimagefile("hud1.gif",0,0,getmaxx(),getmaxy());
        area  = imagesize(0,0,getmaxx(),getmaxy());
        bg1 = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),bg1);
        cleardevice();
        readimagefile("newbg3.gif",0,0,getmaxx(),getmaxy());
        readimagefile("hud2.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        bg2 = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),bg2);
        cleardevice();
        readimagefile("bg3.gif",0,0,getmaxx(),getmaxy());
        readimagefile("hud3.gif",0,0,getmaxx(),getmaxy());
        area = imagesize(0,0,getmaxx(),getmaxy());
        bg3 = malloc(area);
        getimage(0,0,getmaxx(),getmaxy(),bg3);
        cleardevice();
    }
    void bgdraw()
    {
        if (stage == 1)
        {
             setbkcolor(MAGENTA);
             setcolor(YELLOW);
             putimage(0,0,bg1,COPY_PUT);
             if (midxt >= getmaxx()/2)
             {
                 stagestart = 1;
             }

            if (killcount <= 35 && stagestart == 1)
            {
             enemy1r();
             enemy1l();
            }
            if (killcount >= 17 && killcount <= 35 && stagestart == 1)
            {
             enemy2l();
             enemy2r();
            }
        }
        else if (stage == 2)
        {
             setbkcolor(CYAN);
             //setcolor(LIGHTRED);
             putimage(0,0,bg2,COPY_PUT);

              if (midxt >= getmaxx()/2)
             {
                 stagestart = 2;
             }

            if (killcount <= 70 && stagestart == 2)
            {
             enemy3r();
             enemy3l();
            }
            if (killcount >= 60 && killcount <= 70 && stagestart == 2)
            {
             enemy4r();
             enemy4l();
            }
        }
        else if (stage == 3)
        {
             setbkcolor(BLACK);
             //setcolor(WHITE);
             putimage(0,0,bg3,COPY_PUT);
             enemy4();
        }
        setlinestyle(SOLID_LINE, 1, 3);
        //bgline();
    }
    void lockpos()
    {
        midxt = getmaxx()-150;
        midxb = getmaxx()+150;
    }
    void enemy3r()
    {
        if (anishamr >= 1 && anishamr <4)
        {
            readimagefile("sham1r.gif",enemy3pos-150,midyt,enemy3pos+150,midyb);
        }
        if (anishamr >= 4 && anishamr <7)
        {
            readimagefile("sham2r.gif",enemy3pos-150,midyt,enemy3pos+150,midyb);
        }
        if (anishamr >= 7 && anishamr <10)
        {
            readimagefile("sham3r.gif",enemy3pos-150,midyt,enemy3pos+150,midyb);
        }
        if (anishamr == 12)
        {
            readimagefile("sham6r.gif",enemy3pos-150,midyt,enemy3pos+150,midyb);
        }
        anishamr++;
        //circle(enemy3pos,450,50);
        if (enemydefeat == 0)
        {
            if (enemy3pos <= 1240)
            {
                enemy3pos == 1240;
                anishamr = 12;
            }
            else
            {
                enemy3pos=enemy3pos-10;
            }
        }

        if (anishamr > 9 && anishamr < 11)
        {
            anishamr = 1;
        }
        if (anishamr == 12)
        {
            readimagefile("shambul.gif",shamanr-150,midyt,shamanr+150,midyb);
            if (enemydefeat == 0)
            {
            shamanr=shamanr-18;
            if (shamanr <= midxb-30)
            {
                enemy3pos = 1340;
                anishamr = 1;
                shamanr = 1240;
                if (GetAsyncKeyState('E'))
                {
                    //healthplus();
                    killcount=killcount+1;
                }
                else
                {
                    healthminus();
                }
            }
            }
            enemyrangehit();
        }
    }
    void enemy3l()
    {
        if (anishaml >= 1 && anishaml <4)
        {
            readimagefile("sham1l.gif",enemy3lpos-150,midyt,enemy3lpos+150,midyb);
        }
        if (anishaml >= 4 && anishaml <7)
        {
            readimagefile("sham2l.gif",enemy3lpos-150,midyt,enemy3lpos+150,midyb);
        }
        if (anishaml >= 7 && anishaml <10)
        {
            readimagefile("sham3l.gif",enemy3lpos-150,midyt,enemy3lpos+150,midyb);
        }
        if (anishaml == 12)
        {
            readimagefile("sham6l.gif",enemy3lpos-150,midyt,enemy3lpos+150,midyb);
        }
        //circle(enemy3pos,450,50);
        anishaml++;
        if (enemydefeat == 0)
        {
            if (enemy3lpos >= 200)
            {
                enemy3lpos == 200;
                anishaml = 12;
            }
            else
            {
                enemy3lpos=enemy3lpos+10;
            }
        }

        if (anishaml > 9 && anishaml < 11)
        {
            anishaml = 1;
        }
        if (anishaml == 12)
        {
            readimagefile("shambula.gif",shamanl-150,midyt,shamanl+150,midyb);
            if (enemydefeat == 0)
            {
            shamanl=shamanl+18;
            if (shamanl >= midxt+50)
            {
                enemy3lpos = 100;
                anishaml = 1;
                shamanl = 200;
                if (GetAsyncKeyState('E'))
                {
                    healthplus();
                    killcount=killcount+1;
                }
                else
                {
                    healthminus();
                }
            }
            }
        }
    }
    void enemy4r()
    {
        if (aniorcr >= 1 && aniorcr <4)
        {
            readimagefile("kni1r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        if (aniorcr >= 4 && aniorcr <7)
        {
            readimagefile("kni2r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        if (aniorcr >= 7 && aniorcr <10)
        {
            readimagefile("kni3r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        //circle(enemy1pos,450,50);
        if (enemydefeat == 0)
        {
            enemy1pos=enemy1pos-20;
        }
        aniorcr++;
        if (aniorcr > 9)
        {
            aniorcr = 1;
        }
        enemyrangehit();
    }
    void enemy4l()
    {
        if (aniorcl >= 1 && aniorcl <4)
        {
            readimagefile("kni1l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        if (aniorcl >= 4 && aniorcl <7)
        {
            readimagefile("kni2l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        if (aniorcl >= 7 && aniorcl <10)
        {
            readimagefile("kni3l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        //circle(enemy1pos,450,50);
        if (enemydefeat == 0)
        {
            enemy1lpos=enemy1lpos+20;
        }
        aniorcl++;
        if (aniorcl > 9)
        {
            aniorcl = 1;
        }
        enemyrangehit();
    }
    void enemy4()
    {
        circle(enemy1pos,300,150);
        /*if (enemydefeat == 0 && enemy1pos > 0)
        {
            enemy1pos=enemy1pos-5;
        }*/
        enemyrangehit();
    }
    void enemy1r()
    {
        if (aniorcr >= 1 && aniorcr <4)
        {
            readimagefile("orc1r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        if (aniorcr >= 4 && aniorcr <7)
        {
            readimagefile("orc2r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        if (aniorcr >= 7 && aniorcr <10)
        {
            readimagefile("orc3r.gif",enemy1pos-150,midyt,enemy1pos+150,midyb);
        }
        //circle(enemy1pos,450,50);
        if (enemydefeat == 0)
        {
            enemy1pos=enemy1pos-10;
        }
        aniorcr++;
        if (aniorcr > 9)
        {
            aniorcr = 1;
        }
        enemyrangehit();
    }
    void enemy1l()
    {
        if (aniorcl >= 1 && aniorcl <4)
        {
            readimagefile("orc1l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        if (aniorcl >= 4 && aniorcl <7)
        {
            readimagefile("orc2l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        if (aniorcl >= 7 && aniorcl <10)
        {
            readimagefile("orc3l.gif",enemy1lpos-150,midyt,enemy1lpos+150,midyb);
        }
        //circle(enemy1pos,450,50);
        if (enemydefeat == 0)
        {
            enemy1lpos=enemy1lpos+10;
        }
        aniorcl++;
        if (aniorcl > 9)
        {
            aniorcl = 1;
        }
        enemyrangehit();
    }
    void enemy2l()
    {
        if (anibscl >= 1 && anibscl <4)
        {
            readimagefile("bsc1l.gif",enemy2lpos-150,midyt,enemy2lpos+150,midyb);
        }
        if (anibscl >= 4 && anibscl <7)
        {
            readimagefile("bsc2l.gif",enemy2lpos-150,midyt,enemy2lpos+150,midyb);
        }
        if (anibscl >= 7 && anibscl <10)
        {
            readimagefile("bsc3l.gif",enemy2lpos-150,midyt,enemy2lpos+150,midyb);
        }
        //circle(enemy2pos,450,50);
        if (enemydefeat == 0)
        {
            enemy2lpos=enemy2lpos+17;
        }
        anibscl++;
        if (anibscl > 9)
        {
            anibscl = 1;
        }
        enemyrangehit();
    }

    void enemy2r()
    {
        if (anibscr >= 1 && anibscr <4)
        {
            readimagefile("bsc1r.gif",enemy2pos-150,midyt,enemy2pos+150,midyb);
        }
        if (anibscr >= 4 && anibscr <7)
        {
            readimagefile("bsc2r.gif",enemy2pos-150,midyt,enemy2pos+150,midyb);
        }
        if (anibscr >= 7 && anibscr <10)
        {
            readimagefile("bsc3r.gif",enemy2pos-150,midyt,enemy2pos+150,midyb);
        }
        //circle(enemy2pos,450,50);
        if (enemydefeat == 0)
        {
            enemy2pos=enemy2pos-17;
        }
        anibscr++;
        if (anibscr > 9)
        {
            anibscr = 1;
        }
        enemyrangehit();
    }

    void enemyrangehit()
    {
        int enemyranger = midxb;
        int enemyrangel = midxt;
        if(enemy1pos<= enemyranger && enemy1pos >= enemyrangel && GetAsyncKeyState('E') && dir == 0)
        {
            enemy1pos= 2000;
            killcount=killcount+1;
            //healthplus();
        }
        if(enemy1pos <= -100)
        {
            enemy1pos= 2000;
            healthminus();
        }
        if(enemy1lpos<= enemyranger && enemy1lpos >= enemyrangel && GetAsyncKeyState('E') && dir == 1)
        {
            enemy1lpos= -1000;
            killcount=killcount+1;
            //sudahhealthplus();
        }
        if(enemy1lpos >= 1540)
        {
            enemy1lpos= -1000;
            healthminus();
        }
         if(enemy2pos<= enemyranger && enemy2pos >= enemyrangel && GetAsyncKeyState('E') && dir == 0)
        {
            enemy2pos= 2000;
            killcount=killcount+1;
            healthplus();
        }
        if(enemy2pos <= -100)
        {
            enemy2pos= 2000;
            healthminus();
        }
        if(enemy2lpos<= enemyranger && enemy2lpos >= enemyrangel && GetAsyncKeyState('E') && dir == 1)
        {
            enemy2lpos= -1000;
            killcount=killcount+1;
            healthplus();
        }
        if(enemy2lpos >= 1540)
        {
            enemy2lpos= -1000;
            healthminus();
        }
    }
    void healthminus()
    {
        health=health-1;
    }
    void healthplus()
    {
        health=health+1;
    }
    void healthsys()
    {
        if (health >= 1)
        {
            circle(480,827,23);
        }
         if (health >= 2)
        {
            circle(530,827,23);
        }
        if (health >= 3)
        {
            circle(580,827,23);
        }
        if (health >= 4)
        {
            circle(630,827,23);
        }
        if (health == 5)
        {
            circle(680,827,23);
        }
        if (health>5)
        {
            health =5;
        }
    }
    void idle()
    {
        if (dir == 0)
        {
            readimagefile("idler.gif",midxt,midyt,midxb,midyb);
        }
         if (dir ==1)
        {
            readimagefile("idlel.gif",midxt,midyt,midxb,midyb);
        }
    }

    void run()
    {
        if (GetAsyncKeyState(VK_SHIFT))
        {
            speed = 15;
        }
        else
        {
            speed = 8;
        }
    }

    void atk1()
    {
            if (dir==0)
            {
                if (aniatk1 >= 1 && aniatk1 <2)
                {
                    readimagefile("atk11.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 2 && aniatk1 <4)
                {
                    readimagefile("atk12.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 4 && aniatk1 <6)
                {
                    readimagefile("atk13.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 6 && aniatk1 <8)
                {
                    readimagefile("atk14.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 8 && aniatk1 <10)
                {
                    readimagefile("atk15.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 10 && aniatk1 <12)
                {
                    readimagefile("atk16.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 12 && aniatk1 <14)
                {
                    readimagefile("atk17.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 14 && aniatk1 <16)
                {
                    readimagefile("atk18.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 16 && aniatk1 <18)
                {
                    readimagefile("atk19.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 18 && aniatk1 <20)
                {
                    readimagefile("atk110.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 20 && aniatk1 <22)
                {
                    readimagefile("atk111.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 22 && aniatk1 <24)
                {
                    readimagefile("atk112.gif",midxt,midyt,midxb,midyb);
                }
                aniatk1++;

                if (aniatk1 > 23)
                {
                    aniatk1 = 1;
                }
            }
            //delay(100);
            if (dir==1)
            {
                if (aniatk1 >= 1 && aniatk1 <2)
                {
                    readimagefile("atk21.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 2 && aniatk1 <4)
                {
                    readimagefile("atk22.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 4 && aniatk1 <6)
                {
                    readimagefile("atk23.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 6 && aniatk1 <8)
                {
                    readimagefile("atk24.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 8 && aniatk1 <10)
                {
                    readimagefile("atk25.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 10 && aniatk1 <12)
                {
                    readimagefile("atk26.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 12 && aniatk1 <14)
                {
                    readimagefile("atk27.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 14 && aniatk1 <16)
                {
                    readimagefile("atk28.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 16 && aniatk1 <18)
                {
                    readimagefile("atk29.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 18 && aniatk1 <20)
                {
                    readimagefile("atk210.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 20 && aniatk1 <22)
                {
                    readimagefile("atk211.gif",midxt,midyt,midxb,midyb);
                }
                if (aniatk1 >= 22 && aniatk1 <24)
                {
                    readimagefile("atk212.gif",midxt,midyt,midxb,midyb);
                }
                aniatk1++;

                if (aniatk1 > 23)
                {
                    aniatk1 = 1;
                }
            }
    }

    void jumpr()
    {
            if (anijumpr == 1)
            {
            readimagefile("jumpr_1.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 2)
            {
            readimagefile("jumpr_2.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 3)
            {
            readimagefile("jumpr_3.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 4)
            {
            readimagefile("jumpr_4.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 5)
            {
            readimagefile("jumpr_5.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 6)
            {
            readimagefile("jumpr_6.gif",midxt,midyt,midxb,midyb);
            }
            if (anijumpr == 7)
            {
            readimagefile("jumpr_7.gif",midxt,midyt,midxb,midyb);
            }
            anijumpr++;
            if (anijumpr >7)
            {
            anijumpr = 1;
            }
            midyb=midyb-1;
            midyt=midyt-1;
            if (midyb<=200)
            {
                midyb = (getmaxy()/2)-scale;
                midyt = (getmaxy()/2)-scale;
            }
    }

    //jalan ke kanan
    void walkr()
    {
        if (aniwalkr == 1)
        {
            readimagefile("walkr_1.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 2)
        {
            readimagefile("walkr_2.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 3)
        {
            readimagefile("walkr_3.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 4)
        {
            readimagefile("walkr_4.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 5)
        {
            readimagefile("walkr_5.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 6)
        {
            readimagefile("walkr_6.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 7)
        {
            readimagefile("walkr_7.gif",midxt,midyt,midxb,midyb);
        }
        else if (aniwalkr == 8)
        {
            readimagefile("walkr_8.gif",midxt,midyt,midxb,midyb);
        }
        aniwalkr++;
        if (aniwalkr > 8)
        {
            aniwalkr = 1;
        }
        //delay(dsprite);
    }

    //jalan ke kiri
    void walkl()
    {
        if (aniwalkl == 1)
        {
            readimagefile("walkl_1.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 2)
        {
            readimagefile("walkl_2.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 3)
        {
            readimagefile("walkl_3.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 4)
        {
            readimagefile("walkl_4.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 5)
        {
            readimagefile("walkl_5.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 6)
        {
            readimagefile("walkl_6.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 7)
        {
            readimagefile("walkl_7.gif",midxt,midyt,midxb,midyb);
        }
        if (aniwalkl == 8)
        {
            readimagefile("walkl_8.gif",midxt,midyt,midxb,midyb);
        }
        aniwalkl++;
        if (aniwalkl > 8)
        {
            aniwalkl = 1;
        }
        //delay(dsprite);
    }

    int aniboss = 1;
    void boss()
    {
        if (aniboss >=1 && aniboss <4)
        {
            readimagefile("boss1.gif",500,-200,1900,1200);
        }
        if (aniboss >=4 && aniboss <7)
        {
            readimagefile("boss2.gif",500,-200,1900,1200);
        }
        if (aniboss >=7&& aniboss <10)
        {
            readimagefile("boss3.gif",500,-200,1900,1200);
        }
        if (aniboss >=10 && aniboss <13)
        {
            readimagefile("boss4.gif",500,-200,1900,1200);
        }
        if (aniboss >=13 && aniboss <16)
        {
            readimagefile("boss5.gif",500,-200,1900,1200);
        }
        aniboss++;
        if (aniboss>15)
        {
            aniboss = 1;
        }
    }
    int playerposx;
    int playerposy;
    int aniplayer = 1;
    int anilaser = 1;
    void finalplayer()
    {
        playerposx = 300;
        playerposy = mousey();
        if (aniplayer >= 1 && aniplayer <4)
        {
            readimagefile("fly1.gif",playerposx-150,playerposy-150,playerposx+150,playerposy+150);
        }
        if (aniplayer >= 4 && aniplayer <7)
        {
            readimagefile("fly2.gif",playerposx-150,playerposy-150,playerposx+150,playerposy+150);
        }
        if (aniplayer >= 7 && aniplayer <10)
        {
            readimagefile("fly3.gif",playerposx-150,playerposy-150,playerposx+150,playerposy+150);
        }
        aniplayer++;
        if (aniplayer > 9)
        {
            aniplayer= 1;
        }
    }
    int laserpos;
    void playerlaser()
    {
        playerposx = 300;
        playerposy = mousey();
        laserpos = -200;

        readimagefile("shoot1.gif", playerposx-150,playerposy-150,playerposx+150,playerposy+150);
        if (anilaser >= 1 && anilaser <4)
        {
            readimagefile("laser1.gif",laserpos,playerposy-150,laserpos+1700,playerposy+150);
        }
        if (anilaser >= 4 && anilaser<7)
        {
            readimagefile("laser2.gif",laserpos,playerposy-150,laserpos+1700,playerposy+150);
        }
        if (anilaser >= 7 && anilaser <10)
        {
            readimagefile("laser3.gif",laserpos,playerposy-150,laserpos+1700,playerposy+150);
        }
        anilaser++;
        if (anilaser > 9)
        {
            anilaser= 1;
        }
    }
    int weakspot1 = 100;
    int weakspot2 = 600;
    int weakspot3 = 400;
    int weakspot4 = 800;
    int weakspot5 = 200;
    int wsstate = 1;
    int wsy = 1100;
    void weakpoint()
    {
        if (wsstate == 1)
        {
            circle(wsy,weakspot1,50);
            if (GetAsyncKeyState(' ') && playerposy > weakspot1-50 && playerposy < weakspot1+50){
            wsstate = wsstate+1;
            killcount = killcount+1;
            healthplus();
            }
        }
        if (wsstate == 2)
        {
            circle(wsy,weakspot2,50);
            if (GetAsyncKeyState(' ') && playerposy > weakspot2-50 && playerposy < weakspot2+50){
            wsstate = wsstate+1;
            killcount = killcount+1;
            healthplus();
            }
        }
        if (wsstate == 3)
        {
            circle(wsy,weakspot3,50);
            if (GetAsyncKeyState(' ') && playerposy > weakspot3-50 && playerposy < weakspot3+50){
            wsstate = wsstate+1;
            killcount = killcount+1;
            healthplus();
            }
        }
        if (wsstate == 4)
        {
            circle(wsy,weakspot4,50);
            if (GetAsyncKeyState(' ') && playerposy > weakspot4-50 && playerposy < weakspot4+50){
            wsstate = wsstate+1;
            killcount = killcount+1;
            healthplus();
            }
        }
        if (wsstate == 5)
        {
            circle(wsy,weakspot5,50);
            if (GetAsyncKeyState(' ') && playerposy > weakspot5-50 && playerposy < weakspot5+50){
            wsstate = wsstate+1;
            killcount = killcount+1;
            healthplus();
            }
        }
        if (wsstate>5)
        {
            wsstate = 1;
        }
    }
    int anirobot = 1;

    int enemyypos = 1500;
    int enemyypos1 = 1800;
    int enemyypos2 = 1700;
    int enemyypos3 = 1600;
    int enemyypos4 = 1900;

    int enemy7pos = 150;
    int enemy8pos = 300;
    int enemy9pos = 600;
    int enemy10pos = 750;
    int enemy11pos = 450;
    int anishark = 1;

    void printshark(int x, int y)
    {
        if (anishark == 1)
        {
            readimagefile("shark1.gif",x-150,y-150,x+150,y+150);
        }
        if (anishark == 2)
        {
            readimagefile("shark2.gif",x-150,y-150,x+150,y+150);
        }
        if (anishark == 3)
        {
            readimagefile("shark3.gif",x-150,y-150,x+150,y+150);
        }
        if (anishark == 4)
        {
            readimagefile("shark4.gif",x-150,y-150,x+150,y+150);
        }
        if (anishark == 5)
        {
            readimagefile("shark5.gif",x-150,y-150,x+150,y+150);
        }
        if (anishark == 6)
        {
            readimagefile("shark6.gif",x-150,y-150,x+150,y+150);
        }
        anishark++;
        if (anishark >6)
        {
            anishark = 1;
        }
    }

    void checkdamage (int x, int y)
    {
        if (x < playerposx && y >= playerposy-5 && y <= playerposy+5)
            healthminus();
    }

    void enemy7()
    {
        printshark (enemyypos,enemy7pos);
        checkdamage (enemyypos,enemy7pos);
        enemyypos=enemyypos-22;
        if (enemyypos < 0)
        {
            enemyypos = 1500;
        }
    }
    void enemy8()
    {
        printshark (enemyypos1,enemy8pos);
        checkdamage (enemyypos1,enemy8pos);
        enemyypos1=enemyypos1-22;
        if (enemyypos1 < 0)
        {
            enemyypos1 = 1900;
        }
    }
    void enemy9()
    {
        printshark (enemyypos2,enemy9pos);
        checkdamage (enemyypos2,enemy9pos);
        enemyypos2=enemyypos2-22;
        if (enemyypos2 < 0)
        {
            enemyypos2 = 1800;
        }
    }
    void enemy10()
    {
        printshark (enemyypos3,enemy10pos);
        checkdamage (enemyypos3,enemy10pos);
        enemyypos3=enemyypos3-22;
        if (enemyypos3 < 0)
        {
            enemyypos3 = 1700;
        }
    }
    void enemy11()
    {
        printshark (enemyypos4,enemy11pos);
        checkdamage (enemyypos4,enemy11pos);
        enemyypos4=enemyypos4-22;
        if (enemyypos4 < 0)
        {
            enemyypos4 = 1000;
        }
    }

    void finalstage()
    {
        setcolor(WHITE);
        putimage(0,0,bg3,COPY_PUT);
        boss();
        weakpoint();
        healthsys();
        enemy7();
        enemy8();
        enemy9();
        enemy10();
        enemy11();

        if (GetAsyncKeyState(' '))
        {
            playerlaser();
        }
        else
        {
             finalplayer();
        }
        if (killcount >= 110)
        {
            stage = 4;
        }
    }

};


class mmenu : public game
{
public:
    float menu = 0;
    float selection = 1;
    float charselect = 1;

    void mainmenu()
    {
        if (menu == 0)
        {
            cleardevice();
            readimagefile("mainmenu.gif",0,0,getmaxx(),getmaxy());
            if (GetAsyncKeyState(' '))
            {
                menu = 1;
            }
        }
        if (menu == 1)
        {
            if (selection == 1)
                 {
                     cleardevice();
                     readimagefile("menuselect1.gif",0,0,getmaxx(),getmaxy());
                     if (GetAsyncKeyState(VK_RETURN))
                     {
                         menu = 2;
                     }
                 }
            if (selection == 2)
                 {
                     cleardevice();
                     readimagefile("menuselect2.gif",0,0,getmaxx(),getmaxy());
                 }
            if (selection == 3)
                 {
                     cleardevice();
                     readimagefile("menuselect3.gif",0,0,getmaxx(),getmaxy());
                     if (GetAsyncKeyState(VK_RETURN))
                     {
                         menu = 0;
                     }
                 }
            if (GetAsyncKeyState(VK_UP))
            {
                selection--;
                delay(100);
                if (selection <= 1)
                {
                    selection = 1;
                }
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                selection++;
                delay(100);
                if (selection >= 3)
                {
                    selection = 3;
                }
            }
        }

        if (menu == 2)
        {
            if (charselect == 1)
                 {
                     cleardevice();
                     readimagefile("ruby.gif",0,0,getmaxx(),getmaxy());
                     delay(100);
                     if (GetAsyncKeyState(VK_RETURN))
                     {
                         menu = 5;
                     }
                 }
            if (charselect == 2)
                 {
                     cleardevice();
                     readimagefile("aqua.gif",0,0,getmaxx(),getmaxy());
                 }
            if (GetAsyncKeyState(VK_RIGHT))
            {
               charselect++;
                delay(100);
                if (charselect >=2)
                {
                    charselect = 2;
                }
            }
            if (GetAsyncKeyState(VK_LEFT))
            {
                charselect--;
                delay(100);
                if (charselect <=1)
                {
                    charselect = 1;
                }
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                menu = 1;
            }
        }

        if (menu == 5)
        {
            startgame();
        }

    }
};



int main()
{
    initwindow(1440,900);
    mmenu a;
    int page = 0;
    int exitgame = 0;
    while (exitgame == 0)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        a.mainmenu();
        page=1-page;
    }
    closegraph();
}
