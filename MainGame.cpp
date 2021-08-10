
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
#include"graphics.h"

////TO DO
/*

REFACTOR WHENEVER POSSIBLE (player,background,map)

1  implememnt entity system and MAP system.
2  test spritefreeAll() and get it working
3  add sprite free all to init()
4  begin basic player entity
5  begin pointer funtions implentation on the player entity
6  test and make sure pointer function work in the loop (draw,think,update,free)
7  glib test/implement
8  jansson test/implement
9  screen scrolling



//at this point you may begin and start to understand
// "mode 7 rendering"



?? import chipmunk/phyiscs (research)
?? ^^implment (touch) for an entities
??? HUD
??? Music
??? Title screen
??  Obstacles
??  AI
??  Multiple tracks
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


	//Sprite_S* balls = spriteLoad("PNG/m7_map.png", 512, 512);
	// 
	// 
	// 
	//Main loop flag
	int done = 0;
	//Event handler
	SDL_Event e;
	// the map entity
	Map_S* M0deS3v3n = mapLoad("PNG/m7_map.png", 512, 512, "PNG/bg2.png",2048,150);
	//Sprite_S* map = spriteLoad("PNG/m7_map.png", 512, 512);
	//the player entity

	Vector2D Init_map_position;
	Init_map_position.x = 0;
	Init_map_position.y = 150;
	
	// the main game loop
	do
	{
	SDL_RenderClear(gRenderer);
	spriteDraw(M0deS3v3n->MAP->sprite, gRenderer, 0, Init_map_position);// TODO GET THIS WORKING!!! REFACTOR TO A MAP

	//spriteDraw(map, gRenderer, 0, Init_map_position);// TODO GET THIS WORKING!!! REFACTOR TO A MAP


	//const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

			//Handle events on queue
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
	
	NextFrame();

    }while (!done);

//FREE UP EVERYTHING HERE
	//Free resources and close SDL
	close();

	return 0;
}