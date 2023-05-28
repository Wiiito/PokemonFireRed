#include "src/headers/game.hpp"

int Game::GAME_SCALE = 3;

int main() {
  Game game;

  while (game.getIsWindowOpen()) {
    game.updateGame();
    game.renderGame();
  }

  return 0;
}