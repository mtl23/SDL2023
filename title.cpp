#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include "title.h"
#include "SDL_ttf.h"
#include "simple_logger.h"

extern  SDL_Renderer* gRenderer;
int ShowTitle()
{
	SDL_RenderClear(gRenderer);


TTF_Font *font =  NULL;
TTF_Font *font2 =  NULL;
TTF_Font *font3 =  NULL;

font =	TTF_OpenFont( "SRC/fonts/font.ttf", 36 );
font2 =	TTF_OpenFont( "SRC/fonts/font1.ttf", 36 );
font3  =	TTF_OpenFont( "SRC/fonts/font2.ttf", 36 );

SDL_Rect Logo;

SDL_Texture* Title;
SDL_Texture* Title2;
SDL_Texture* Title3;
  if( font == NULL || font2 == NULL || font3 == NULL )
    {
     slog("font not loaded properly");
		return 0;
    }


  char title[32];
  char title2[32];
  char title3[32];
  strcpy(title ,"Capulet");
  strcpy(title2 ,"Mode");
  strcpy(title3 ,"Racing");
  SDL_Color textColor = { 255, 255, 255 };
  SDL_Color textColor2 = { 255, 22, 60 };
  SDL_Color textColor3 = { 55, 255, 50 };

  SDL_Surface *message = TTF_RenderText_Solid( font, title, textColor);
  SDL_Surface *message2 = TTF_RenderText_Solid( font2, title2, textColor2);
  SDL_Surface *message3 = TTF_RenderText_Solid( font2, title3, textColor3);


  Title = SDL_CreateTextureFromSurface(gRenderer, message );
  Title2 = SDL_CreateTextureFromSurface(gRenderer, message2 );
  Title3 = SDL_CreateTextureFromSurface(gRenderer, message3 );
		
  int done = 0;

  do  {


  Logo.x = 150;
  Logo.y = 150;
  Logo.w = 512;
  Logo.h = 128;
  	
    SDL_RenderCopy(gRenderer,Title,NULL,&Logo);
    Logo.w = 256;
    Logo.h = 128;
	Logo.x += 512;  
	SDL_RenderCopy(gRenderer,Title2,NULL,&Logo);
	Logo.x -= 260;
	Logo.y += 128;
	SDL_RenderCopy(gRenderer,Title3,NULL,&Logo);

	SDL_RenderPresent(gRenderer);
	
	SDL_Event e;
	 SDL_PollEvent( &e ); 
	
	if( e.type == SDL_KEYUP )
					{
						
				done = 1;

					}

}while(!done);// end do

  return 0;
}