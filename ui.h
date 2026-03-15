#ifndef UI_H
#define UI_H

// ANSI escape codes
#define CLEAR_SCREEN "\e[2J"

// Text colours
#define RESET   "\e[0m"
#define MAGENTA "\e[35m"
#define WHITE   "\e[37m"

// Menu Options
typedef enum{
    START,
    ABOUT,
    CONFIG,
    QUIT,
    NUM_MENU_OPTIONS,
    NO_CHOICE = -1 
} MenuOption;

// Functions
void clear_screen(void);

void set_raw_mode(int);

void display_title(void);
void display_menu_options(MenuOption choice);

#endif
