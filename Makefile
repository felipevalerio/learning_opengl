CC = g++

CFLAGS = -Isrc -Iinclude
LDFLAGS = -Llib -lglfw3 -lopengl32 -lgdi32

SRC = src/main.cpp src/ppm.cpp src/glad.c

OUT = main.exe

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT) $(LDFLAGS)