#ifndef Events
#define Events

#include"mainThings.h"

class Sukien {
    private:
        SDL_Surface* cauhoi;
        SDL_Surface* traloiA;
        SDL_Surface* traloiB;
        SDL_Surface* nhanvat;
    public:
        Sukien(int a, std::string c);
        ~Sukien();
        friend void show(Sukien a);
};

#endif

