#ifndef UI_H
#define UI_H

// ANSI escape codes
#define CLEAR_SCREEN "\e[2J"

// Text colours
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define BRIGHT_YELLOW "\033[93m"

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
