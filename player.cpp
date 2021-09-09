#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "entity.h"
#include "vector.h"
#include "simple_logger.h"
#include "player.h"



Player_S PlayerInit(const char* filename, int SizeX, int SizeY)
{
	Player_S temp;
	strncpy_s(temp.name, filename, 20);
	temp.CAR= CarNew("SRC/PNG/car2.png", 128, 128);
	return temp;
}
