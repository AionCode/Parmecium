#include <SDL/SDL_mixer.h>

// init SDL_mixer
if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096))
{
	fprintf(stderr, "SDL_Mixer Error: %s\n", Mix_GetError());
	exit(1);
}

Mix_Chunk* explosionogg = Mix_LoadWAV("data/music/wellcome.wav");	
if (!explosionogg)
{
	fprintf(stderr, "SDL_mixer Error: %s\n", Mix_GetError());
	exit(1);
}

if (!keyboard->keywaspressed[SDLK_SPACE])
{
	if (keyboard->key[SDLK_SPACE])
	{
		keyboard->keywaspressed[SDLK_SPACE] = true;
	}
}
else
{
	// play audio clip
	if (Mix_PlayChannel(-1, explosionogg, 0) < 0)
	{
		fprintf(stderr, "SDL_mixer Error: %s\n", Mix_GetError());
	}
	keyboard->keywaspressed[SDLK_SPACE] = false;
}

// free the audio sample
Mix_FreeChunk(wellcomewav);

// shut down SDL_mixer
Mix_CloseAudio();