#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "entity.h"
#include "vector.h"
#include "simple_logger.h"


extern SDL_Renderer* gRenderer;

Entity_S* entityList = NULL;
int numEntity = 0;
int entityMax = 500;


bool InitEntitySystem(int EntityMax)
{

	if (numEntity == entityMax)
	{
		slog("Cannot init entities");
		return false;
	}
	entityList = (Entity_S*)malloc(sizeof(Entity_S) * (entityMax));

	if (entityList == NULL)
	{
		slog("failed to initialize entity system. STILL NULL");
		return false;

	}
	memset(entityList, 0, sizeof(Entity_S) * (entityMax));
	slog("Entity system is go");
	atexit(CloseEntitySystem);
	return true;
}

void CloseEntitySystem()

{
	if (!entityList)
	{
		return;
	}

	slog("entity system is closed");
	free(entityList);
	entityList = NULL;
	numEntity = 0;
}

Entity_S* EntityNew()
{
	int i;
	for (i = 0; i < entityMax; i++)
	{
		if (entityList[i].inuse)
		{
			continue;
		}
		memset(&entityList[i], 0, sizeof(Entity_S));
		entityList[i].inuse = 1;
		slog("NEW ENTITY");
		if (!&entityList[i])
		{
			slog("ENTITY ALLOCATION FAILED");
			return NULL;
		}

		return &entityList[i];
	}
}
void entityFree(Entity_S** entity)
{
	(*entity)->inuse = 0;
	*entity = NULL;

}

void entityFreeAll(Entity_S** list)
{
	int i;
	for (i = 0; i < entityMax; i++)
	{
		entityFree(&list[i]);// need to be tested
	}
}
Entity_S* entityLoad(char* filename, Vector2D position) //should load the sprite of entity if needed
{
	int i;
	Entity_S* temp;
	temp = EntityNew();
	Sprite_S temp_spr = *spriteLoad(filename, position.x, position.y);


	/*makesure we have the room for a entity*/
	if (numEntity + 1 >= entityMax)
	{
		slog("Maximum Entities Reached.");
		exit(1);
	}
	/*if its not already in memory, then load it.*/

	numEntity++;
	temp->sprite = &temp_spr;
	strncpy(temp->name, temp_spr.filename, 20);
	for (i = 0; i <= numEntity; i++)
	{
		if (entityList[i].inuse)break;
	}

	if (&temp == NULL)
	{
		slog("unable to load a vital sprite: %s", SDL_GetError());
		exit(0);
	}
	slog("loaded an entity for the first time");


	temp->inuse = 1;
	return temp;
}

void entityDraw(Entity_S* entity, SDL_Renderer* renderer, int frame, Vector2D position)
{
	if ((!entity) || (!renderer))
	{

		slog("no valid entity or renderer");
		return;
	}

	if (!&entity->sprite)
	{

		slog("no valid entity sprite");
		return;
	}
	spriteDraw(entity->sprite, gRenderer, frame, position);
}

void entityThinkAll()
{
	int i;
	for (i = 0; i < entityMax; i++)
	{
		if (!entityList[i].inuse)
		{
			continue;
		}
		if (!entityList[i].think)
		{
			continue;
		}
		entityList[i].think(&entityList[i]);
	}
}

void entityUpdateAll()
{
	int i;
	for (i = 0; i < entityMax; i++)
	{
		if (!entityList[i].inuse)
		{
			continue;
		}
		if (!entityList[i].update)
		{
			continue;
		}
		entityList[i].update(&entityList[i]);

	}

}

void entityDrawAll()
{
	int i;
	for (i = 0; i < entityMax; i++)
	{
		if (!entityList[i].inuse)
		{
			continue;
		}
		if (!entityList[i].draw)
		{
			continue;
		}
		entityList[i].draw(&entityList[i], gRenderer);
	}

}