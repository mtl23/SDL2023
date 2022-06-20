#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "car.h"
#include "camera.h"
#include "entity.h"
#include "vector.h"
#include "simple_logger.h"
#include "camera.h"

extern SDL_Renderer* gRenderer;

Entity_S* entityList = NULL;
int numEntity = 0;
int entityMax = 500;

extern int SCREEN_HEIGHT_OFFSET;//revert to zero
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

extern Map_S M0deS3v3n;

extern Camera_S MainCam; //hopefully this help as a workaround to adding camera.h


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
		slog("NEW ENTITY at index: %i", i);

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
	

	    //check if we are drawing the car
	     
	if (entity->is_Map)
	{
		//adjust the camera  position here, by tis time cam position has taken over for the drawing over init_map position
	    //slog("Map posistion is %f, %f", M0deS3v3n.Init_map_position.x, M0deS3v3n.Init_map_position.y);
		//slog("Camera posistion is %f, %f", cam.Init_cam_position.x, cam.Init_cam_position.y);
		//M0deS3v3n.Init_map_position.x = cam.position.x;
		//M0deS3v3n.Init_map_position.y = cam.position.y;
			}
	
	if(entity->is_car)
		 {
			 //adjust the camera  position here, by tis time cam position has taken over for the drawing over init_map position
			// slog("Map posistion is %f, %f", M0deS3v3n.Init_map_position.x, M0deS3v3n.Init_map_position.y);
			// slog("Camera posistion is %f, %f", cam.Init_cam_position.x, cam.Init_cam_position.y);

		 }
		spriteDraw(entity->sprite, gRenderer, frame, position);// currently this draws the map, but how do i conorporate the camera in this?
	


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
		//12/12 the 0 entity should be the map and 1 the car so they are drawn in that order. fix this
		if (entityList[i].is_Map == 1) // draw the map relative to what the camera can see
		{
			entityList[i].draw(&entityList[i], gRenderer, entityList[i].sprite->frame, MainCam.position);

		}
		else if(entityList[i].is_car == 1) {

			// TO DO only draw these entities if the are in range of the camera.
			entityList[i].draw(&entityList[i], gRenderer, entityList[i].sprite->frame, entityList[i].position);
			}
	}
}

void carThink(Entity_S* self)// moves the cars position on the map, and consquencially the map is drawn on a new location on the screen.
{
	
	slog(" state: %i -- Cars y pos %f", self->state, MainCam.position.y);


	          /*         car has hit the top              ||                car has hit the bottom                              */
	//if (MainCam.position.y >= float(SCREEN_HEIGHT_OFFSET) || MainCam.position.y <= (((SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET) - (self->sprite->imageH + (self->sprite->imageH/1.995) ))*-1))//change direction
	//{
	//	
	
		
		if (self->state > 4)
		{
			self->state = 0;
		}
		switch(self->state)
		{
				case(0): //State 0 at the start going up
					{
					//slog("Car's y pos %f", MainCam.position.y);
					if (MainCam.position.y >= float(SCREEN_HEIGHT_OFFSET))
					{

						self->state++;
						self->velocity.y = self->velocity.y * -1;
					}
					break;

				    }

				case(1)://State 1 going down to the bottom 

				{
					if (MainCam.position.y <= (((SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET) - (self->sprite->imageH + (self->sprite->imageH / 1.995))) * -1))
					{

						self->state++;
						self->velocity.y = self->velocity.y * -1;
					}
					break;

				};

				case(2): //State 2 goes to the center of the screen, then to the far left
				{
					//self->velocity.y = self->velocity.y * -1;// go back up 
					if (MainCam.position.y >= -1 * (160))// TO DO once centered scroll to the right
					{

						slog("here");
						self->velocity.y = 0;
						self->velocity.x = -1;
					}


					

					if (MainCam.position.x >= -1 * (160000000)) // TO DO  reached the far right check how to swing them back to the left
					{

						self->velocity.x = self->velocity.x * -1;
						self->state++;
					}					
					break;

				};

		
				case(3): // State 3 goes from the far right to the far left
				{

					if (MainCam.position.x >= -1 * (160000000)) // TO DO reached the far left check how to swing them back toward the center
					{

						self->velocity.x = self->velocity.x * -1;
						self->state++;
					}
					break;

				};
				
				case(4): //State 4  reached at the center of the map again, go up again,  state to reset to zero
				{

					if (MainCam.position.y >= -1 * (16000000000))  // TO DO check how to swing them back toward the center
					{
						
						self->velocity.y = 1;
						self->velocity.x = 0;
						self->state++;
					}
					break;
				};

		
				default:
				{
					//self->velocity = self->velocity * -1;
					break;
				};

		//} //end if 

	   
		
		slog(" state: %i -- Cars y pos %f", self->state, MainCam.position.y);
	}
	MainCam.position.x = MainCam.position.x + self->velocity.x; // movbes the map based on the cars velocity Ypos
	MainCam.position.y = MainCam.position.y + self->velocity.y; // movbes the map based on the cars velocity Ypos
	//slog("Cars lower bound is %i, whe position is this, go back up ", ((SCREEN_HEIGHT - SCREEN_HEIGHT_OFFSET) - self->sprite->imageH) * -1);
	

}



float GetXOrigin(Entity_S* self)
{
	return self->position.x;
}

float GetYOrigin(Entity_S* self)
{
	return self->position.y;
} 