#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>


class Player{
    
    
    
    int speed;
    sf::Sprite playerSprite;
    float timePerFrame;
    //AnimatedSprite playerAnimation{playerSprite,timePerFrame};

    public:
    bool moveUp;
    bool moveDown;
    bool moveLeft;
    bool moveRight;
    bool isMovingRight;
    bool isMovingLeft;
    bool isMovingUp;
    bool isMovingDown;
    bool canMove;
    sf::Vector2f targetTilePosition;
        
    sf::Vector2f position;
    Player();
    Player(const sf::Texture& playerTexture);
    //void HandleInput(sf::Keyboard::Key key,bool isPressed);
    sf::Vector2<int> Move(sf::Vector2i);
    void Update(sf::Time elapsedTime, sf::View&);
    void Update2(sf::Time elapsedTime);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition();
    sf::Vector2<int> TargetTile;
    sf::Vector2f Normalize(sf::Vector2f source);
    void SetPosition(sf::Vector2f);
    void SetTargetPosition(sf::Vector2f);
    

    
    

};