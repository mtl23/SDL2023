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

	map.bg_sky = backgroundLoad(bgfilename, bgSizeX, bgSizeY, map.Init_bg_position); // the sky
	strncpy_s(map.MAP->name, filename, 20);
	map.MAP->position.x = map.Init_map_position.x;
	map.MAP->position.y = map.Init_map_position.y;
	map.MAP->is_UI= 0;
	map.MAP->velocity= 0;
	map.MAP->accel= 0;
	map.MAP->is_Map= 1;
	map.MAP->is_car = 0;
	map.MAP->is_AI = 0;
	map.MAP->is_Obstacle = 0;
	map.MAP->draw = &entityDraw;// this does no account for the background
	map.MAP->think = &mapThink;
	return map;

}


void mapFree(Map_S* map)
{
	//spriteFree(map->MAP->sprite);
	//spriteFree();
	//entityFree(&map->MAP);


}

void mapthink(Map_S* self)
{}
void mapupdate(Map_S* self)
{}
void maptouch(Map_S* self, Entity_S* other)
{}

