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
bool stt[30];
bool collection[4];
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
bool Checkpoint = false;
bool khoaNen;


int main(int arc, char* argv[] ){
	
    //Khởi tạo mọi thứ
	if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return -1;
    window = SDL_CreateWindow("The Ocean's Mystery",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
    SDL_RenderClear(renderer);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    nhacNen = Mix_LoadMUS("nhacNen.mp3");
    Mix_VolumeMusic(20);
    //Mix_PlayMusic(nhacNen,-1);
    game::napAttributes();
    memset(stt,false,30);
    memset(collection,false,4);
    game::nhapfileCache();
    if (!Checkpoint) khungNen=7;
    Sukien sukien;

    //Trò chơi
    while (isRunning) {
        SDL_RenderClear(renderer);
        switch (khungNen) {
            case 1: {
                if (turn==0 && !Checkpoint) {
                    game::inLoigioithieu();
                    SDL_Delay(5000);
                    Checkpoint = true;
                };
                game::showNen(1);
                game::showAttributes();
                khoaNen = true;
                if (turn == 0 || turn == 4) {
                    game::inSukien(0,turn);
                    SDL_RenderPresent(renderer);
                    while (khoaNen) {
                        bool thaydoi = false;
                        while (SDL_PollEvent(&event)!=0) {
                            if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE) {
                                if (turn == 4) {
                                    if (Favor>=45 && Influ>=45 && Oxygen>=25 && Money>=25 && Trans>=25) reNhanh=2;
                                    else reNhanh=1;
                                    khungNen = 2;
                                }
                                turn++;
                                thaydoi = true;
                            }
                            else if (event.type==SDL_QUIT) isRunning = false;
                        }
                        if (thaydoi || !isRunning) khoaNen = false;
                    }
                }
                else {
                    show(sukien);
                    SDL_RenderPresent(renderer);
                    while (khoaNen) {
                    bool thaydoi=false;
                    while (SDL_PollEvent(&event)!=0) {
                        switch(event.type) {
                            case SDL_MOUSEBUTTONDOWN:
                                if (event.button.x>92 && event.button.x<326 && event.button.y>418 && event.button.y<542) {
                                    sukien.thaydoi(100);
                                    explain(sukien,false);
                                    turn++;
                                    if (ketThuc!=0) game::inKetthuc(ketThuc);
                                    else {
                                        do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                        stt[sukien.laySTT()]=true;
                                    }
                                    thaydoi=true;
                                }
                                else if (event.button.x>398 && event.button.x<632 && event.button.y>418 && event.button.y<542) {
                                    sukien.thaydoi(200);
                                    explain(sukien,true);
                                    turn++;
                                    if (ketThuc!=0) game::inKetthuc(ketThuc);
                                    else {
                                        do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                        stt[sukien.laySTT()]=true;
                                    }
                                    thaydoi=true;
                                }
                                if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) khungNen = 6;
                                else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) khungNen = 3;
                                break;
                            case SDL_QUIT: 
                                isRunning = false;
                                break;
                        }
                    }
                    if (thaydoi || khungNen!=1 || !isRunning) khoaNen=false;
                }
                }
                break;
            }

            case 2: {
                game::showNen(2);
                game::showAttributes();
                khoaNen = true;
                if (turn == 5 || turn == 9 || turn == 13) {
                    if (turn == 5) collection[0]=true;
                    else if (turn == 9) collection[1]=true;
                    else if (turn == 13) collection[2]=collection[3]=true;
                    game::inSukien(reNhanh,turn);
                    SDL_RenderPresent(renderer);
                    while (khoaNen) {
                        bool thaydoi = false;
                        while (SDL_PollEvent(&event)!=0) {
                            if (event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_SPACE) {
                                turn++;
                                thaydoi = true;
                                if (turn == 13) {
                                    if (reNhanh == 1) game::inKetthuc(9);
                                    else if (reNhanh == 2) game::inKetthuc(10);
                                }
                            }
                            else if (event.type==SDL_QUIT) isRunning = false;
                        }
                        if (thaydoi || !isRunning) khoaNen = false;
                    }
                }
                else {
                    show(sukien);
                    SDL_RenderPresent(renderer);
                    while (khoaNen) {
                    bool thaydoi=false;
                        while (SDL_PollEvent(&event)!=0) {
                            switch(event.type) {
                                case SDL_MOUSEBUTTONDOWN:
                                    if (event.button.x>92 && event.button.x<326 && event.button.y>418 && event.button.y<542) {
                                        sukien.thaydoi(100);
                                        explain(sukien,false);
                                        turn++;
                                        if (ketThuc!=0) game::inKetthuc(ketThuc);
                                        else {
                                            do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                            stt[sukien.laySTT()]=true;
                                        }
                                        thaydoi=true;
                                    }
                                    else if (event.button.x>398 && event.button.x<632 && event.button.y>418 && event.button.y<542) {
                                        sukien.thaydoi(200);
                                        explain(sukien,true);
                                        turn++;
                                        if (ketThuc!=0) game::inKetthuc(ketThuc);
                                        else {
                                            do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                            stt[sukien.laySTT()]=true;
                                        }
                                        thaydoi=true;
                                    }
                                    if (event.button.x>836 && event.button.x<986 && event.button.y>36 && event.button.y<68) khungNen = 6;
                                    else if (event.button.x>836 && event.button.x<986 && event.button.y>78 && event.button.y<110) khungNen = 3;
                                    break;
                                case SDL_QUIT: 
                                    isRunning = false;
                                    break;
                            }
                        }
                        if (thaydoi || khungNen!=1 || !isRunning) khoaNen=false;
                    }
                }
                break;
            }

                
            case 3: {
                khoaNen = true;
                game::showNen(3);
                SDL_RenderPresent(renderer);
                while (khoaNen) {   
                    while (SDL_PollEvent(&event)!=0) {
                        switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>443 && event.button.x<583 && event.button.y>197 && event.button.y<277) {
                                memset(stt,false,30);
                                game::setupAttribute();
                                khungNen = 1;
                                do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                stt[sukien.laySTT()]=true;
                            }   
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>284 && event.button.y<364) {
                                if (turn>4) khungNen=2;
                                else khungNen=1;
                                do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                stt[sukien.laySTT()]=true;
                            }
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>370 && event.button.y<450) khungNen=4;
                            else if (event.button.x>443 && event.button.x<583 && event.button.y>457 && event.button.y<537) khungNen=6;
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                    if (khungNen!=3 || !isRunning) khoaNen=false;
                }
                break;
            }

            case 4: {
                khoaNen=true;
                game::showNen(4);
                SDL_RenderPresent(renderer);
                while (khoaNen) {
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
                    if (khungNen !=4 || !isRunning) khoaNen=false;
                }
                break;
            }

            case 5: {
                khoaNen=true;
                game::showNen(5);
                SDL_RenderPresent(renderer);
                while (khoaNen) {
                    while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>423 && event.button.x<603 && event.button.y>428 && event.button.y<528) khungNen = 7;
                            break;
                        case SDL_QUIT:
                            isRunning=false;
                            break;
                    }
                }
                    if (khungNen !=5 || !isRunning) khoaNen=false;
                }
                break;
            }

            case 6: {
                khoaNen=true;
                game::showNen(6);
                game::inCollection();
                SDL_RenderPresent(renderer);
                while (khoaNen) {
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
                    if (khungNen !=6 || !isRunning) khoaNen=false;
                }
                break;
            }

            case 7: {
                khoaNen=true;
                game::showNen(7);
                SDL_RenderPresent(renderer);
                while (khoaNen) {
                    while (SDL_PollEvent(&event)!=0) {
                    switch (event.type) {
                        case SDL_MOUSEBUTTONDOWN:
                            if (event.button.x>443 && event.button.x<583 && event.button.y>197 && event.button.y<277) {
                                memset(stt,false,30);
                                game::setupAttribute();
                                khungNen=1;
                                do {sukien.getDulieu(game::layRandom());} while (stt[sukien.laySTT()]);
                                stt[sukien.laySTT()]=true;
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
                    if (khungNen !=7 || !isRunning) khoaNen=false;
                }
                break;
            }
        
            default: isRunning = false;
        }
    }



	//Hủy mọi thứ
    if (ketThuc!=0) game::setupAttribute();
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
