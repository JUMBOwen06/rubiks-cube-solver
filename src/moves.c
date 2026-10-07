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



/* U face rotation */
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



/* D face rotation */
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



/* F face rotation */
void cube_move_F(Cube *cube) {
    rotate_face_cw(cube->stickers[FACE_F]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][6];
    tmp[1] = cube->stickers[FACE_U][7];
    tmp[2] = cube->stickers[FACE_U][8];

    cube->stickers[FACE_U][6] = cube->stickers[FACE_L][8];
    cube->stickers[FACE_U][7] = cube->stickers[FACE_L][5];
    cube->stickers[FACE_U][8] = cube->stickers[FACE_L][2];

    cube->stickers[FACE_L][2] = cube->stickers[FACE_D][0];
    cube->stickers[FACE_L][5] = cube->stickers[FACE_D][1];
    cube->stickers[FACE_L][8] = cube->stickers[FACE_D][2];

    cube->stickers[FACE_D][0] = cube->stickers[FACE_R][6];
    cube->stickers[FACE_D][1] = cube->stickers[FACE_R][3];
    cube->stickers[FACE_D][2] = cube->stickers[FACE_R][0];

    cube->stickers[FACE_R][0] = tmp[0];
    cube->stickers[FACE_R][3] = tmp[1];
    cube->stickers[FACE_R][6] = tmp[2];
}

void cube_move_F_prime(Cube *cube) {
    rotate_face_ccw(cube->stickers[FACE_F]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][6];
    tmp[1] = cube->stickers[FACE_U][7];
    tmp[2] = cube->stickers[FACE_U][8];

    cube->stickers[FACE_U][6] = cube->stickers[FACE_R][0];
    cube->stickers[FACE_U][7] = cube->stickers[FACE_R][3];
    cube->stickers[FACE_U][8] = cube->stickers[FACE_R][6];

    cube->stickers[FACE_R][0] = cube->stickers[FACE_D][2];
    cube->stickers[FACE_R][3] = cube->stickers[FACE_D][1];
    cube->stickers[FACE_R][6] = cube->stickers[FACE_D][0];

    cube->stickers[FACE_D][0] = cube->stickers[FACE_L][2];
    cube->stickers[FACE_D][1] = cube->stickers[FACE_L][5];
    cube->stickers[FACE_D][2] = cube->stickers[FACE_L][8];

    cube->stickers[FACE_L][2] = tmp[0];
    cube->stickers[FACE_L][5] = tmp[1];
    cube->stickers[FACE_L][8] = tmp[2];
}




/* B face roation */
void cube_move_B(Cube *cube){
    rotate_face_cw(cube->stickers[FACE_B]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_B][0];
    tmp[1] = cube->stickers[FACE_B][1];
    tmp[2] = cube->stickers[FACE_B][2];

    cube->stickers[FACE_U][0] = cube->stickers[FACE_R][2];
    cube->stickers[FACE_U][1] = cube->stickers[FACE_R][5];
    cube->stickers[FACE_U][2] = cube->stickers[FACE_R][8];

    cube->stickers[FACE_R][2] = cube->stickers[FACE_D][6];
    cube->stickers[FACE_R][5] = cube->stickers[FACE_D][7];
    cube->stickers[FACE_R][8] = cube->stickers[FACE_D][8];

    cube->stickers[FACE_D][6] = cube->stickers[FACE_L][0];
    cube->stickers[FACE_D][7] = cube->stickers[FACE_L][3];
    cube->stickers[FACE_D][8] = cube->stickers[FACE_L][6];

    cube->stickers[FACE_L][0] = tmp[0];
    cube->stickers[FACE_L][3] = tmp[1];
    cube->stickers[FACE_L][6] = tmp[2];
}

void cube_move_B_prime(Cube *cube){
    rotate_face_ccw(cube->stickers[FACE_B]);
}



/* R face rotation */
void cube_move_R(Cube *cube) {
    rotate_face_cw(cube->stickers[FACE_R]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][2];
    tmp[1] = cube->stickers[FACE_U][5];
    tmp[2] = cube->stickers[FACE_U][8];

    cube->stickers[FACE_U][2] = cube->stickers[FACE_F][2];
    cube->stickers[FACE_U][5] = cube->stickers[FACE_F][5];
    cube->stickers[FACE_U][8] = cube->stickers[FACE_F][8];

    cube->stickers[FACE_F][2] = cube->stickers[FACE_D][2];
    cube->stickers[FACE_F][5] = cube->stickers[FACE_D][5];
    cube->stickers[FACE_F][8] = cube->stickers[FACE_D][8];

    cube->stickers[FACE_D][2] = cube->stickers[FACE_B][6];   
    cube->stickers[FACE_D][5] = cube->stickers[FACE_B][3];
    cube->stickers[FACE_D][8] = cube->stickers[FACE_B][0];

    cube->stickers[FACE_B][0] = tmp[2];                     
    cube->stickers[FACE_B][3] = tmp[1];
    cube->stickers[FACE_B][6] = tmp[0];
}

void cube_move_R_prime(Cube *cube) {
    rotate_face_ccw(cube->stickers[FACE_R]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][2];
    tmp[1] = cube->stickers[FACE_U][5];
    tmp[2] = cube->stickers[FACE_U][8];

    cube->stickers[FACE_U][2] = cube->stickers[FACE_B][6];   /* reversed */
    cube->stickers[FACE_U][5] = cube->stickers[FACE_B][3];
    cube->stickers[FACE_U][8] = cube->stickers[FACE_B][0];

    cube->stickers[FACE_B][0] = cube->stickers[FACE_D][8];   /* reversed */
    cube->stickers[FACE_B][3] = cube->stickers[FACE_D][5];
    cube->stickers[FACE_B][6] = cube->stickers[FACE_D][2];

    cube->stickers[FACE_D][2] = cube->stickers[FACE_F][2];
    cube->stickers[FACE_D][5] = cube->stickers[FACE_F][5];
    cube->stickers[FACE_D][8] = cube->stickers[FACE_F][8];

    cube->stickers[FACE_F][2] = tmp[0];
    cube->stickers[FACE_F][5] = tmp[1];
    cube->stickers[FACE_F][8] = tmp[2];
}



/* L face rotation */
void cube_move_L(Cube *cube){
    rotate_face_cw(cube->stickers[FACE_L]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][0];
    tmp[1] = cube->stickers[FACE_U][3];
    tmp[2] = cube->stickers[FACE_U][6];

    cube->stickers[FACE_U][0] = cube->stickers[FACE_F][0];
    cube->stickers[FACE_U][3] = cube->stickers[FACE_F][3];
    cube->stickers[FACE_U][6] = cube->stickers[FACE_F][6];

    cube->stickers[FACE_F][0] = cube->stickers[FACE_D][0];
    cube->stickers[FACE_F][3] = cube->stickers[FACE_D][3];
    cube->stickers[FACE_F][6] = cube->stickers[FACE_D][6];

    cube->stickers[FACE_D][0] = cube->stickers[FACE_B][0];
    cube->stickers[FACE_D][3] = cube->stickers[FACE_B][3];
    cube->stickers[FACE_D][6] = cube->stickers[FACE_B][6];

    cube->stickers[FACE_B][0] = tmp[0];
    cube->stickers[FACE_B][3] = tmp[1];
    cube->stickers[FACE_B][6] = tmp[2];
}

void cube_move_L_prime(Cube *cube){
    rotate_face_ccw(cube->stickers[FACE_L]);

    uint8_t tmp[3];
    tmp[0] = cube->stickers[FACE_U][0];
    tmp[1] = cube->stickers[FACE_U][3];
    tmp[2] = cube->stickers[FACE_U][6];

    cube->stickers[FACE_U][0] = cube->stickers[FACE_B][0];
    cube->stickers[FACE_U][3] = cube->stickers[FACE_B][3];
    cube->stickers[FACE_U][6] = cube->stickers[FACE_B][6];

    cube->stickers[FACE_B][0] = cube->stickers[FACE_D][0];
    cube->stickers[FACE_B][3] = cube->stickers[FACE_D][3];
    cube->stickers[FACE_B][6] = cube->stickers[FACE_D][6];

    cube->stickers[FACE_D][0] = cube->stickers[FACE_F][0];
    cube->stickers[FACE_D][3] = cube->stickers[FACE_F][3];
    cube->stickers[FACE_D][6] = cube->stickers[FACE_F][6];

    cube->stickers[FACE_F][0] = tmp[0];
    cube->stickers[FACE_F][3] = tmp[1];
    cube->stickers[FACE_F][6] = tmp[2];
}