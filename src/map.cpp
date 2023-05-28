#include "headers/map.hpp"

using namespace sf;

std::map<string, MapTile> Map::mapColorFunction = {{"0,255,0", grass}, {"128,255,128", road}};

// Constructors / Destructors

Map::Map(string mapName) {
  /*
  - Loads map image
  - Get every pixel and maps it on mapColorFunction
  - Push the maped value to class map vector
  */

  Image map;
  map.loadFromFile("assets/maps/" + mapName + ".png");

  Vector2u mapSize = map.getSize();

  std::cout << mapSize.x << "," << mapSize.y;

  for (unsigned int y = 0; y < mapSize.y; y++) {
    vector<MapTile> yAxis;
    for (unsigned int x = 0; x < mapSize.x; x++) {
      Color color = map.getPixel(x, y);
      yAxis.push_back(mapColorFunction[std::to_string(color.r) + "," + std::to_string(color.g) +
                                       "," + std::to_string(color.b)]);
    }
    this->mapTiles.push_back(yAxis);
  }

  std::cout << this->mapTiles[0].size();
}

Map::~Map() {}

// Functions

void Map::render(RenderWindow *i_window, int scale) {
  /*
    @return void

    Draws map vector on screen
  */

  Texture gameTexture;
  gameTexture.loadFromFile("assets/textures/Texture.png");

  RectangleShape square;
  square.setSize(Vector2f(16 * scale, 16 * scale));

  square.setTexture(&gameTexture);

  for (unsigned int y = 0; y < this->mapTiles.size(); y++) {
    for (unsigned int x = 0; x < this->mapTiles[y].size(); x++) {
      square.setTextureRect(IntRect(16 * mapTiles[y][x], 0, 16, 16));
      square.setPosition(Vector2f(16 * scale * x, 16 * scale * y));

      i_window->draw(square);
    }
  }
}