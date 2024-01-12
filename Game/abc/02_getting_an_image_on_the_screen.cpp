#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "giaoDIen.h"

using namespace std;
typedef struct {
    int x;
    int y;
}ToaDo;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
SDL_Event g_event, g2_event, g3_event;
SDL_Surface *g_object = NULL;
const string WINDOW_TITLE = "Window";
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void logSDLError(std::ostream& os, const std::string &msg, bool fatal = false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
void draw(SDL_Renderer* renderer,int x,int y, char *s, float tiLe);
SDL_Texture* loadTexture( string path,SDL_Renderer* renderer );
void GiaoDien(SDL_Renderer* renderer, int x, int y, char *s);
void Menu(int x, int y, SDL_Renderer* renderer, int NhanVat, int d);
void MenuNV(int x, int y, SDL_Renderer* renderer, int k);
void GiaoDienEnd(SDL_Renderer* renderer, int x, int y, int d, int NhanVat);
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    int NhanVat = 1, d = 1;
    ToaDo Chim, denta;
    denta.x = 0;
    denta.y = 0;
    char s[100];
    strcpy(s, "MuiTen.bmp");
    GiaoDien(renderer, 350, 450, s);
    draw(renderer, 0, 0, "bg2.bmp", 1);
    Menu(200, 20, renderer, NhanVat, d);
    Thoat3:
    do{
        if(SDL_PollEvent(&g_event))
            if(g_event.type == SDL_KEYDOWN){
                cerr<<""<<SDL_GetKeyName(g_event.key.keysym.sym)<<""<<endl;
                switch(g_event.key.keysym.sym){
                    case SDLK_a: d--; break;
                    case SDLK_d: d++; break;
                    case SDLK_s:{
                        switch(d){
                            case 1:{
                                ChoiLai:
                                Chim.x = 100;
                                Chim.y = 200;
                                draw(renderer, 0, 0, "bg2.bmp", 1);
                                switch(NhanVat){
                                    case 1: strcpy(s, "NhanVat1.bmp"); break;
                                    case 2: strcpy(s, "NhanVat2.bmp"); break;
                                    case 3: strcpy(s, "NhanVat3.bmp"); break;
                                    case 4: strcpy(s, "NhanVat4.bmp"); break;
                                }
                                draw(renderer, Chim.x, Chim.y, s, 4);
                                int timeGame = 0;

                                do{
                                    if(SDL_PollEvent(&g2_event))
                                        if(g2_event.type == SDL_KEYDOWN){
                                            cerr<<""<<SDL_GetKeyName(g2_event.key.keysym.sym)<<""<<endl;
                                            switch(g2_event.key.keysym.sym){
                                                case SDLK_w: Chim.y -= 40; break;
                                                case SDLK_x: Chim.y += 40; break;
                                            }
                                        }
                                    timeGame++;
                                    if(timeGame == 5){
                                        Chim.y += 10;
                                        timeGame = 0;
                                    }
                                    if(Chim.y >= 500){
                                            int k = 1;
                                            GiaoDienEnd(renderer, 300, 400, k, NhanVat);
                                            do{
                                                if(SDL_PollEvent(&g3_event))
                                                    if(g3_event.type == SDL_KEYDOWN){
                                                        cerr<<""<<SDL_GetKeyName(g3_event.key.keysym.sym)<<""<<endl;
                                                        switch(g3_event.key.keysym.sym){
                                                            case SDLK_a: k--; break;
                                                            case SDLK_d: k++; break;
                                                            case SDLK_s: if(k >= 2) goto Thoat3;
                                                                        else        goto ChoiLai;
                                                        }
                                                    if(k == 3)
                                                        k = 1;
                                                    if(k == 0)
                                                        k = 2;
                                                    GiaoDienEnd(renderer, 300, 400, k, NhanVat);
                                                    }
                                            }while(1);

                                    }
                                draw(renderer, Chim.x, Chim.y, s, 4);
                                SDL_Delay(100);
                                }while(1);
                                break;
                            }
                            case 2:{
                                MenuNV(200, 20, renderer, NhanVat);
                                do{
                                    if(SDL_PollEvent(&g2_event))
                                        if(g2_event.type == SDL_KEYDOWN){
                                            cerr<<""<<SDL_GetKeyName(g2_event.key.keysym.sym)<<""<<endl;
                                            switch(g2_event.key.keysym.sym){
                                                case SDLK_a: NhanVat--; break;
                                                case SDLK_d: NhanVat++; break;
                                                case SDLK_s: goto TienDen;
                                            }
                                        if(NhanVat == 0)
                                            NhanVat = 4;
                                        if(NhanVat == 5)
                                            NhanVat = 1;
                                        MenuNV(200, 20, renderer, NhanVat);
                                        }
                                }while(1);
                                break;
                            }
                            case 4:{
                                goto Out;
                            }
                        }
                        break;
                    }
                }
                TienDen:
                if(d == 0)
                    d = 4;
                if(d == 5)
                    d = 1;
                Menu(200, 20, renderer, NhanVat, d);
                }
    }while(1);
    Out:
  /*
    draw(renderer, 0, 0, "bg2.bmp", 1);
    draw(renderer, Chim.x, Chim.y, "hinhanh.bmp", 20);
    do{
        if ( SDL_PollEvent(&g_event) == 0) continue;
        else if(g_event.type == SDL_QUIT) break;
        else if(g_event.type == SDL_KEYDOWN){
            cerr<<""<<SDL_GetKeyName(g_event.key.keysym.sym)<<""<<endl;
        switch(g_event.key.keysym.sym){
            case SDLK_w:{
                Chim.y -= 20;
                break;
            }
            case SDLK_x:{
                Chim.y += 20;
                break;
            }
            }
        }
    Chim.y +=10;
    draw(renderer, 0, 0, "bg2.bmp", 1);
    draw(renderer, Chim.x, Chim.y, "hinhanh.bmp", 20);
    SDL_RenderPresent(renderer);
    }while(g_event.key.keysym.sym != SDLK_s);
  */
 //   SDL_RenderPresent(renderer);
    waitUntilKeyPressed();   //bấm phím bất kì để quit
    quitSDL(window, renderer);   //quit khỏi window
    return 0;
}
void GiaoDienEnd(SDL_Renderer* renderer, int x, int y, int d, int NhanVat){
    draw(renderer, 320, 350, "ChoiLai.bmp", 1.5);
    draw(renderer, 520, 350, "Thoat.bmp", 1.7);
    char s[100];
    switch(NhanVat){
    case 1: strcpy(s, "NhanVat1.bmp"); break;
    case 2: strcpy(s, "NhanVat2.bmp"); break;
    case 3: strcpy(s, "NhanVat3.bmp"); break;
    case 4: strcpy(s, "NhanVat4.bmp"); break;
    }
    switch(d){
        case 1: draw(renderer, 300, 250, s, 2.5); break;
        case 2: draw(renderer, 500, 250, s, 2.5); break;
    }
}
void MenuNV(int x, int y, SDL_Renderer* renderer, int NhanVat){
    draw(renderer, 0, 0, "bg2.bmp", 1);
    draw(renderer, x, y + 200, "NhanVat1.bmp", 2.5);
    draw(renderer, x + 200, y + 200, "NhanVat2.bmp", 2.5);
    draw(renderer, x + 400, y + 200, "NhanVat3.bmp", 2.5);
    draw(renderer, x + 600, y + 200, "NhanVat4.bmp", 2.5);
    switch(NhanVat){
        case 1: draw(renderer, 500, y, "NhanVat1.bmp", 2);  draw(renderer, x + 33, y + 300, "ChonNV.bmp", 2);    break;
        case 2: draw(renderer, 500, y, "NhanVat2.bmp", 2);  draw(renderer, x+200 + 23, y + 300, "ChonNV.bmp", 2);    break;
        case 3: draw(renderer, 500, y, "NhanVat3.bmp", 2);  draw(renderer, x+400 + 35, y + 300, "ChonNV.bmp", 2);    break;
        case 4: draw(renderer, 500, y, "NhanVat4.bmp", 2);  draw(renderer, x+600 + 30, y + 300, "ChonNV.bmp", 2);    break;
    }
    SDL_RenderPresent(renderer);
}
void Menu(int x, int y, SDL_Renderer* renderer, int NhanVat, int d){
    draw(renderer, 0, 0, "bg2.bmp", 1);
    draw(renderer, x, y + 150, "BatDau.bmp", 1.5);
    draw(renderer, x + 200, y + 150, "CaiDat.bmp", 1.5);
    draw(renderer, x + 400, y + 150, "AmThanh.bmp", 1.5);
    draw(renderer, x + 600, y + 150, "Thoat.bmp", 1.5);
    int a = 20;
    switch(NhanVat){
        case 1:{
            draw(renderer, 200*d - a, y, "NhanVat1.bmp", 2);
            break;
        }
        case 2:{
            draw(renderer, 200*d - a, y, "NhanVat2.bmp", 2);
            break;
        }
        case 3:{
            draw(renderer, 200*d - a, y, "NhanVat3.bmp", 2);
            break;
        }
        case 4:{
            draw(renderer, 200*d - a, y, "NhanVat4.bmp", 2);
            break;
        }
    }
    SDL_RenderPresent(renderer);
}
void GiaoDien(SDL_Renderer* renderer, int x, int y, char *s){
    int d = 1;
    draw(renderer, 50, 0, "Flappy Birth.bmp", 1.8);
    for(int i=0; i<400; i+=20){
        switch(d){
            case 1: draw(renderer, 400, 400, "load1.bmp", 4); break;
            case 2: draw(renderer, 400, 400, "load2.bmp", 4); break;
            case 3: draw(renderer, 400, 400, "load3.bmp", 4); break;
        }
        d++;
        if(d == 4)
            d = 1;
        draw(renderer, x + i, y, s, 3);
        SDL_Delay(300);
    }
}
void logSDLError(std::ostream& os, const std::string &msg, bool fatal){
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
logSDLError(std::cout, "SDL_Init", true);
window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
//SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
if (window == NULL) logSDLError(std::cout, "CreateWindow", true);
//Khi chạy trong môi trường bình thường (không chạy trong máy ảo)
renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
SDL_RENDERER_PRESENTVSYNC);
//Khi chạy ở máy ảo (ví dụ tại máy tính trong phòng thực hành ở trường)
//renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
if (renderer == NULL) logSDLError(std::cout, "CreateRenderer", true);
SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

//.............................................................


void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//.............................................................

void waitUntilKeyPressed()
{
SDL_Event e;
while (true) {
if ( SDL_WaitEvent(&e) != 0 &&
(e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
return;
SDL_Delay(100);
}
}



SDL_Texture* loadTexture( string path,SDL_Renderer* renderer ){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if ( loadedSurface == NULL )
        cout << "Unable to load image " << path << " SDL_image Error: "<< IMG_GetError() << endl;

    else {
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( newTexture == NULL )
            cout << "Unable to create texture from " << path << " SDL Error:"<< SDL_GetError() << endl;

        SDL_FreeSurface( loadedSurface );
}
    return newTexture;
}
void draw(SDL_Renderer* renderer,int x,int y, char *s, float tiLe){
    SDL_Texture* dogde= loadTexture(s,renderer);
    SDL_Rect dogdeRect;
    SDL_QueryTexture(dogde,NULL,NULL,&dogdeRect.w,&dogdeRect.h);
    dogdeRect.x=x;
    dogdeRect.y=y;
    dogdeRect.w=dogdeRect.w/tiLe;
    dogdeRect.h=dogdeRect.h/tiLe;
    SDL_RenderCopy(renderer,dogde,NULL,&dogdeRect);


    SDL_RenderPresent(renderer);
}
