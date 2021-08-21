
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

////TO DO
/*

REFACTOR WHENEVER POSSIBLE (player,background,map)





3  glib test/implement
4  jansson test/implement
5  screen scrolling



//at this point you may begin and start to understand
// "mode 7 rendering" in off time work on the below if/when possible



?? import chipmunk/phyiscs (research)
?? ^^implment (touch) for all entities
??? HUD
??? Music
??? Title screen
??  Obstacles
??  AI
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

	//Vector2D Init_map_position;// refactor for map position
	//Init_map_position.x = 0;// refactor for map position
	//Init_map_position.y = 150;// refactor for map position




	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}


	//Main loop flag
	int done = 0;
	//Event handler
	SDL_Event e;
	// the map entity
	// 
    //Background_M map = backgroundLoad("SRC/PNG/m7_map.png", 512, 512); //-works
	//Entity_S map2 = *EntityNew();
	//map2.sprite= spriteLoad("SRC/PNG/m7_map.png", 512, 512);// -works
	//Sprite_S map3 = *spriteLoad("SRC/PNG/bg2.png", 512, 512); //-works
	Map_S M0deS3v3n = mapNew("SRC/PNG/m7_map.png", 512, 512, "SRC/PNG/bg2.png",2048,150);
	Car_S Kuruma = CarNew("SRC/PNG/car2.png",128,128);
	//the player entity

	
	//const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

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
		entityDrawAll();//  8/21 for starters the bg,map, and car
		NextFrame();
    }while (!done);

//FREE UP EVERYTHING HERE
	//Free resources and close SDL
	close();

	return 0;
}