#ifndef SCRAMBLE_H
#define SCRAMBLE_H

#include "cube.h"


typedef enum {
    MOVE_U, MOVE_U_PRIME, MOVE_U2,
    MOVE_D, MOVE_D_PRIME, MOVE_D2,
    MOVE_F, MOVE_F_PRIME, MOVE_F2,
    MOVE_B, MOVE_B_PRIME, MOVE_B2,
    MOVE_L, MOVE_L_PRIME, MOVE_L2,
    MOVE_R, MOVE_R_PRIME, MOVE_R2,
    NUM_MOVES
} Move;


void scramble_generate(Move *out, int n, unsigned seed);
void cube_aplly_move(Cube *cube, Move m);
void cube_apply_moves(Cube *cube, const Move *moves, int n);
Move move_inverse(Move m);
const char *move_name(Move m);

#endif