#ifndef Events
#define Events

#include"mainThings.h"

class Sukien {
    private:
        SDL_Surface* cauhoi;
        SDL_Surface* traloiA;
        SDL_Surface* traloiB;
        SDL_Surface* nhanvat;
        SDL_Rect posCauhoi;
        SDL_Rect posTraloiA;
        SDL_Rect posTraloiB;
        SDL_Rect posNhanvat;
        short sttSukien;
    public:
        Sukien(int a);
        ~Sukien();
        friend void show(Sukien a);
        friend void explain(Sukien a, bool b);
        void thaydoi(short a);
};


#endif

