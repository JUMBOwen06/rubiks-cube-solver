# Rubik's Cube Solver
A 3x3 Rubik's Cube solver written in C, with a 3D OpenGL visualization.

## Status
Early development.
- Cube state representation and all 12 face moves are implemented
    - U, D, R, L, F, B and their inverses
- OpenGL window skeleton (GLFW + glad) builds and runs
- Clean file structure: cube logic has no OpenGL dependency, so the CLI and solver never need a window

## Dependencies
- gcc and make
- GLFW (viewer only): `sudo apt install libglfw3-dev`
- glad (OpenGL loader): generated once and committed in `third_party/glad/`, so no extra install is needed to build

## Build
    make              # builds both the CLI and the viewer
    make run          # run the CLI
    make run-viewer   # run the 3D viewer
    make clean

## Project layout
    include/          cube.h, moves.h, render/ headers
    src/              cube.c, moves.c, main.c (CLI)
    src/render/       OpenGL viewer (window, shader, mesh, camera, renderer, animation)
    third_party/glad/ generated OpenGL loader

## Planned
- Choose what move to do in the CLI
- Move-notation parser and scramble function
- Test harness for every move and its inverse
- Solver algorithm (beginner's layer-by-layer method)
- OpenGL rendering of the cube with animated moves