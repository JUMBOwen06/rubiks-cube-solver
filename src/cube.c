#include <stdio.h>
#include "cube.h"

static const char COLOR_CHARS[] = "WYGBOR";  /* U D F B L R */

void cube_init(Cube *cube) {
    for (int f = 0; f < NUM_FACES; f++)
        for (int i = 0; i < 9; i++)
            cube->stickers[f][i] = (uint8_t)f;
}

int cube_is_solved(const Cube *cube) {
    for (int f = 0; f < NUM_FACES; f++)
        for (int i = 0; i < 9; i++)
            if (cube->stickers[f][i] != cube->stickers[f][4])
                return 0;
    return 1;
}

static void print_row(const Cube *c, Face f, int row) {
    for (int col = 0; col < 3; col++)
        putchar(COLOR_CHARS[c->stickers[f][row * 3 + col]]);
}

void cube_print(const Cube *c) {
    for (int r = 0; r < 3; r++) {          /* top face */
        printf("    ");
        print_row(c, FACE_U, r);
        putchar('\n');
    }
    for (int r = 0; r < 3; r++) {          /* L F R B */
        print_row(c, FACE_L, r); putchar(' ');
        print_row(c, FACE_F, r); putchar(' ');
        print_row(c, FACE_R, r); putchar(' ');
        print_row(c, FACE_B, r); putchar('\n');
    }
    for (int r = 0; r < 3; r++) {          /* bottom face */
        printf("    ");
        print_row(c, FACE_D, r);
        putchar('\n');
    }
}

static void rotate_face_cw(uint8_t face[9]) {
    uint8_t tmp[9];
    for (int i = 0; i < 9; i++) tmp[i] = face[i];
    int map[9] = {6, 3, 0, 7, 4, 1, 8, 5, 2}; /* dest <- src index */
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