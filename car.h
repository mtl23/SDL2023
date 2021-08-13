#ifndef __CAR_H__
#define __CAR_H__

#include "vector.h"
#include "sprite.h"
#include "entity.h"

typedef struct Car_S
{
	Entity_S* car;
	Vector2D Init_car_position;
	
}Car_S;


Car_S CarNew(const char* filename, int SizeX, int SizeY);// the size of the backgrounds should be made unified
void carFree(Car_S* map);
void carDraw(Car_S* map, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition); ///technically the ,mapo it entity #1 so consider not using this in later implementastions

#endif