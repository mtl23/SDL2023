#ifndef __MAP_H__
#define __MAP_H__

#include <SDL.h>
#include <SDL_image.h>
#include"sprite.h"
#include"vector.h"
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
	char bg_name[24];
	Background_M* bg_sky;
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
Map_S* mapLoad( const char* filename, int SizeX, int SizeY, const char* bgfilename,  int bgSizeX,int bgSizeY);// the size of the backgrounds should be made unified
void mapFree(Map_S* map);
void mapDraw(Map_S* map, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition); ///technically the ,mapo it entity #1 so consider not using this in later implementastions

// map draw will likely need to be refactored, with more parameters for how to draw floor and sky


// include entity think / touch/ draw / update / and such


#endif