#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

typedef enum {
    PLAYING,
    PC_WIN,
    PLAYER_WIN,
    DRAW,
} GameStatus;

typedef struct {
    char cells[3][3];     
    GameStatus status;
} Board;

#endif
