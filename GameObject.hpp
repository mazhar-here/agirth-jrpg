#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>
#include "TileMap.hpp"


class GameObject{
    
    
    
    int speed;
    float timePerFrame;
    AnimatedSprite gameObjectSprite;
    Animation walkAnimationLeft;
    Animation walkAnimationRight;
    Animation walkAnimationUp;
    Animation walkAnimationDown;
    Animation* currentAnimation;

    public:
    
	bool isMovingRight;
    bool isMovingLeft;
    bool isMovingUp;
    bool isMovingDown;
    bool ableToMove;
    
	sf::Vector2f targetTilePosition;
    sf::Vector2i moveDirection;    
    sf::Vector2f position;

    
    GameObject();
    void SetTexture(const sf::Texture& gameObjectTexture);
    void Update(sf::Time elapsedTime, sf::View&,const TileMap& map);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition();
    void SetPosition(sf::Vector2f);
    void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
    
    

};