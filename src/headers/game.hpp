#include <SFML/Graphics.hpp>

#include "map.hpp"

class Game {
 private:
  // Variables

  sf::VideoMode videoMode;
  sf::RenderWindow *window;

  sf::Event event;

  Map *map;

  // Functions
  void initWindow();
  void poolEvents();

 public:
  static int GAME_SCALE;
  // Construtors / Destructors
  Game();
  ~Game();

  // Functions
  void initVariables();

  void updateGame();
  void renderGame();

  // Set / Get Functions
  bool getIsWindowOpen();

  // Static
  static int getGameScale() { return GAME_SCALE; }
};
