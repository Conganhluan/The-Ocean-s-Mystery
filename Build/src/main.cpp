#include"mainThings.h"
#include"Events.h"
#include"Attributes.h"
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
short Money = 32;
short Favor = 32;
short Oxygen = 64;
short Trans = 0;
short Influ = 15;
short ketThuc = 0;
short khungNen = 3;
short turn = 0;
short nenHientai = 0;
bool stt[30];
bool collection[4];
bool Save=false;
SDL_Surface* att1 = NULL;
SDL_Surface* att2 = NULL;
SDL_Surface* att3 = NULL;
SDL_Surface* att4 = NULL;
SDL_Surface* att5 = NULL;
SDL_Rect rect1 = {46,42,64,64};
SDL_Rect rect2 = {188,42,64,64};
SDL_Rect rect3 = {330,42,64,64};
SDL_Rect rect4 = {472,42,64,64};
SDL_Rect rect5 = {614,42,64,64};
short chuoi[20] = {1,2,3,2,1,1,2,2,3,2,3,2,1,1,1,1,1,1,1,3};
short reNhanh=0;


int main(int arc, char* argv[] ){
	
    //Khởi tạo mọi thứ
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("The Ocean's Mystery",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 138, 188, 222, 0);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    nhacNen = Mix_LoadMUS("nhacNen.mp3");
    Mix_VolumeMusic(30);
    Mix_PlayMusic(nhacNen,-1);
    game::napAttributes();
    memset(stt,false,30);
    memset(collection,false,4);
    game::nhapfileCache();
    if (!Save) khungNen=7;

    //Trò chơi
    while (isRunning) {
        if (khungNen!=nenHientai) game::showNen(khungNen);
        switch (khungNen) {
            case 1: {
                if (!Save) {
                    Save=true;
                    game::inLoigioithieu();
                    SDL_Delay(10000);
                    SDL_RenderClear(renderer);
                    game::showNen(khungNen);
                }
                game::showAttributes();
                if (turn==0 && turn==4) {
                    game::inSukien(0,turn);
                    bool stop = false;
                    while (!stop) {  
                        while (SDL_PollEvent(&event)!=0) {
                            if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE) {
                                if (turn==4) (Favor>=45 && Influ>=45 && Oxygen>=25 && Money>=25 && Trans>=25)?reNhanh=2:reNhanh=1;
                                if (reNhanh!=0) khungNen=2;
                                turn++;
                            }
                            else if (event.type==SDL_QUIT) isRunning = false;
                            if (event.type==SDL_MOUSEBUTTONDOWN) {
                                if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) khungNen = 6;
                                else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) khungNen = 3;
                            }
                        }
                        if (turn!=0 || turn!=4 || khungNen!=1) stop = true;
                    }
                }
                else {
                    int random;
                    do {random=game::layRandom();} while (stt[random]);
                    stt[random]=true;
                    Sukien sukien(random);
                    show(sukien);
                    bool stopHere = false;
                    while (!stopHere) {
                        while (SDL_PollEvent(&event)) {
                            short luachon = 0;
                            switch (event.type) {
                                case SDL_MOUSEBUTTONDOWN: {
                                    if (event.button.x>92 && event.button.x<326 && event.button.y>418 && event.button.y<542) luachon=100;
                                    else if (event.button.x>398 && event.button.x<632 && event.button.y>418 && event.button.y<542) luachon=200;
                                    else if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) khungNen = 6;
                                    else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) khungNen = 3;
                                    if (luachon==100 || luachon==200) {   
                                        sukien.thaydoi(luachon);
                                        if (luachon==100) explain(sukien,false); else explain(sukien,true);
                                        SDL_Delay(5000);
                                        turn++;
                                        if (ketThuc!=0) game::inKetthuc(ketThuc);
                                    }
                                    break;
                                }
                                case SDL_QUIT:{
                                    isRunning = false;
                                    break; 
                                }   
                            }
                            if (luachon!=0 || khungNen!=1 || !isRunning) stopHere = true;
                        }
                    }
                }
            }
            
            case 2: {
                game::showAttributes();
                if (turn==5 || turn==9 || turn==13) {
                    game::inSukien(reNhanh,turn);
                    if (turn==5) collection[0]=1;
                    else if (turn==9) collection[1]=1;
                    else if (turn==13) collection[2]=collection[3]=1;
                    while (SDL_PollEvent(&event)!=0) {
                        if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE) turn++;
                        else if (event.type==SDL_QUIT) isRunning = false;
                    }
                    turn++;
                    if (turn==14) {
                        if (reNhanh==1) ketThuc=9;
                        else ketThuc=10;
                        game::inKetthuc(ketThuc);
                    }
                }
                else {
                    int random;
                    do {random=game::layRandom();} while (stt[random]);
                    stt[random]=true;
                    Sukien sukien(random);
                    show(sukien);
                    bool stop = false;
                    while (!stop) {
                        while (SDL_PollEvent(&event)) {
                            switch (event.type) {
                                case SDL_MOUSEBUTTONDOWN: {
                                    short luachon = 0;
                                    if (event.button.x>92 && event.button.x<326 && event.button.y>418 && event.button.y<542) luachon=100;
                                    else if (event.button.x>398 && event.button.x<632 && event.button.y>418 && event.button.y<542) luachon=200;
                                    if (luachon==100 || luachon==200) {   
                                        sukien.thaydoi(luachon);
                                        if (luachon==100) explain(sukien,false); else explain(sukien,true);
                                        SDL_Delay(5000);
                                        turn++;
                                        if (ketThuc!=0) game::inKetthuc(ketThuc);
                                    }
                                    else if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) khungNen = 6;
                                    else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) khungNen = 3;
                                    if (luachon!=0 || khungNen!=1) stop = true;
                                    break;
                                }
                                case SDL_QUIT:
                                    isRunning = false; 
                                    stop = true;
                                    break; 
                            }
                        }
                    }
                }
            }
                
            case 3:
                {while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>443 && event.button.x<583 && event.button.y>197 && event.button.y<277) {
                                memset(stt,false,30);
                                turn = 0;
                                Money = 32;
                                Favor = 32;
                                Oxygen = 64;
                                Trans = 0;
                                Influ = 15;
                                khungNen = 1;
                            }   
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>284 && event.button.y<364) {
                                if (turn >= 10) khungNen=2;
                                else khungNen=1;
                            }
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>370 && event.button.y<450) {
                                khungNen = 4;
                            }
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>457 && event.button.y<537) {
                                khungNen = 6;
                            }
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                break;}
            case 4:
                {game::inCredit();
                while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>40 && event.button.x<190 && event.button.y>51 && event.button.y<83) khungNen = 3;
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                break;}
            case 5:
                {while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>423 && event.button.x<603 && event.button.y>428 && event.button.y<528) khungNen = 3;
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                break;}
            case 6:
                {game::inCollection();
                while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>47 && event.button.x<197 && event.button.y>37 && event.button.y<69) khungNen = 3;
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                break;}
            case 7:
                {while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>443 && event.button.x<583 && event.button.y>197 && event.button.y<277) {
                                memset(stt,false,30);
                                turn = 0;
                                khungNen = 1;
                                Money = 32;
                                Favor = 32;
                                Oxygen = 64;
                                Trans = 0;
                                Influ = 15;
                            }   
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>370 && event.button.y<450) {
                                khungNen = 4;
                            }
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>457 && event.button.y<537) {
                                khungNen = 6;
                            }
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                break;}
        }
    }



	//Hủy mọi thứ
    game::xuatfileCache();
    game::xoaAttributes();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_PauseMusic();
    Mix_CloseAudio();
    SDL_FreeSurface(anhNen);
    SDL_DestroyTexture(texture);
	SDL_Quit();
	return 0;
}

