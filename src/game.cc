#include "game.hh"
#include "player.hh"

using namespace UG;

Player player(60.f, 80.f);

Game::Game() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    SDL_LogError(0, "error initializing sdl! %s", SDL_GetError());

  window = SDL_CreateWindow("Umbrella Game",
			    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			    WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  is_running = true;
}

Game::~Game() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::PollEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT)
      is_running = false;
  }
}

void Game::Update() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  player.Draw(renderer);
  SDL_RenderPresent(renderer);
}

bool Game::GetIsRunning() {
  return is_running;
}

SDL_Renderer *Game::GetRenderer() {
  return renderer;
}
