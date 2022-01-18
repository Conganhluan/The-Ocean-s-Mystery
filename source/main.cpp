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
bool Death = false;
bool Winning1 = false;
bool Winning2 = false;

int main(int arc, char* argv[] ){
	//Khoi tao moi thu
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("Da trang thoat Me cung",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    font = TTF_OpenFont("Vtimesb.ttf", 30);
    std::string noidung = "Lêu Lêu";
    SDL_Surface* chu = TTF_RenderText_Solid(font,noidung.c_str(),mauchu);
    anhNen=IMG_Load("hinhnen.png");
    game::taoAnhNen();
    game::ganAnh(chu,100,100);
    texture = SDL_CreateTextureFromSurface(renderer,tempAnhNen);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    SDL_RenderPresent(renderer);
    
    //Tro choi
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type==SDL_KEYDOWN || event.key.keysym.sym==SDLK_ESCAPE) 
                isRunning=false;
        }
    }

	//Huy moi thu
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
    SDL_FreeSurface(anhNen);
    SDL_FreeSurface(tempAnhNen);
	SDL_Quit();
	return 0;
}

