#include <string.h>
#include"sprite.h"
#include"vector.h"
#include"background.h"
#include"map.h"
#include"entity.h"



Map_S* mapNew(const char* filename, int SizeX, int SizeY, const char* bgfilename, int bgSizeX, int bgSizeY)
 {
	//BG sprites will be loaded at a set size of: 
	
	Map_S map;
  
	//Entity_S* temp;
	//temp = EntityNew();
	//Sprite_S temp_spr = *spriteLoad(filename, 100,100 ); //change numbers

	//map.MAP = temp;

	//if (map.MAP == NULL)
	//{
	//	slog("Falied to create a Map Entity");
	//	return NULL;
	//	

	//}

	//map.MAP->sprite = &temp_spr;// the road
	//
	//if (map.MAP->sprite == NULL)
	//{
	//	slog("Failed to create a sprite for the Map Entity");
	//	return NULL;

	//}
	
	map.bg_sky = backgroundLoad(bgfilename, bgSizeX, bgSizeY); // the sky

	if (map.bg_sky==NULL)
	{

		slog("Falied to create a background sprite");
		return NULL;
	}

	strncpy_s(map.bg_name, bgfilename, 20);
	//strncpy_s(map.MAP->name, "map", 20);

	return &map;

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