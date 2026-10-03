#include <stdio.h>
#include "cube.h"

int main(void) {
    Cube cube;
    cube_init(&cube);

    printf("Solved cube:\n");
    cube_print(&cube);

    cube_move_U(&cube);
    printf("\nAfter U move:\n");
    cube_print(&cube);
    printf("Solved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    return 0;
}