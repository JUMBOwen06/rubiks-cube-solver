#ifndef CUBE_H
#define CUBE_H

#include <stdint.h>

typedef enum { FACE_U, FACE_D, FACE_F, FACE_B, FACE_L, FACE_R, NUM_FACES } Face;

typedef struct {
    uint8_t stickers[NUM_FACES][9];   /* each value is the color 0-5 */
} Cube;

void cube_init(Cube *cube);               /* set to solved state */
int  cube_is_solved(const Cube *cube);    /* 1 if solved, else 0 */
void cube_print(const Cube *cube);        /* print unfolded net */

#endif