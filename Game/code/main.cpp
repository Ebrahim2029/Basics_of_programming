#include<iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Animal Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 720, 480, 0);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Unable to create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load lion image
    SDL_Texture* lionTexture = IMG_LoadTexture(renderer, "image/lion.png");
    if (!lionTexture) {
        SDL_Log("Unable to load lion image: %s", IMG_GetError());
        // handle error...
    }


    // create rectangular
    SDL_Rect r{ 10,10,250,250 };
    r.w = 120;
    r.h = 93;

    // Main game loop flag
    bool gameRunning = true;

    // Event handler
    SDL_Event e;

    // Game loop
    while (gameRunning) {

        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                gameRunning = false;
            }
            else if (e.type == SDL_KEYDOWN)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "right key was pressed " << endl;
                    r.x = min(r.x + 50, 720 - r.w);
                    
                    break;
                case SDLK_LEFT:
                    cout << "LEFT key was pressed " << endl;
                    r.x = max(r.x - 50, 0);
                   
                    break;
                case SDLK_UP:
                    cout << "UP key was pressed " << endl;
                    r.y = max(r.y - 50, 0);
                  
                    break;
                case SDLK_DOWN:
                    cout << "DOWN key was pressed " << endl;
                    r.y = min(r.y + 50, 480 - r.h);
                    break;
                }

            }


            /*else if (e.type == SDL_KEYUP)
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    cout << "right key was released" << endl;
                    break;
                }
            }*/
            /*else if (e.type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&r.x, &r.y);
            }*/
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Set rectangular color and Fill rectangular
        //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        //SDL_RenderFillRect(renderer, &r);

        SDL_RenderCopy(renderer, lionTexture, NULL, &r);


        // Update screen
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


