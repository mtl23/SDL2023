#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"background.h"
#include"vector.h"
#include "simple_logger.h"
#include <string.h>




Background_M* backgroundLoad(const char* filename, int SizeX, int SizeY)
{
	
	
	struct Background_M temp{};
	strncpy_s(temp.bg_name, filename, 20);
	temp.sky = spriteLoad(filename,SizeX,SizeY);

	if (temp.sky ==NULL)
	{
	
		slog("Failed to load sprite for a Map's background");
		return NULL;
	}

	return &temp;
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