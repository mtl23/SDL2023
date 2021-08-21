#include "vector.h"
#include "sprite.h"
#include "entity.h"
#include "car.h"

Car_S CarNew(const char* filename, int SizeX, int SizeY)
{
	Car_S temp_car;
	Entity_S* temp;
	temp = EntityNew();
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
	temp_car.CAR->sprite = temp_spr;// the car

	return temp_car;
}

void carDraw(Car_S car, SDL_Renderer* renderer, Vector2D destPosition)
{

	spriteDraw(car.CAR->sprite, renderer, 0, destPosition);// TODO REFACTOR TO A MAP  -works with an entity or  sprite created

}