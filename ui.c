#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "ui.h"

// ANSI escape functions
void clear_screen(void) {
    printf(CLEAR_SCREEN);
    fflush(stdout);
}


// Function to set terminal to raw mode
void set_raw_mode(int enable) {
    static struct termios backup;
    struct termios t;
    
    if (enable) {
        // Save current terminal settings
        tcgetattr(STDIN_FILENO, &backup);
        t = backup;
        t.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSANOW, &t);
    }
    else tcsetattr(STDIN_FILENO, TCSANOW, &backup);
}

// Draws main menu
void draw_menu(MenuOption choice) {
    int maxX = 43, maxY = 13;
    int x, y, i;

    clear_screen();
    display_title();

    for (y=0; y<maxY-1; y++) {
        for (x=0; x<maxX; x++) {
            // Draw top border
            if (y==0 || y==maxY-2) {
                printf("░");
                continue;
            }

            // Draw left border
            if (x==0 || x==1) {
                printf("░");
                continue;
            }

            // Draw right border
            if (x==maxX-1 || x==maxX-2) {
                printf("░");
                continue;
            }
            
            // First menu option
            if (y==2 && x==4) {
                printf("(%sS%s) ", GREEN, RESET);
                if (choice == START) {
                    printf("%sStart%s", MAGENTA, RESET);
                }
                else {
                    printf("Start");
                }
                x+=8;
                continue;
            }
            
            // Second menu option
            if (y==3 && x==4) {
                printf("(%sA%s) ", GREEN, RESET);
                if (choice == ABOUT) {
                    printf("%sAbout%s", MAGENTA, RESET);
                }
                else {
                    printf("About");
                }
                x+=8;
                continue;
            }
            
            // Third menu option
            if (y==4 && x==4) {
                printf("(%sC%s) ", GREEN, RESET);
                if (choice == CONFIG) {
                    printf("%sConfig%s", MAGENTA, RESET);
                }
                else {
                    printf("Config");
                }
                x+=9;
                continue;
            }
            
            // Fourth menu option
            if (y==5 && x==4) {
                printf("(%sQ%s) ", GREEN, RESET);
                if (choice == QUIT) {
                    printf("%sQuit%s",MAGENTA, RESET);
                }
                else {
                    printf("Quit");
                }
                x+=7;
                continue;
            }

            // Draw controls
            if (y==2 && x==35) {
                printf("%s↑%s", GREEN, RESET);
                continue;
            }
            else if (y==3 && x==22) {
                printf("Controls:  ← • →");
                x+=15;
                continue;
            }
            else if (y==4 && x==35) {
                printf("%s↓%s", GREEN, RESET);
                continue;
            }
            
            // Draw button for select
            if (y==8 && x==13) {
                printf("(%sEnter%s) to select", GREEN, RESET);
                x+=16;
                continue;
            }

            // Draw author name
            if (y==10 && x==31) {
                printf("by %skashi%s", BRIGHT_YELLOW, RESET);
                x+=7;
                continue;
            }

            // Draw empty spaces
            printf(" ");
        }
        printf("\n");
    }
}
/*
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 1
░░                                       ░░ 2
░░  (S) Start                      ↑     ░░ 3
░░  (A) About         Controls:  ← • →   ░░ 4
░░  (C) Config                     ↓     ░░ 5
░░  (Q) Quit                             ░░ 6
░░                                       ░░ 7
░░                                       ░░ 8
░░           (Enter) to select           ░░ 9
░░                                       ░░10
░░                             by kashi  ░░11
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░12
1234567890          1234567890          123
          1234567890          1234567890
*/

// Draws title
void display_title(void) {
    static char *title_lines[] = {
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░",
        "░░░░░░░░░░█░█░█▀█░█▀▀░█▀█░▀█▀░█▀█░░░░░░░░░░",
        "░░░░░░░░░░█░█░█░█░█▀▀░█▀█░░█░░█▀▄░░░░░░░░░░",
        "░░░░░░░░░░▀▀▀░▀░▀░▀░░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░",
        "░░▀█▀░▀█▀░█▀▀░░░▀█▀░█▀█░█▀▀░░░▀█▀░█▀█░█▀▀░░",
        "░░░█░░░█░░█░░░░░░█░░█▀█░█░░░░░░█░░█░█░█▀▀░░",
        "░░░▀░░▀▀▀░▀▀▀░░░░▀░░▀░▀░▀▀▀░░░░▀░░▀▀▀░▀▀▀░░",
        "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
    };
    char symbol;

    for (int y=0; y<8; y++) {
        for (int x=0; x<129; x++) {
            symbol = title_lines[y][x];

            if (symbol == '█') {
                printf("ASDASD");
            }
            else 
            printf("%c", title_lines[y][x]);
        }
        printf("\n");
    } // END for
}
// 618 DO THIS NOW NEIL
/*
* Need to find some way to make the title colour coding work
*/

/*
*   Handles navigating menu options using arrow keys
*   - Modifies currMenu, storing selected menu option from arrow keys
*/
MenuOption navigate_menu_arrow_keys(MenuOption currMenu) {
    // End early if input doesn't match arrow key
    if (getchar() != '[') return NO_CHOICE;

    char arrow = getchar();
    
    switch (arrow) {
        // Up arrow
        case 'A':
            if (currMenu == NO_CHOICE || currMenu == START) {
                return QUIT;
            }
            else { 
                return --currMenu;
            }
            break;
        
    // Down arrow
        case 'B':
            if (currMenu == NO_CHOICE || currMenu == QUIT) {
                return START;
            }
            else {
                return ++currMenu;
            }
            break;
        
        // Left and right arrow
        default:
            return currMenu;
    }
}

// Makes selecting menu work 
// TODO: Better function name...
void menu_selection(MenuOption currMenu) {
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
            exit(0);
    }
}
