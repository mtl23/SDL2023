#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL.h>
#include <SDL_image.h>
#include "vector.h"
#include "map.h"
#include "player.h"

typedef struct Camera_S

{
	Map_S* MAP;
	Background_M bg_sky;
	Player_S player;
	Vector2D Init_cam_position;
	Vector2D Cam_size;
	SDL_Rect Cam_rect; //uses the above Vector 2Ds to create this
	Vector2D Map_size;
	//void(*draw) ( struct Camera_S* self ,struct Map_S* map, SDL_Renderer* renderer, int frame, Vector2D destPosition); /**logic*<*/

}Camera_S;


Camera_S CameraInit( Map_S map,Player_S player);
//void Cameradraw(Camera_S* self, Map_S* map, SDL_Renderer* renderer, int frame, Vector2D destPosition);
#endif