#pragma once

#include <SDL2/SDL.h>

namespace UG {
  class Game {
    SDL_Window *window;
    SDL_Renderer *renderer;

    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;
    
    bool is_running = false;
  public:
    Game();
    ~Game();

    void PollEvents();
    void Update();
    
    bool GetIsRunning();
    SDL_Renderer *GetRenderer();
  };
};
