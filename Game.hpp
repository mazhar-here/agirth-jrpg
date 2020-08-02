#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "TileMap.hpp"

class Game{
    public:
    Game();
    void Run();
    

    private:
    void ProcessEvents();
    void Update(sf::Time elapsedTime);
    void Draw();
    void HandleInput(sf::Keyboard::Key key,bool isPressed);

    sf::RenderWindow mWindow;
    sf::Texture playerTexture;
    Player player;
    sf::Texture mapTexture;
    TileMap map;
    //bool isUp;
    //bool isDown;
    //bool isLeft;
    //bool isRight;
    int levelWidth;
    int levelHeight;
    int level[60*60]={};
    sf::View mainView;
    sf::Time timePerFrame;
    //sf::Vector2f targetTilePosition;

    
};