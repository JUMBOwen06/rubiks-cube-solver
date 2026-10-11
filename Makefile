CC        := gcc
CFLAGS    := -Wall -Wextra -std=c11 -g -Iinclude
GL_CFLAGS := -Ithird_party/glad/include
GL_LIBS   := -lglfw -lGL -lm

CORE_SRC := src/cube.c src/moves.c
CLI_SRC  := $(CORE_SRC) src/main.c
GL_SRC   := $(CORE_SRC) $(wildcard src/render/*.c) third_party/glad/src/gl.c

CLI_OBJ  := $(CLI_SRC:%.c=build/%.o)
GL_OBJ   := $(GL_SRC:%.c=build/%.o)

all: cube

cube: $(CLI_OBJ)
	$(CC) $^ -o $@

viewer: $(GL_OBJ)
	$(CC) $^ -o cube_gl $(GL_LIBS)

build/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(GL_CFLAGS) -c $< -o $@

run: cube
	./cube

run-viewer: viewer
	./cube_gl

clean:
	rm -rf build cube cube_gl

.PHONY: all viewer run run-viewer clean