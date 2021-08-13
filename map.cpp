#include <string.h>
#include"sprite.h"
#include"vector.h"
#include"background.h"
#include"map.h"
#include"entity.h"

extern SDL_Renderer* gRenderer;


Map_S mapNew(const char* filename, int SizeX, int SizeY, const char* bgfilename, int bgSizeX, int bgSizeY)
 {
	//BG sprites will be loaded at a set size of: 
	
	Map_S map;  
	Entity_S* temp;
	temp = EntityNew();
	Sprite_S* temp_spr = spriteLoad(filename, SizeX,SizeY ); 
	map.Init_map_position.x = 0;
	map.Init_map_position.y = 150;
	map.Init_bg_position.x = 0;
	map.Init_bg_position.y = 0;


	if (temp == NULL)
	{
		slog("Falied to create a Map Entity");
		//return NULL;
		

	}
	map.MAP = temp;

	
	if (&temp_spr == NULL)
	{
		slog("Failed to create a sprite for the Map Entity");
		//return NULL;

	}
	map.MAP->sprite = temp_spr;// the road

	map.bg_sky = backgroundLoad(bgfilename, bgSizeX, bgSizeY); // the sky
	strncpy_s(map.MAP->name, filename, 20);

	return map;

}


void mapFree(Map_S* map)
{
	//spriteFree(map->MAP->sprite);
	//spriteFree();
	//entityFree(&map->MAP);


}



void mapDraw(Map_S map) ///technically the ,mapo it entity #1 so consider not using this in later implementastions
{

	spriteDraw(map.bg_sky.sky, gRenderer, 0, map.Init_bg_position);// TODO REFACTOR TO A MAP  -works with an entity or  sprite created
	spriteDraw(map.MAP->sprite, gRenderer, 0, map.Init_map_position);// TODO REFACTOR TO A MAP  -works with an entity or  sprite created




}