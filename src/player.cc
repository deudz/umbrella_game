#include "player.hh"

using namespace UG;

Player::Player(float x, float y) {
  x = this->x;
  y = this->y;
}

void Player::Draw(SDL_Renderer *renderer) {
  SDL_Rect rect = {
    x, y,
    32, 32
  };

  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer, &rect);
  SDL_RenderPresent(renderer);
}

//Player::Update() {}
