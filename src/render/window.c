#include <stdio.h>
#include <glad/gl.h>        /* must come before GLFW */
#include <GLFW/glfw3.h>
#include "render/window.h"

static void on_resize(GLFWwindow *win, int w, int h) {
    (void)win;
    glViewport(0, 0, w, h);
}

int window_init(Window *w, int width, int height, const char *title) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to init GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    w->handle = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!w->handle) {
        fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return -1;
    }
    w->width = width;
    w->height = height;

    glfwMakeContextCurrent(w->handle);
    if (!gladLoadGL((GLADloadfunc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to load OpenGL\n");
        glfwDestroyWindow(w->handle);
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(w->handle, on_resize);
    glfwSwapInterval(1);   /* vsync */
    return 0;
}

int window_should_close(const Window *w) {
    return glfwWindowShouldClose(w->handle);
}

void window_end_frame(Window *w) {
    glfwSwapBuffers(w->handle);
    glfwPollEvents();
}

void window_destroy(Window *w) {
    glfwDestroyWindow(w->handle);
    glfwTerminate();
}