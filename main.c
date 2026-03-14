#include <stdio.h>
#include "ui.h"

// Entry point
int main(void) {
    char choice = NONE;

    clear_screen();
    display_title();
    display_menu_options(NONE); 

     while (1) {
        choice = getchar();
        getchar();
        
        clear_screen();
        display_title();

        switch (choice) {
            case 's':
                display_menu_options(START);
                break;
            case 'a':
                display_menu_options(ABOUT);
                break;
            case 'q':
                display_menu_options(QUIT);
                break;
            default:
                display_menu_options(NONE);
                choice = NONE;
        }
    }

    return 0;
}

