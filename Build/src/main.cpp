#include"mainThings.h"
#include"Events.h"
#undef main

//Các biến môi trường
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* anhNen = NULL;
SDL_Texture* texture = NULL;
Mix_Music* nhacNen = NULL;
SDL_Event event;

//Các biến phụ
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
bool stt[30];

int main(int arc, char* argv[] ){
	
    //Khởi tạo mọi thứ
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("The Ocean's Mystery",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    Mix_Init(0);
    memset(stt,false,sizeof(stt[0]*30));
    Mix_OpenAudio();


    //Trò chơi
    while (isRunning) {
        if (khungNen!=nenHientai) game::showNen(khungNen);
        switch (khungNen) {
            case 1:
                int temp;
                do {
                    temp=game::layRandom();
                } while (stt[temp]!=)
                break;
            case 2: 

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                
                break;
            default: isRunning = false;
        }
        
        
        nenHientai = khungNen;
    }



	//Hủy mọi thứ
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
    SDL_FreeSurface(anhNen);
    SDL_DestroyTexture(texture);
	SDL_Quit();
	return 0;
}

