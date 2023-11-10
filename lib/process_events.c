#include <SDL2/SDL.h>
#include "status.h"
#include "sprite.h"

void update_value(Status *status,int n){
	if(status->value!=-1){
		status->value*=10;
		status->value+=n;
	}else{
		status->value=n;
	}
}
void ProcessEvents(Status *status, Sprite *player)
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            status->quit = 1;
            return;
        }

        if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE)
            {
                status->quit = 1;
            }

            if (status->over)
            {
                return;
            }

            if (e.key.keysym.sym == SDLK_SPACE)
            {
            }	
        }

        if (e.type == SDL_KEYUP)
        {
            if (e.key.keysym.sym == SDLK_r)
            {
                if (status->over)
                {
                    status->init = 1;
                    return;
                }
            }

            if (status->over)
            {
                return;
            }

            if (e.key.keysym.sym == SDLK_p)
            {
                status->paused = !status->paused;
            }


            if (e.key.keysym.sym == SDLK_1)
            {
				update_value(status,1);
            }
			if (e.key.keysym.sym == SDLK_2)
            {
				update_value(status,2);
            }
			if (e.key.keysym.sym == SDLK_3)
            {
				update_value(status,3);
            }
			if (e.key.keysym.sym == SDLK_4)
            {
				update_value(status,4);
            }
			if (e.key.keysym.sym == SDLK_5)
            {
				update_value(status,5);
            }
			if (e.key.keysym.sym == SDLK_6)
            {
				update_value(status,6);
            }
			if (e.key.keysym.sym == SDLK_7)
            {
				update_value(status,7);
            }
			if (e.key.keysym.sym == SDLK_8)
            {
				update_value(status,8);
            }
			if (e.key.keysym.sym == SDLK_9)
            {
				update_value(status,9);
            }
			if (e.key.keysym.sym == SDLK_0)
            {
				update_value(status,0);
            }
			if (e.key.keysym.sym == SDLK_c)
            {
				status->value=-1;
            }
        }
    }
}
