#include <stdio.h>
#include "ui.h"

// Entry point
int main(void) {
    char currInput = 0;
    MenuOption currMenu = NO_CHOICE;

    // Initialization
    clear_screen();
    set_raw_mode(1);
    
    // Menu loop
    while (1) {
        draw_menu(currMenu);
        
        currInput = getchar();
        
        switch (currInput) {
            // Display current menu (arrow key navigation)
            case 27:
                currMenu = navigate_menu_arrow_keys(currMenu);
                break;

            // Display current menu (keyboard navigation)
            case 's': case 'S':
                currMenu = START;
                break;
            case 'a': case 'A':
                currMenu = ABOUT;
                break;
            case 'c': case 'C':
                currMenu = CONFIG;
                break;
            case 'q': case 'Q':
                currMenu = QUIT;
                break;
            
        
        // Handles menu selection (enter key)
        case 13: case 10:
            menu_selection(currMenu);
            break;
            
        // Handles unexpected inputs
        default:
            break;
        }
    } // END while
    
    return 0;
}


