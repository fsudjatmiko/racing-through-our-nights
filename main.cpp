#include "include/Menu.h"

int main()
{
    // Initialize graphics window
    initwindow(1440, 900);
    
    // Create menu instance
    Menu gameMenu;
    
    // Game loop variables
    int page = 0;
    int exitgame = 0;
    
    // Main game loop
    while (exitgame == 0) {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();
        
        gameMenu.mainmenu();
        
        page = 1 - page;
    }
    
    // Clean up and close graphics
    closegraph();
    
    return 0;
}
