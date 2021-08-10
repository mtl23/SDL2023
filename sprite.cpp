#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "vector.h"
#include "SDL.h"
#include "graphics.h"
#include "simple_logger.h"

extern SDL_Window* gWindow;
extern SDL_Surface* temp;
extern SDL_Renderer* gRenderer;

Sprite_S* spriteList = NULL;
int numSprites = 0;
int spriteMax = 100;

bool InitSpriteSystem()
{
	spriteList = (Sprite_S*)malloc(sizeof(Sprite_S) * (spriteMax));

	if (spriteList == NULL)
	{
		//slog("failed to initialize sprite system. STILL NULL");
		return false;
	}
	memset(spriteList, 0, sizeof(Sprite_S) * (spriteMax));
	//slog("sprite system is go");
	return true;
}


void CloseSpriteSystem()
{
	int i;
	if (!spriteList)
	{
		return;
	}
	for (i = 0; i < spriteMax; i++)
	{
		if (spriteList[i].image != 0)
		{
			spriteFree(&spriteList[i]);
		}
	}
	//slog("sprite system is closed");
	free(spriteList);
	spriteList = NULL;
	spriteMax = 0;
}

Sprite_S* spriteLoad(const char* filename, int sizeX, int sizeY)
{
	int i;
	SDL_Surface* temp;
	SDL_Texture* myTex;
	/*first search to see if the requested sprite image is alreday loaded*/
	for (i = 0; i < numSprites; i++)
	{
		if (!spriteList)
		{
			//slog("WARNING! no sprite list to lookup!");
		}

		if (strncmp(filename, spriteList[i].filename, 20) == 0)
		{
			//	slog("already loaded");
			spriteList[i].refcount++;
			spriteList[i].framesPerLine = 16;
			spriteList[i].frameW = sizeX;
			spriteList[i].frameH = sizeY;
			spriteList[i].imageW = sizeX;
			spriteList[i].imageH = sizeY;
			//spriteList[i].color.r = 200;
			//spriteList[i].color.b = 200;
			//spriteList[i].color.g = 200;
			spriteList[i].angle = 0;
			return &spriteList[i];
		}
	}
	/*makesure we have the room for a new sprite*/
	if (numSprites + 1 >= spriteMax)
	{
		//slog("Maximum Sprites Reached.");
		exit(1);
	}
	/*if its not already in memory, then load it.*/
	numSprites++;
	for (i = 0; i <= numSprites; i++)
	{
		if (!spriteList[i].refcount)break;
	}
	temp = IMG_Load(filename);
	if (temp == NULL)
	{
		printf("unable to load a vital sprite: %s", SDL_GetError());
		return NULL;
	}
	 printf("loaded a sprite for the first time");
	myTex = SDL_CreateTextureFromSurface(gRenderer, temp);
	spriteList[i].image = myTex;
	/*sets a transparent color for blitting.*/
	/*then copy the given information to the sprite*/
	strncpy_s(spriteList[i].filename, filename, 20);
	/*now sprites don't have to be 16 frames per line, but most will be.*/
	spriteList[i].frameW = sizeX;
	spriteList[i].frameH = sizeY; 
	spriteList[i].imageW = sizeX;
	spriteList[i].imageH = sizeY;
	spriteList[i].refcount++;
	spriteList[i].angle = 0;
	spriteList[i].framesPerLine = 16;
	return &spriteList[i];
}

void spriteFree(Sprite_S* sprite)
{
	/*first lets check to see if the sprite is still being used.*/
	sprite->refcount--;
	if (sprite->refcount == 0)
	{
		strncpy_s(sprite->filename, "\0",20);
		sprite->image = NULL;
	}
	if (sprite->refcount <= 0)
	{
		strncpy_s(sprite->filename, "\0",20);
		SDL_DestroyTexture(sprite->image);
		memset(sprite, 0, sizeof(sprite));
	}
	sprite = NULL;

}
void spriteDraw(Sprite_S* sprite, SDL_Renderer* renderer, int frame, Vector2D position)
{


	SDL_Rect rect;//where on the sprite sheet? //this has to be changed with varibnles 
	SDL_Rect dest;

	rect.x = frame % sprite->framesPerLine * sprite->frameW;
	rect.y = frame / sprite->framesPerLine * sprite->frameH;
	rect.w = sprite->frameW;
	rect.h = sprite->frameH;

	dest.x = position.x;
	dest.y = position.y;
	dest.w = sprite->frameW;
	dest.h = sprite->frameH;

	//find sprite to draw in the list
   //slog("looking for sprite to draw");
	int i;
	for (i = 0; i <= spriteMax; i++)
	{
		if (spriteList[i].image == sprite->image)
		{
			//slog("Drawing");
			// send sprite texture to renderer
			//SDL_SetTextureColorMod(spriteList[i].image,spriteList[i].color.r,spriteList[i].color.g,spriteList[i].color.b);
			//slog("%d",spriteList[i].angle);
			SDL_RenderCopyEx(renderer, spriteList[i].image, &rect, &dest, spriteList[i].angle, NULL, SDL_FLIP_NONE); //tell the renderer theres something you want to do 
		}
		//printf("Finished looking for a sprite to draw in the list\n");
	}

}