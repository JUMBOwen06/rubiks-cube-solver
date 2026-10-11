#ifndef WINDOW_H
#define WINDOW_H

struct GLFWwindow;

typedef struct {
    struct GLFWwindow *handle;
    int width, height;
} Window;

int  window_init(Window *w, int width, int height, const char *title); /* 0 on success */
int  window_should_close(const Window *w);
void window_end_frame(Window *w);   /* swap buffers + poll events */
void window_destroy(Window *w);

#endif