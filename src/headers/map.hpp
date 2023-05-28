#include <vector>
using std::vector;

#include <string>
using std::string;

#include <SFML/Graphics.hpp>
#include <iostream>

enum MapTile { grass, road };

class Map {
 private:
  vector<vector<MapTile>> mapTiles;

 public:
  static std::map<string, MapTile> mapColorFunction;

  // Constructor / Destructor
  Map(string mapName);
  ~Map();

  // Functions
  void render(sf::RenderWindow *i_window, int scale);
};