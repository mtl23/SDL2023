#include <string.h>
#include "vector.h"
#include "sprite.h"
#include "entity.h"
#include "car.h"

Car_S CarNew(const char* filename, int SizeX, int SizeY)
{
	Car_S temp_car;
	Entity_S* temp;
	temp = EntityNew();
	slog("created car entity");
	Sprite_S* temp_spr = spriteLoad(filename, SizeX, SizeY);
	temp_car.Init_car_position.x = 192;//(screenwidth/2)-(car->sprite.width/2)
	temp_car.Init_car_position.y = 380;//fixed number, for the most part
	
	
if (temp == NULL)
	{
		slog("Falied to create a car Entity");
		//return NULL;


	}
	temp_car.CAR = temp;


	if (&temp_spr == NULL)
	{
		slog("Failed to create a sprite for the car Entity");
		//return NULL;

	}
	temp_car.CAR->position.x = temp_car.Init_car_position.x;
	temp_car.CAR->position.y = temp_car.Init_car_position.y;
	temp_car.CAR->sprite = temp_spr;// the car
	temp_car.CAR->velocity = 1;	
	strncpy_s(temp_car.CAR->name, filename, 20);
	temp_car.CAR->accel = 0;	
	temp_car.CAR->is_UI = 0;
	temp_car.CAR->is_Map = 0;
	temp_car.CAR->is_car = 1;
	temp_car.CAR->is_AI = 0;
	temp_car.CAR->is_Obstacle = 0;
	temp_car.CAR->draw = &entityDraw;
	temp_car.CAR->think = &carThink;
	return temp_car;
}

