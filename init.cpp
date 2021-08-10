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

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

//The surface contained by the window
extern SDL_Surface* gScreenSurface;

extern int entityMax;



 bool init()
{



	
	//Screen dimension constants
	 const int SCREEN_HEIGHT_OFFSET = 150;//revert to zero
	const int SCREEN_WIDTH = 512;
	const int SCREEN_HEIGHT = 512+ SCREEN_HEIGHT_OFFSET;


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

			// Initialize fonts
			if (TTF_Init() == -1)
			{
				printf("Falied to SDL ttf font system");
				return false;
			}
			// Initialize sounds
			if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			{
				printf("Falied to load SDL_mixer audio system");
				return false;
			}

			//load glib
		    //jannson
			// chipmunk

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