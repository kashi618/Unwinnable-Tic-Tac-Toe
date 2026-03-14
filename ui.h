#ifndef UI_H
#define UI_H

// ANSI escape codes
#define CLEAR_SCREEN "\e[2J"

// Text colours
#define RESET   "\e[0m"
#define MAGENTA "\e[35m"
#define WHITE   "\e[37m"

// Menu Choice
typedef enum{
    NONE,
    START,
    ABOUT,
    QUIT
} MenuChoice;

// Functions
void clear_screen(void);

void display_title(void);
void display_menu_options(MenuChoice choice);

#endif
