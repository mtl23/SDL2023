#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "vector.h"
#include "sprite.h"
#include "entity.h"
#include "car.h"




typedef struct Player_S

{
	char name[32];
	Car_S CAR;
	/*Assorted Stats*/
}Player_S;





/** YOU NEED TO MAKE AN ARRAY OF PLAYERS FOR TRACKING.
*
*@brief creates a single new Entity object
*@param a filename, and the position on the scrren you want it drawn
*@return an Entity type object
*/
Player_S PlayerInit(const char* filename, int SizeX, int SizeY);// the size of the backgrounds should be made unified
/**
*
*@brief Frees up a single Entity
*/
void PlayerFree(Player_S** player);
/**
*
**/

void PlayerChangeEntity(Player_S* player, Entity_S* entity );
void playerDraw(Player_S* player, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition); ///CURRENTLY USING CAR DRAW

#endif