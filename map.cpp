#include <string.h>
#include"sprite.h"
#include"vector.h"
#include"background.h"
#include"map.h"
#include"entity.h"



Map_S* mapLoad(const char* filename, int SizeX, int SizeY, const char* bgfilename, int bgSizeX, int bgSizeY)
{
	//BG sprites will be loaded at a set size of: 
	
	struct Map_S temp;

	temp.MAP = EntityNew();// the map is our frst entity
	if (temp.MAP== NULL)
	{
		slog("Falied to create a Map Entity");
		return NULL;
		

	}
	strncpy_s(temp.MAP->name, "map", 20);

	temp.MAP->sprite = spriteLoad(filename,SizeX,SizeY);// the road
	
	if (temp.MAP->sprite == NULL)
	{
		slog("Failed to create a sprite for the Map Entity");
		return NULL;

	}

	temp.bg_sky = backgroundLoad(bgfilename, bgSizeX, bgSizeY); // the sky
	strncpy_s(temp.bg_name, bgfilename, 20);

	if (temp.bg_sky==NULL)
	{

		slog("Falied to create a background sprite");
		return NULL;
	}


	return &temp;

}


void mapFree(Map_S* map)
{
	spriteFree(map->MAP->sprite);
	spriteFree(map->bg_sky->sky);
	entityFree(&map->MAP);


}



void mapDraw(Map_S* map, SDL_Renderer* renderer, Vector2D destPosition, Vector2D imgPosition) ///technically the ,mapo it entity #1 so consider not using this in later implementastions
{





}