#include "SDL_mixer.h" 
#include <SDL.h>


void changeMusic(const char* song)
{

	Mix_Music* newSong;
	newSong = Mix_LoadMUS(song);
	Mix_PlayMusic(newSong, -1);

}