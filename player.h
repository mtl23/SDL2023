#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "vector.h"
#include "sprite.h"
#include "entity.h"



typedef struct Player_S

{
	char name[32];
	Entity_S* playerEntity;
	/*Assorted Stats*/
}Player_S;





/**
*
*@brief creates a single new Entity object
*@param a filename, and the position on the scrren you want it drawn
*@return an Entity type object
*/
Player_S* PlayerInit();
/**
*
*@brief Frees up a single Entity
*/
void PlayerFree(Player_S** player);
/**
*
**/

void PlayerChangeEntity(Player_S* player, Entity_S* entity );

#endif