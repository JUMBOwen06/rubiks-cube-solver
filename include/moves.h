#ifndef MOVES_H
#define MOVES_H

#include "cube.h"

void cube_move_U(Cube *cube);
void cube_move_U_prime(Cube *cube);

void cube_move_D(Cube *cube);
void cube_move_D_prime(Cube *cube);

void cube_move_F(Cube *cube);
void cube_move_F_prime(Cube *cube);

void cube_move_B(Cube *cube);
void cube_move_B_prime(Cube *cube);

void cube_move_R(Cube *cube);
void cube_move_R_prime(Cube *cube);

void cube_move_L(Cube *cube);
void cube_move_L_prime(Cube *cube);
#endif