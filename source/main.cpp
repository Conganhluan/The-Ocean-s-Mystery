#undef main

int main(int arc, char* argv[] )
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	window = SDL_CreateWindow("Nothing here",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,0);
	renderer = SDL_CreateRenderer(window,0,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
	//cleans up all initialized subsystems
	SDL_Quit();
	return 0;
}