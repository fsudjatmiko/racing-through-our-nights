#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu : public Game
{
public:
    // Constructor
    Menu();
    
    // Menu state variables
    float menu;
    float selection;
    float charselect;
    
    // Main menu function
    void mainmenu();
};

#endif // MENU_H
