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
    display_title();
    display_menu_options(NO_CHOICE); 

    while (1) {
        currInput = getchar();
        
        clear_screen();
        display_title();
    
        switch (currInput) {
            // Handles arrow keys 
            case 27:
                if (getchar() == '[') {
                    char arrow = getchar();
                    switch (arrow) {
                        case 'A': // Up arrow
                            if (currMenu == NO_CHOICE || currMenu == START) currMenu = QUIT;
                            else currMenu--;
                            break;
                        case 'B': // Down arrow
                            if (currMenu == NO_CHOICE || currMenu == QUIT) currMenu = START;
                            else currMenu++;
                            break;
                    }
                    display_menu_options(currMenu);
                }
                break;
            // Menu option handler
            case 's': case 'S':
                currMenu = START;
                display_menu_options(currMenu);
                break;
            case 'a': case 'A':
                currMenu = ABOUT;
                display_menu_options(currMenu);
                break;
            case 'c': case 'C':
                currMenu = CONFIG;
                display_menu_options(currMenu);
                break;
            case 'q': case 'Q':
                currMenu = QUIT;
                display_menu_options(currMenu);
                break;
            // Option selected
            case 13: case 10:
                // No options selected
                if (currMenu == NO_CHOICE) continue;
                
                switch (currMenu) {
                    case START:
                        // TODO: Implement the game
                        printf("DEBUG: Starting game\n");
                        break;
                    case ABOUT:
                        // TODO: Implement about menu
                        printf("DEBUG: About menu\n");
                        break;
                    case CONFIG:
                        // TODO: Implement config menu
                        printf("DEBUG: Config menun\n");
                        break;
                    case QUIT:
                        // TODO: Add "reset terminal settings" function
                        // TODO: Signal handler for abrupt quit such as "ctrl+c"
                        set_raw_mode(0); 
                        return 0;
                }
                break;
            default:
                display_menu_options(NO_CHOICE);
                currInput = 0;
        } // END switch
    } // END while

    return 0;
}


