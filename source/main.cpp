#include"mainThings.h"
#undef main

//Khai bao bien moi truong
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* anhNen = NULL;
SDL_Surface* tempAnhNen = NULL;
SDL_Texture* texture = NULL;
Mix_Music* nhacNen = NULL;
TTF_Font* font = NULL;
SDL_Color mauchu = {0, 0, 0};
SDL_Event event;

//Cac bien phu
int Timehientai = 0;
bool isRunning = true;
short Money = 50;
short Favor = 50;
short Oxygen = 100;
short Trans = 0;
short Influ = 20;
bool Death1 = false;
bool Death2 = false;
bool Death3 = false;
bool Death4 = false;
bool Death5 = false;
bool Winning1 = false;
bool Winning2 = false;
bool Winning3 = false;

int main(int arc, char* argv[] ){
	//Khoi tao moi thu
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("Thoát khỏi vua Thủy Tề",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    //TTF_Init();
    Mix_Init(0);
    //font = TTF_OpenFont("Vtimesb.ttf", 24);
    //std::string noidung = "Lêu Lêu";
    //SDL_Surface* chu = TTF_RenderText_Solid(font,noidung.c_str(),mauchu);
    //game::ganAnh(chu,100,100);
    texture = IMG_LoadTexture(renderer,"hinhnen.jpg");
    if (texture==NULL) SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_RenderClear(renderer);
    //Tro choi
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type==SDL_KEYDOWN || event.key.keysym.sym==SDLK_ESCAPE) 
                isRunning=false;
        }
        SDL_RenderCopy(renderer,texture,NULL,NULL);
        SDL_RenderPresent(renderer);
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

