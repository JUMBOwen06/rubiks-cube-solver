#include <stdio.h>
#include "cube.h"
#include "moves.h"

int main(void) {
    Cube cube;
    /* Initial Solved Cube */
    cube_init(&cube);
    printf("Cube\n");
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");


    for (int i = 0; i < 4; i++){
        printf("After B\n");
        cube_move_B(&cube);
        cube_print(&cube);
        printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");
    }


    return 0;
}

/*

     U move 
    printf("After U\n");
    cube_move_U(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    U' move 
    printf("After U'\n");
    cube_move_U_prime(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");



    D move 
    printf("After D\n");
    cube_move_D(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    D' move
    printf("After D'\n");
    cube_move_D_prime(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");
    


    F move
    printf("After F\n");
    cube_move_F(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");



    R move
    printf("After R\n");
    cube_move_R(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    R' move
    printf("After R'\n");
    cube_move_R_prime(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");



    L move
    printf("After l\n");
    cube_move_L(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    L' move
    printf("After l'\n");
    cube_move_L_prime(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");



    F move
    printf("After F\n");
    cube_move_F(&cube);
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");

    F' move
    printf("After l'\n");
    cube_move_F_prime(&cube)F
    cube_print(&cube);
    printf("\nSolved: %s\n", cube_is_solved(&cube) ? "yes" : "no");
*/