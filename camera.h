#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <SDL.h>
#include <SDL_image.h>
#include "sprite.h"
#include "vector.h"
#include "simple_logger.h"
#include "background.h"
#include "entity.h"
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


	/// /do i even need these??
	void(*think) (struct Camera_S* self); /**logic*<*/
	void(*update) (struct Camera_S* self); /**physics*<*/
	void(*touch) (struct Camera_S* self, struct Entity_S* other); /**collions*<*/
}Camera_S;


void CameraInit( Map_S map,Player_S player,Camera_S cam);// need to create a player obj fot this to work
#endif