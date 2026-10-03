#include <stdio.h>
#include "cube.h"
#include "moves.h"

int main(void) {
    Cube cube;
    cube_init(&cube);
    printf("Cube\n");
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    printf("After U\n");
    cube_move_U(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    printf("After U'\n");
    cube_move_U_prime(&cube);
    cube_print(&cube);

    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    return 0;
}