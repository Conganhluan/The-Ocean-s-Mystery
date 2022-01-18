#include"mainThings.h"
#undef main

//Cac bien moi truong
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* anhNen = NULL;
SDL_Texture* texture = NULL;
Mix_Music* nhacNen = NULL;
SDL_Event event;

//Cac bien phu
int Timehientai = 0;
bool isRunning = true;
short Money = 50;
short Favor = 50;
short Oxygen = 100;
short Trans = 0;
short Influ = 20;
short ketThuc = 0;
short khungNen = 1;
short turn = 0;
short nenHientai = 0;

int main(int arc, char* argv[] ){
	
    //Khoi tao moi thu
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("Thoát khỏi vua Thủy Tề",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    Mix_Init(0);
    


    //Tro choi
    while (isRunning) {
        if (khungNen!=nenHientai) game::showNen(khungNen);
        switch (khungNen) {
            case 1: {
                while (SDL_PollEvent(&event)!=0) {
                    if (event.type==SDL_KEYDOWN) switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE: isRunning = false;
                    }
                    else if (event.type==SDL_QUIT) isRunning = false;
                }
                break;
            }
            default: isRunning = false;
        }
        
        
        nenHientai = khungNen;
    }



	//Huy moi thu
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
    SDL_FreeSurface(anhNen);
    SDL_DestroyTexture(texture);
	SDL_Quit();
	return 0;
}

