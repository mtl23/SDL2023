#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "sprite.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h" 
#include "simple_logger.h"
#include "entity.h"
#include "jansson.h"  
#include"map.h"
#include"car.h"
#include"graphics.h"
#include "glib.h"
#include "camera.h"
#include "title.h" 
//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//The surface contained by the window
extern SDL_Surface* gScreenSurface;

extern int entityMax;
	
//Screen dimension constants
const int SCREEN_HEIGHT_OFFSET = 0;//revert to zero takes away from the bottom of the screen going up
const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512 + SCREEN_HEIGHT_OFFSET;


 bool init()
{


		//Initialization flag
		bool success = true;
		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

			// Initialize Sprite system	
			if (!InitSpriteSystem())
			{
				printf("Falied to load sprite system");
				success = false;
			}
			if (!InitEntitySystem(entityMax))
			{
			
			}

			//// Create an json interger, a json test.
			json_int_t x = 123123123;
			printf("x is % " JSON_INTEGER_FORMAT "\n", x);
			// Initialize fonts
			if (TTF_Init() == -1)
			{
				printf("Falied to SDL ttf font system");
				return false;
			}
			// Initialize sounds
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
			{
				printf("Falied to load SDL_mixer audio system");
				return false;
			}

			//load glib
			// chipmunk/physics

			//Create window
			SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE, &gWindow, &gRenderer);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}

			return success;
		}

		return false;
	


}



 int initDemoProps()
 {
	 // Inital loading of main assets for the demo
	 Map_S M0deS3v3n = mapNew("SRC/PNG/vchgss.png", 1188, 821, "SRC/PNG/bg2.png", 2048, 150); //  make the map larger than the camera
	 Player_S Player1 = PlayerInit("SRC/PNG/car2.png", 128, 128);
	Camera_S cam = CameraInit(M0deS3v3n, Player1);

	 //const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

	 // main menu music	
	 Mix_Chunk* menu_music;
	// menu_music = SDL_LoadWAV("SRC/music/BigBlue.mid");// why is this not playing with a WAV??
	 menu_music = Mix_LoadWAV("SRC/music/Theme.WAV");// why is this not playing with a WAV??

	 //Play the music
	 Mix_PlayChannel(-1, menu_music, 0);
		

	 return 0;
 }



 void close()
 {
	
		//close Entity System
	     CloseEntitySystem();
		 //close Sprite System
		 CloseSpriteSystem();
		 //Destroy window
		 SDL_DestroyWindow(gWindow);
		 gWindow = NULL;

		 //Quit SDL subsystems
		 SDL_Quit();
	 
 }