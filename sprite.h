#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
#include <SDL_image.h>
#include "vector.h"
/**
* @basic Sprite struct
**/
//typedef struct {
//
//	float y; /**<the y component of the sprite in local coordinates */
//	float x; /**<the x component of the center  of the sprite */
//	float h; /**<the h component of the center of the sprite   */
//	float w; /**<the w component of the sprite */
//	float refcount;
//	float inuse = 0; //used as a boolean
//	char filename[24];// assidned names of the sprite
//	SDL_Renderer* renderer;// the desired renderer to draw to
//	int frame;
//	int frameW;
//	int frameH;
//	int framesPerLine;
//	float angle;
//	Vector3D color;
//	SDL_Texture* image;
//
//}Sprite_M;



typedef struct Sprite_S

{
	int refcount;
	char filename[32];
	SDL_Texture* image;
	int imageW;
	int imageH;
	float angle;
	int frame;
	int frameW;
	int frameH;
	int framesPerLine;
	Vector3D color;

}Sprite_S;


/**
*
*@brief creates the sptite system, should be used once at game start
*/
bool InitSpriteSystem();

/**
*
*@brief closes the sptite system, should be used once at game end
*/
void CloseSpriteSystem();

/**
*
*@brief allocates a space in the master Sprite-List for a sprite of a given filename (PNG)
*@param filename: the filename of the srpite associated with the entity
*@param sizeX: the final width of the sprite when its drawn
*@param sizeX: the final height of the sprite when its drawn
*@return Sprite_M: returns a Sprite_M object so that it can be saved for later. This is necessary to use spriteDraw()
*/
Sprite_S* spriteLoad(const char* filename, int sizeX, int sizeY);



/**
*
*@brief frees a single sprite back to memory
 @param *sprite: pointer to the sprite that you wish to free
*/

void spriteDraw(Sprite_S* sprite, SDL_Renderer* renderer, int frame, Vector2D position);
void spriteFree(Sprite_S* sprite);
#endif