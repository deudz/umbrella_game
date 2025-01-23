#pragma once

#include <SDL2/SDL.h>

#include "entity.hh"

namespace UG {
  class Player : public Entity {
  public:
    Player(float x, float y);
    void Draw(SDL_Renderer *renderer);
    //    void Update();
  };
};
