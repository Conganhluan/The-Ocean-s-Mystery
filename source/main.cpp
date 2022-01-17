#include"mainThings.h"
#undef main

int main(int arc, char* argv[] ){
	if (!game::init()) return -1

	
	
	//Clean up
	game::destroy();
	SDL_Quit();
	return 0;
}