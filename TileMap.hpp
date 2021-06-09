#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include <SFML/Graphics.hpp>
#include "json.hpp"
#include <fstream>

class TileMap{
    //TileMap();
    
    sf::VertexArray vertexArray;
    sf::VertexArray vertexArray2;
    //sf::Texture& tileset;
    int TILE_SIZE;
    int mapWidth;
    int mapHeight;
    std::vector<int> mapLayer;
    std::vector<int> mapLayer2;
    std::vector<std::string> collisionLayer;
    sf::Vector2f startPlayerPosition;
    
    
    
    public:
    void Initialize(const sf::Texture& tileset,const std::string mapPath);
    sf::Vector2i GetMapDimensions() const;
    void Draw(sf::RenderWindow& window,const sf::Texture& tileset);
    int GetTileSize();
    sf::Vector2f GetStartPlayerPosition();
    sf::Vector2f GetTilePixelPosition(int x, int y);
    sf::Vector2<int> GetTileIndex(sf::Vector2f position) const;
    bool IsPassable(const sf::Vector2i gameObjectTile) const;

    

    


};

#endif