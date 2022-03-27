#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define GL_GLEXT_PROTOTYPES
#include <GL/glcorearb.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[])
{	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	
	SDL_Window* window = SDL_CreateWindow(
		"SDL Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Surface* surface = SDL_GetWindowSurface( window );

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	if (glContext == NULL) {
		printf("GL Context could not be created! SDL_Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	if (SDL_GL_MakeCurrent(window, glContext) != 0) {
		printf("Could not make GL Context current! SDL_Error: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	bool quit = false;
	SDL_Event e;

	while (!quit) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}
