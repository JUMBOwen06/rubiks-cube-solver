#include <stdlib.h>
#include <time.h>
#include "scramble.h"
#include "moves.h"


typedef void (*MoveFn)(Cube *);

static const MoveFn QUARTER[NUM_FACES] = {
    cube_move_U,
    cube_move_D,
    cube_move_F,
    cube_move_B,
    cube_move_L,
    cube_move_R
};

static const MoveFn QUARTER_PRIME[NUM_FACES] = {
    cube_move_U_prime,
    cube_move_D_prime,
    cube_move_F_prime,
    cube_move_B_prime,
    cube_move_L_prime,
    cube_move_R_prime
};

static const char *MOVE_NAMES[NUM_MOVES] = {
    "U", "U'", "U2",
    "D", "D'", "D2",
    "F", "F'", "F2",
    "B", "B'", "B2",
    "L", "L'", "L2",
    "R", "R'", "R2"
};

void scramble_generate(Move *out, int n, unsigned seed){

}


void cube_apply_moves(Cube *cube, Move m){

}

Move move_inverse(Move m){
   
}

const char *move_name(Move m){
    return MOVE_NAMES[m];
}