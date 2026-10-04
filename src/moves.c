#include "moves.h"

/* rotate a 3x3 face's own stickers 90 deg clockwise */
static void rotate_face_cw(uint8_t face[9]) {
    uint8_t tmp[9];
    for (int i = 0; i < 9; i++) tmp[i] = face[i];
    int map[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2}; /* dest <- src index */
    for (int i = 0; i < 9; i++) face[i] = tmp[map[i]];
}

/* rotate a 3x3 face's own stickers 90 deg counter-clockwise */
static void rotate_face_ccw(uint8_t face[9]) {
    uint8_t tmp[9];
    for (int i = 0; i < 9; i++) tmp[i] = face[i];
    int map[9] = {2, 5, 8, 1, 4, 7, 0, 3, 6}; /* dest <- src index */
    for (int i = 0; i < 9; i++) face[i] = tmp[map[i]];
}

void cube_move_U(Cube *cube) {
    rotate_face_cw(cube->stickers[FACE_U]);

    uint8_t tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube->stickers[FACE_F][i];

    for (int i = 0; i < 3; i++) cube->stickers[FACE_F][i] = cube->stickers[FACE_R][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_R][i] = cube->stickers[FACE_B][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_B][i] = cube->stickers[FACE_L][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_L][i] = tmp[i];
}

void cube_move_U_prime(Cube *cube) {
    rotate_face_ccw(cube->stickers[FACE_U]);

    uint8_t tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube->stickers[FACE_F][i];

    for (int i = 0; i < 3; i++) cube->stickers[FACE_F][i] = cube->stickers[FACE_L][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_L][i] = cube->stickers[FACE_B][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_B][i] = cube->stickers[FACE_R][i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_R][i] = tmp[i];
}


void cube_move_D(Cube *cube) {
    rotate_face_ccw(cube->stickers[FACE_D]);

    uint8_t tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube->stickers[FACE_F][6 + i];

    for (int i = 0; i < 3; i++) cube->stickers[FACE_F][6 + i] = cube->stickers[FACE_L][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_L][6 + i] = cube->stickers[FACE_B][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_B][6 + i] = cube->stickers[FACE_R][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_R][6 + i] = tmp[i];
}

void cube_move_D_prime(Cube *cube){
    rotate_face_cw(cube->stickers[FACE_D]);

    uint8_t tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube->stickers[FACE_F][6 + i];

    for (int i = 0; i < 3; i++) cube->stickers[FACE_F][6 + i] = cube->stickers[FACE_R][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_R][6 + i] = cube->stickers[FACE_B][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_B][6 + i] = cube->stickers[FACE_L][6 + i];
    for (int i = 0; i < 3; i++) cube->stickers[FACE_L][6 + i] = tmp[i];
}