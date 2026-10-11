#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "render/window.h"

int main(void) {
    Window win;
    if (window_init(&win, 800, 600, "Rubik's Cube Solver") != 0)
        return 1;

    while (!window_should_close(&win)) {
        if (glfwGetKey(win.handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(win.handle, 1);

        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window_end_frame(&win);
    }

    window_destroy(&win);
    return 0;
}