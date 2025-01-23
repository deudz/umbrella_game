#include <SDL2/SDL.h>

#include "game.hh"

int main() {
  UG::Game game;
  
  while (game.GetIsRunning()) {
    game.PollEvents();
    game.Update();
  }
  
  return 0;
}
