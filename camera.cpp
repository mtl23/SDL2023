#include <SDL.h>
#include <SDL_image.h>
#include "sprite.h"
#include "vector.h"
#include "simple_logger.h"
#include "background.h"
#include "entity.h"
#include "map.h"
#include "player.h"
#include "camera.h"


/// why does this extern not work without setting value again.
/// see init and entity.cpps

extern int SCREEN_HEIGHT_OFFSET = 0;//revert to zero
extern int SCREEN_WIDTH = 512;
extern int SCREEN_HEIGHT = 512 + SCREEN_HEIGHT_OFFSET;

 Camera_S CameraInit()//(Map_S map, Player_S player) //update the player and map for the camera, not responsible for changing the background.
{

	 Camera_S cam;

	//cam.MAP = &map;
	cam.Cam_size.x = SCREEN_WIDTH;
	cam.Cam_size.y = SCREEN_HEIGHT;
	cam.Init_cam_position.x = 50;
	cam.Init_cam_position.y = 50;
	cam.Cam_rect.x= cam.Init_cam_position.x;
	cam.Cam_rect.y= cam.Init_cam_position.y;
	cam.Cam_rect.w= cam.Cam_size.x;
	cam.Cam_rect.h= cam.Cam_size.y;
	//cam.player = player;
	//cam.draw = Cameradraw;

	return cam;
}

 void Cameradraw ( Camera_S* self,  Map_S* map, SDL_Renderer* renderer, int frame, Vector2D destPosition) /**logic*<*/
 {
 
 
 }