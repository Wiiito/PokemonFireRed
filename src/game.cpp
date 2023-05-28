#include "headers/game.hpp"

Game::Game() { initVariables(); }

Game::~Game() {}

// Functions

void Game::initVariables() {
  /*
    Public
    @return void

    Initialize game variables
      - Init pointers with values:
        - Window
  */

  // Window initialization
  this->window = nullptr;
  this->initWindow();

  // Map initialization
  this->map = nullptr;

  this->map = new Map("Pallet");
}

void Game::initWindow() {
  /*
    Private
    @return void

    Initialize window
     - Create window object and appends it adress to window pointer
  */

  this->videoMode = sf::VideoMode(240 * GAME_SCALE, 160 * GAME_SCALE);

  this->window = new sf::RenderWindow(this->videoMode, "Recreation of pokemon FireRed",
                                      sf::Style::Titlebar | sf::Style::Close);
}

void Game::poolEvents() {
  /*
    Private
    @return void

    Pool window events
  */

  while (this->window->pollEvent(this->event)) {
    if (this->event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      this->window->close();
    }
  }
}

void Game::updateGame() {
  /*
    Public
    @return void

    Updates game logic
  */
  this->poolEvents();
}

void Game::renderGame() {
  /*
    Public
    @return void

    Renders game on screen
  */

  this->window->clear();

  map->render(this->window, Game::GAME_SCALE);

  this->window->display();
}

// Set / Get Functions
bool Game::getIsWindowOpen() { return this->window->isOpen(); };