#include <SFML/Graphics.hpp>


class TileMap{
    //TileMap();
    
    sf::VertexArray vertexArray;
    //sf::Texture& tileset;
    int TILE_SIZE;
    int levelWidth;
    int levelHeight;
    
    

    

    public:
    void Initialize(const sf::Texture& tileset,const int* level,const int levelWidth,const int levelHeight);
    void Draw(sf::RenderWindow& window,const sf::Texture& tileset);
    int GetTileSize();
    sf::Vector2f GetTilePixelPosition(int x, int y);
    sf::Vector2<int> GetTileIndex(sf::Vector2f position);


};