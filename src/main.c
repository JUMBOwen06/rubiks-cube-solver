#include <stdio.h>
#include "cube.h"

int main(void) {
    Cube cube;
    cube_init(&cube);
    cube_print(&cube);
    printf("Solved: %s\n", cube_is_solved(&cube) ? "yes" : "no");
    return 0;
}