
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
#include "map.h"
#include "car.h"
#include "graphics.h"
#include "glib.h"
#include "jansson.h"  
#include "title.h"  
#include "audio.h"  
////TO DO
/*

REFACTOR WHENEVER POSSIBLE (player,background,map)

5  screen scrolling


?? import chipmunk/phyiscs (research)
?? ^^implment (touch) for all entities


//at this point you may begin and start to understand
// "mode 7 rendering" in off time work on the below if/when possible


??  Obstacles
??  AI
?? race logic (tracking position)


??  glib test/implement
??  save logic
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



	//GString* mat;
	//mat = g_string_new("Jasson, and ");
	//g_string_append_printf(mat, "Glib all tested and working\nThanks");
	//printf("%s", mat->str);



	//Main loop flag
	int done = 0;
	//Event handler
	SDL_Event e;



	if (initDemoProps() == 1)
	{
	
		slog("failed to load demo assets");
	
	}

	// Go to the title screen
	ShowTitle();
	Mix_HaltChannel(-1);

	changeMusic("SRC/music/surf.mid");

	// the main game loop
	do
	{
		//	//Handle events on queue ///does this need to be here?
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
		// end does this need to be here ? INPUT SECTION REFACTOR!!!
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