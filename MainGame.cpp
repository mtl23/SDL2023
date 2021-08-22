
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "sprite.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h" 
#include "simple_logger.h"
#include "init.h"
#include"map.h"
#include"car.h"
#include"graphics.h"
#include "glib.h"
#include "jansson.h"  
////TO DO
/*

REFACTOR WHENEVER POSSIBLE (player,background,map)



??? Title screen

??? HUD/fonts

5  screen scrolling



//at this point you may begin and start to understand
// "mode 7 rendering" in off time work on the below if/when possible

??  glib test/implement
?? import chipmunk/phyiscs (research)
?? ^^implment (touch) for all entities

??  Obstacles


??  AI
?? race logic (tracking position)


??  Multiple tracks
??  Map editor
*/



//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;


const Uint8* keys;
int main(int argc, char* args[])
{

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}

	//// Create an json interger, a json test.
	json_int_t x = 123123123;
	printf("x is % " JSON_INTEGER_FORMAT "\n", x);


	//GString* mat;
	//mat = g_string_new("Jasson, and ");
	//g_string_append_printf(mat, "Glib all tested and working\nThanks");
	//printf("%s", mat->str);



	//Main loop flag
	int done = 0;
	//Event handler
	SDL_Event e;
	Map_S M0deS3v3n = mapNew("SRC/PNG/m7_map.png", 512, 512, "SRC/PNG/bg2.png",2048,150);
	Car_S Kuruma = CarNew("SRC/PNG/car2.png",128,128);
	//the player entity
		
	//const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );


	// music
	Mix_Music* demo_music;
	demo_music = Mix_LoadMUS("SRC/sfx/surf.mid");


	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		if (Mix_PlayMusic(demo_music, -1) == -1)
		{
			return 1;
		}
	}

	// the main game loop
	do
	{
		//	//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				done = 1;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					slog("up");
					break;

				case SDLK_DOWN:
					slog("down");
					break;

				case SDLK_LEFT:
					slog("left");
					break;

				case SDLK_RIGHT:
					slog("right");
					break;

				case SDLK_ESCAPE:
					done = 1;					
					break;

				default:
					break;
				}
			}
		}
		SDL_RenderClear(gRenderer);
		entityThinkAll();
		entityDrawAll();//includes car, map and bg!!
		NextFrame();
    }while (!done);

//FREE UP EVERYTHING HERE
	//Free resources and close SDL
	close();

	return 0;
}