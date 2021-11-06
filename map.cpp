#include <string.h>
#include"sprite.h"
#include"vector.h"
#include"background.h"
#include"map.h"
#include"camera.h"
#include"entity.h"

extern SDL_Renderer* gRenderer;
extern Camera_S cam;

Map_S mapNew(const char* filename, int SizeX, int SizeY, const char* bgfilename, int bgSizeX, int bgSizeY)
 {
	//BG sprites will be loaded at a set size of: 
	
	Map_S map;  
	Entity_S* temp;
	temp = EntityNew();
	Sprite_S* temp_spr = spriteLoad(filename, SizeX, SizeY ); 
	map.Init_map_position.x = -450; // to position of the map, not the position of the camera. Make these ubiform //camera rect must be the same size as map rect??
	map.Init_map_position.y = -150; // There fore, change map position var as the car moves, and update cam position accordingly. (0,0) is the top left corner
	cam.Init_cam_position.x = map.Init_map_position.x;
	cam.Init_cam_position.y = map.Init_map_position.y;
	cam.position.x = map.Init_map_position.x;
	cam.position.y = map.Init_map_position.y;

	
	//map.Init_bg_position.x = 0;
	//map.Init_bg_position.y = 0;//adjust this when the bg is renabled
	map.Map_size.x = SizeX;
	map.Map_size.y = SizeY;
	
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

	//map.bg_sky = backgroundLoad(bgfilename, bgSizeX, bgSizeY, map.Init_bg_position); // the sky
	strncpy_s(map.MAP->name, filename, 20);
	map.MAP->position.x = map.Init_map_position.x; //change thi s as the car moves too
	map.MAP->position.y = map.Init_map_position.y; // change this as the car moves too
	map.MAP->is_UI= 0;
	map.MAP->velocity= 0;
	map.MAP->accel= 0;
	map.MAP->is_Map= 1;
	map.MAP->is_car = 0;
	map.MAP->is_AI = 0;
	map.MAP->is_Obstacle = 0;
	map.MAP->draw = &entityDraw;// this does not account for the background
	return map;

}


void mapFree(Map_S* map)
{
	//spriteFree(map->MAP->sprite);
	//spriteFree();
	//entityFree(&map->MAP);


}
void mapthink(Map_S* map, Player_S player)
{}
void mapupdate(Map_S* map)
{}
void maptouch(Map_S* map, Entity_S* other)
{}

