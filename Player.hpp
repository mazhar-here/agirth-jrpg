#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>


class Player{
    
    
    
    int speed;
    //sf::Sprite playerSprite;
    float timePerFrame;
    AnimatedSprite playerSprite;
    Animation walkAnimationLeft;
    Animation walkAnimationRight;
    Animation walkAnimationUp;
    Animation walkAnimationDown;
    Animation* currentAnimation;

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
    sf::Vector2i moveDirection;    
    sf::Vector2f position;

    
    Player();
    void SetTexture(const sf::Texture& playerTexture);
    void Update(sf::Time elapsedTime, sf::View&);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition();
    sf::Vector2<int> TargetTile;
    sf::Vector2f Normalize(sf::Vector2f source);
    void SetPosition(sf::Vector2f);
    void SetTargetPosition(sf::Vector2f);
    void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
    
    

};