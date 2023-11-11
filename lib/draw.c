#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "sprite.h"

TTF_Font *font;
TTF_Font *bigfont;
TTF_Font *superfont;
SDL_Renderer *renderer;
SDL_Surface *surface;
SDL_Texture *texture;

void draw_init(SDL_Window *window)
{
    font = TTF_OpenFont("./resources/white-rabbit.TTF", 20);
    bigfont = TTF_OpenFont("./resources/white-rabbit.TTF", 40);
	superfont = TTF_OpenFont("./resources/white-rabbit.TTF", 60);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    renderer = SDL_CreateRenderer(window, -1, render_flags);
}

void draw_clear()
{
    SDL_RenderClear(renderer);
}

void draw_paused(int WIDTH, int HEIGHT)
{
    SDL_Color color = {255, 255, 255};
    surface = TTF_RenderText_Solid(superfont,
                                   "PAUSED", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {WIDTH / 2 - texW / 2, HEIGHT / 2 - texH / 2, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
};

void draw_gameover(int WIDTH, int HEIGHT)
{
    SDL_Color color = {255, 0, 0};
    surface = TTF_RenderText_Solid(superfont,
                                   "GAME OVER", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {WIDTH / 2 - texW / 2, HEIGHT / 2 - texH / 2, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
};

void draw_value(int _value)
{
    SDL_Color color = {255, 255, 255};
    char value[1000];
	if(_value==-1){
		sprintf(value, "input:%s", "NULL");
	}else{
		sprintf(value, "input:%d", _value);
	}
    
    surface = TTF_RenderText_Solid(font,
                                   value, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect score_dstrect = {10, 50, texW, texH};

    SDL_RenderCopy(renderer, texture, NULL, &score_dstrect);
};

void draw_life(int _life)
{
    SDL_Color color = {255, 255, 255};
    char life[1000];
    sprintf(life, "LIFE:%d", _life);
    surface = TTF_RenderText_Solid(font,
                                   life, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect score_dstrect = {10, 30, texW, texH};

    SDL_RenderCopy(renderer, texture, NULL, &score_dstrect);
};

void draw_score(int _score)
{
    SDL_Color color = {255, 255, 255};
    char score[1000];
    sprintf(score, "SCORE:%d", _score);
    surface = TTF_RenderText_Solid(font,
                                   score, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect score_dstrect = {10, 10, texW, texH};

    SDL_RenderCopy(renderer, texture, NULL, &score_dstrect);
};

void draw_sprite(Sprite sprite)
{
    SDL_Color color = {255, 255, 255};
    // 🛸
    surface = TTF_RenderText_Solid(bigfont,
                                   sprite.data, color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    //SDL_Rect dstrect = {sprite.x, sprite.y, sprite.w, sprite.h};
	SDL_Rect dstrect = {sprite.x, sprite.y, texW, texH};
    // SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
};

void draw_show()
{
    SDL_RenderPresent(renderer);
}

void draw_destroy()
{
    TTF_CloseFont(font);
    TTF_CloseFont(bigfont);
    TTF_Quit();
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
}
