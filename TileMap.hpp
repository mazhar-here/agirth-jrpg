#include <SFML/Graphics.hpp>
#include "json.hpp"
#include <fstream>

class TileMap{
    //TileMap();
    
    sf::VertexArray vertexArray;
    //sf::Texture& tileset;
    
    
    std::vector<int> mapLayer;
    
    

    

    public:
    void Initialize(const sf::Texture& tileset,const std::string mapPath);
    std::vector<std::string> collisionLayer;
    int TILE_SIZE;
    int levelWidth;
    int levelHeight;
    void Draw(sf::RenderWindow& window,const sf::Texture& tileset);
    int GetTileSize();
    sf::Vector2f GetTilePixelPosition(int x, int y);
    sf::Vector2<int> GetTileIndex(sf::Vector2f position);


};