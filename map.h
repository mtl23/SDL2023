#ifndef __MAP_H__
#define __MAP_H__

#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"vector.h"
#include"player.h"
#include"entity.h"
#include"background.h"



/**
*
*@brief The blueprint for a map object. Representing the bottom section of the screen in a mode 7 game. Scrolls left to right
* The map should be treated as the first entity created.
*@param char the reference count of the specific map image
*@param Entity_S the refrecnce to a Sprite object to be used
*@param Background_M the refrecnce to a Background object to be used
*/

typedef struct Map_S

{
	Entity_S* MAP;
	Background_M bg_sky;
	Vector2D Init_map_position;
	Vector2D Map_size;
	Vector2D Init_bg_position;
	void(*think) (struct Map_S* map, struct Player_S player); /**logic*<*/
	void(*update) (struct Map_S* map); /**physics*<*/
	void(*touch) (struct Map_S* map, struct Entity_S* other); /**collsions*<*/
}Map_S;

/**
*
*@brief allocates a space in the master Entity-List for a map of a given filename (PNG)? or BMP?? Also gives the Map a specific name and loads associates a background sprite
*@param filename: the name of the map associated with the entity
*@param SizeX: the final width of the background when it's drawn
*@param SizeY: the final height of the background when it's drawn
*@param bgfilename: the name of the file to make the associated background image
*@return Map_M: returns a Map_M object the primary Entity.
*/
Map_S mapNew( const char* filename, int SizeX, int SizeY, const char* bgfilename,  int bgSizeX,int bgSizeY);// the size of the backgrounds should be made unified
void mapFree(Map_S map);

// include entity think / touch/ draw / update / and such

void mapthink( Map_S* map, Player_S player);
void mapupdate( Map_S* map);
void maptouch(Map_S* map, Entity_S* other);
#endif