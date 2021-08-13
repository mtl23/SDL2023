#include "vector.h"
#include "sprite.h"
#include "entity.h"
#include "car.h"

Car_S CarNew(const char* filename, int SizeX, int SizeY)
{
	Car_S temp_car;

	Entity_S* temp;
	temp = EntityNew();
	Sprite_S* temp_spr = spriteLoad(filename, 64, 64);
	
	if (temp == NULL)
	{
		slog("Falied to create a car Entity");
		//return NULL;


	}
	temp_car.car = temp;


	if (&temp_spr == NULL)
	{
		slog("Failed to create a sprite for the Map Entity");
		//return NULL;

	}
	temp_car.car->sprite = temp_spr;// the car




	temp_car.Init_car_position.x = 256;
	temp_car.Init_car_position.y =380;


	return temp_car;
}