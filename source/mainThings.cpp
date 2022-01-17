#include"mainThings.h"
bool game::init(){
    if (SDL_Init(SDL_INIT_EVERYTHING)!=0) return false;
    window = SDL_CreateWindow(window,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,576,0);
    if (window==NULL) return false;
    renderer = SDL_CreateRenderer(window,-1,0);
    if (renderer==NULL) return false;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    anhNen=IMG_Load(".....");
    if (anhNen==NULL) return false;
    return true;
}

void game::destroy(){
    SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_CloseAudio();
    SDL_FreeSurface(anhNen);
    SDL_FreeSurface(tempAnhNen);
}


bool game::xoaNen(SDL_Surface* a){
    if (SDL_SetColorKey(a,SDL_TRUE,SDL_MapRGB(a->format,255,192,203))!=0) return false;
    return true;
}

bool game::ganAnh(SDL_Surface* a, int x, int y) {
    SDL_Rect rect;
    rect.x=x;
    rect.y=y;
    if (SDL_BlitSurface(a,NULL,tempAnhNen,rect)!=0) return false;
    return true;
}

SDL_Surface* game::loadAnh(std::string a) {
    SDL_Surface* result = NULL;
    result = IMG_Load(a.c_str());
    return result;
}

bool game::taoAnhNen(){
    tempAnhNen->clip_rect=anhNen->clip_rect;
    tempAnhNen->flags = anhNen->flags;
    tempAnhNen->format = anhNen->flags;
    tempAnhNen->h = anhNen->h;
    tempAnhNen->list_blitmap = anhNen->list_blitmap;
    tempAnhNen->locked = anhNen->locked;
    tempAnhNen->map = anhNen->map;
    tempAnhNen->pitch = anhNen->pitch;
    tempAnhNen->pixels = anhNen->pixels;
    tempAnhNen->refcount = anhNen->refcount;
    tempAnhNen->userdata = anhNen->refcount;
    tempAnhNen->w = anhNen->w;
}