#include "../include/Menu.h"

Menu::Menu() : menu(0), selection(1), charselect(1)
{
    // Constructor inherits from Game
}

void Menu::mainmenu()
{
    if (menu == 0) {
        cleardevice();
        readimagefile("assets/ui/mainmenu.gif", 0, 0, getmaxx(), getmaxy());
        if (GetAsyncKeyState(' ')) {
            menu = 1;
        }
    }
    
    if (menu == 1) {
        if (selection == 1) {
            cleardevice();
            readimagefile("assets/ui/menuselect1.gif", 0, 0, getmaxx(), getmaxy());
            if (GetAsyncKeyState(VK_RETURN)) {
                menu = 2;
            }
        }
        if (selection == 2) {
            cleardevice();
            readimagefile("assets/ui/menuselect2.gif", 0, 0, getmaxx(), getmaxy());
        }
        if (selection == 3) {
            cleardevice();
            readimagefile("assets/ui/menuselect3.gif", 0, 0, getmaxx(), getmaxy());
            if (GetAsyncKeyState(VK_RETURN)) {
                menu = 0;
            }
        }
        
        if (GetAsyncKeyState(VK_UP)) {
            selection--;
            delay(100);
            if (selection <= 1) {
                selection = 1;
            }
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            selection++;
            delay(100);
            if (selection >= 3) {
                selection = 3;
            }
        }
    }

    if (menu == 2) {
        if (charselect == 1) {
            cleardevice();
            readimagefile("assets/ui/ruby.gif", 0, 0, getmaxx(), getmaxy());
            delay(100);
            if (GetAsyncKeyState(VK_RETURN)) {
                menu = 5;
            }
        }
        if (charselect == 2) {
            cleardevice();
            readimagefile("assets/ui/aqua.gif", 0, 0, getmaxx(), getmaxy());
        }
        
        if (GetAsyncKeyState(VK_RIGHT)) {
            charselect++;
            delay(100);
            if (charselect >= 2) {
                charselect = 2;
            }
        }
        if (GetAsyncKeyState(VK_LEFT)) {
            charselect--;
            delay(100);
            if (charselect <= 1) {
                charselect = 1;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE)) {
            menu = 1;
        }
    }

    if (menu == 5) {
        startgame();
    }
}
