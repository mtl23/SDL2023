#include <string.h>
#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"background.h"
#include"vector.h"
#include "simple_logger.h"




Background_M backgroundLoad(const char* filename, int SizeX, int SizeY,Vector2D destpostion)
{
	
	
	Background_M temp;
	temp.sky = EntityNew();
	if (temp.sky == NULL)
	{

		slog("Failed to load entity for a Map's background");
	
	}


	temp.sky->sprite = spriteLoad(filename,SizeX,SizeY);

	if (temp.sky->sprite ==NULL)
	{
	
		slog("Failed to load sprite for a Map's background");
		//return NULL;
	}
	strncpy_s(temp.bg_name, filename, 20);

	temp.sky->is_UI = 0;
	temp.sky->velocity = 0;
	temp.sky->accel = 0;
	temp.sky->is_Map = 1;
	temp.sky->is_car = 0;
	temp.sky->is_AI = 0;
	temp.sky->is_Obstacle = 0;
	strncpy_s(temp.sky->name, filename, 20);
	temp.sky->position.x = destpostion.x;
	temp.sky->position.y = destpostion.y;
	//temp.sky->draw = &entityDraw; 
	temp.sky->think = &bgThink;

	return temp;
}