#ifndef Events
#define Events

#include"mainThings.h"

class Sukien {
    private:
        std::string cauhoi;
        std::string traloiA;
        std::string traloiB;
        std::string nhanvat;
        SDL_Rect posCauhoi;
        SDL_Rect posTraloiA;
        SDL_Rect posTraloiB;
        SDL_Rect posNhanvat;
        short sttSukien;
    public:
        Sukien(short a);
        Sukien();
        ~Sukien();
        friend void show(Sukien a);
        friend void explain(Sukien a, bool b);
        void thaydoi(short a);
        void getDulieu(short a);
        short laySTT();
};


#endif

