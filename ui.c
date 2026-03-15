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

// Graphics
void display_title(void) {
    // TODO: Fix this oh my fucking god T-T
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    printf("░░░░░░░░░░%s█%s░%s█%s░%s█▀█%s░%s█▀▀%s░%s█▀█%s░%s▀█▀%s░%s█▀█%s░░░░░░░░░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░░░░░░░░░%s█%s░%s█%s░%s█%s░%s█%s░%s█▀▀%s░%s█▀█%s░░%s█%s░░%s█▀▄%s░░░░░░░░░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░░░░░░░░░%s▀▀▀%s░%s▀%s░%s▀%s░%s▀%s░░░%s▀%s░%s▀%s░%s▀▀▀%s░%s▀%s░%s▀%s░░░░░░░░░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░%s▀█▀%s░%s▀█▀%s░%s█▀▀%s░░░%s▀█▀%s░%s█▀█%s░%s█▀▀%s░░░%s▀█▀%s░%s█▀█%s░%s█▀▀%s░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░░%s█%s░░░%s█%s░░%s█%s░░░░░░%s█%s░░%s█▀█%s░%s█%s░░░░░░%s█%s░░%s█%s░%s█%s░%s█▀▀%s░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░░%s▀%s░░%s▀▀▀%s░%s▀▀▀%s░░░░%s▀%s░░%s▀%s░%s▀%s░%s▀▀▀%s░░░░%s▀%s░░%s▀▀▀%s░%s▀▀▀%s░░\n",
           MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET, MAGENTA, RESET);
    printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
    fflush(stdout);

    /*
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░░░░░░░░░█░█░█▀█░█▀▀░█▀█░▀█▀░█▀█░░░░░░░░░░
    ░░░░░░░░░░█░█░█░█░█▀▀░█▀█░░█░░█▀▄░░░░░░░░░░
    ░░░░░░░░░░▀▀▀░▀░▀░▀░░░▀░▀░▀▀▀░▀░▀░░░░░░░░░░
    ░░▀█▀░▀█▀░█▀▀░░░▀█▀░█▀█░█▀▀░░░▀█▀░█▀█░█▀▀░░
    ░░░█░░░█░░█░░░░░░█░░█▀█░█░░░░░░█░░█░█░█▀▀░░
    ░░░▀░░▀▀▀░▀▀▀░░░░▀░░▀░▀░▀▀▀░░░░▀░░▀▀▀░▀▀▀░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    */
}

void display_menu_options(MenuOption choice) {
    // TODO: Find another to implement this
    switch (choice) {
        case NO_CHOICE:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  S) Start                       ↑     ░░\n");
            printf("░░  A) About          Controls:  ← • →   ░░\n");
            printf("░░  C) Config                      ↓     ░░\n");
            printf("░░  Q) Quit                              ░░\n");
            printf("░░                                       ░░\n");
            printf("░░           (%sEnter%s) to select           ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
        case START:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  S) %sStart%s                       ↑     ░░\n", MAGENTA, RESET);
            printf("░░  A) About          Controls:  ← • →   ░░\n");
            printf("░░  C) Config                      ↓     ░░\n");
            printf("░░  Q) Quit                              ░░\n");
            printf("░░                                       ░░\n");
            printf("░░           (%sEnter%s) to select           ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
        case ABOUT:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  S) Start                       ↑     ░░\n");
            printf("░░  A) %sAbout%s          Controls:  ← • →   ░░\n", MAGENTA, RESET);
            printf("░░  C) Config                      ↓     ░░\n");
            printf("░░  Q) Quit                              ░░\n");
            printf("░░                                       ░░\n");
            printf("░░           (%sEnter%s) to select           ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break; 
        case CONFIG:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  S) Start                       ↑     ░░\n");
            printf("░░  A) About          Controls:  ← • →   ░░\n");
            printf("░░  C) %sConfig%s                      ↓     ░░\n", MAGENTA, RESET);
            printf("░░  Q) Quit                              ░░\n");
            printf("░░                                       ░░\n");
            printf("░░           (%sEnter%s) to select           ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
        case QUIT:
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            printf("░░                                       ░░\n");
            printf("░░  S) Start                       ↑     ░░\n");
            printf("░░  A) About          Controls:  ← • →   ░░\n");
            printf("░░  C) Config                      ↓     ░░\n");
            printf("░░  Q) %sQuit%s                              ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░           (%sEnter%s) to select           ░░\n", MAGENTA, RESET);
            printf("░░                                       ░░\n");
            printf("░░                             by kashi  ░░\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░\n");
            fflush(stdout);
            break;
    }

    /*
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    ░░                                       ░░
    ░░  S) Start                       ↑     ░░
    ░░  A) About          Controls:  ← • →   ░░
    ░░  C) Config                      ↓     ░░
    ░░  Q) Quit                              ░░
    ░░                                       ░░
    ░░           (Enter) to select           ░░
    ░░                                       ░░
    ░░                             by kashi  ░░
    ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
    */
}
