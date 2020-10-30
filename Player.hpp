#pragma once

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include <iostream>
#include "TileMap.hpp"


class Player{
    
    
    
    int speed;
    float timePerFrame;
    AnimatedSprite playerSprite;
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

    
    Player();
    void SetTexture(const sf::Texture& playerTexture);
    void Update(sf::Time elapsedTime, sf::View&,TileMap& map);
    void Draw(sf::RenderWindow& window);
    sf::Vector2f GetPosition();
    sf::Vector2<int> TargetTile;
    void SetPosition(sf::Vector2f);
    void SetTargetPosition(sf::Vector2f);
    void MoveRight();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
    
    

};