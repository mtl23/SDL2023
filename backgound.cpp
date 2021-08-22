#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"background.h"
#include"vector.h"
#include "simple_logger.h"
#include <string.h>




Background_M backgroundLoad(const char* filename, int SizeX, int SizeY,Vector2D destpostion)
{
	
	
	Background_M temp;
	temp.sky = EntityNew();
	if (temp.sky == NULL)
	{

		slog("Failed to load entity for a Map's background");
	
	}
	//temp = (Background_M*)malloc(sizeof(Background_M));
	//memset(temp, 0, sizeof(Background_M));


	//temp.sky = (Sprite_S*)malloc(sizeof(Sprite_S));
	//memset(temp->sky, 0, sizeof(Sprite_S));

	temp.sky->sprite = spriteLoad(filename,SizeX,SizeY);

	if (temp.sky->sprite ==NULL)
	{
	
		slog("Failed to load sprite for a Map's background");
		//return NULL;
	}
	strncpy_s(temp.bg_name, filename, 20);

	temp.sky->position.x = destpostion.x;
	temp.sky->position.y = destpostion.y;
	temp.sky->draw = &entityDraw;


	return temp;
}

//void backgroundFree(Background_M* bg) 
//{
//
//
//}
//
//
//void backgroundDraw(Background_M* bg, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition)
//{
//
//}