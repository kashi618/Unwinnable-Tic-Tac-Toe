#include <stdio.h>
#include "ui.h"

// ANSI escape functions
void clear_screen(void) {
    printf(CLEAR_SCREEN);
    fflush(stdout);
}


// Graphics
void display_title(void) {
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("░░░░░░░░░░█░█░█▀█░█▀▀░█▀█░▀█▀░█▀█░░░░░░░░░░\n");
    printf("░░░░░░░░░░█░█░█░█░█▀▀░█▀█░░█░░█▀▄░░░░░░░░░░\n");
    printf("░░░░░░░░░░▀▀▀░▀░▀░▀░░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░\n");
    printf("░░▀█▀░▀█▀░█▀▀░░░▀█▀░█▀█░█▀▀░░░▀█▀░█▀█░█▀▀░░\n");
    printf("░░░█░░░█░░█░░░░░░█░░█▀█░█░░░░░░█░░█░█░█▀▀░░\n");
    printf("░░░▀░░▀▀▀░▀▀▀░░░░▀░░▀░▀░▀▀▀░░░░▀░░▀▀▀░▀▀▀░░\n");
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");   
    fflush(stdout);
}

void display_menu_options(MenuChoice choice) {
    switch (choice) {
        case NONE:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  Start (s)                            ░░\n");
            printf("░░  About (a)                            ░░\n");
            printf("░░  Quit  (q)                            ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
        case START:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  "MAGENTA"Start (s)"RESET"                            ░░\n");
            printf("░░  About (a)                            ░░\n");
            printf("░░  Quit  (q)                            ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
        case ABOUT:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  Start (s)                            ░░\n");
            printf("░░  "MAGENTA"About (a)"RESET"                            ░░\n");
            printf("░░  Quit  (q)                            ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;        
        case QUIT:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  Start (s)                            ░░\n");
            printf("░░  About (a)                            ░░\n");
            printf("░░  "MAGENTA"Quit  (q)"RESET"                            ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
    }

    /*
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("░░                                       ░░\n");
    printf("░░  Start (s)                            ░░\n");
    printf("░░  About (a)                            ░░\n");
    printf("░░  Quit  (q)                            ░░\n");
    printf("░░                                       ░░\n");
    printf("░░                                       ░░\n");
    printf("░░                                       ░░\n");
    printf("░░                                       ░░\n");
    printf("░░                             by kashi  ░░\n");
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    fflush(stdout);
    */
}
