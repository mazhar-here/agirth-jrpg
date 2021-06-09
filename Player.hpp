#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "MovableGameObject.hpp"
#include "AnimatedSprite.hpp"
#include <iostream>

class Player: public MovableGameObject{
	
	float timePerFrame;
	
    AnimatedSprite gameObjectSprite;
    Animation walkAnimationLeft;
    Animation walkAnimationRight;
    Animation walkAnimationUp;
    Animation walkAnimationDown;
    Animation* currentAnimation;
	
	
	public:
	
	Player();

	void Update(sf::Time elapsedTime, const TileMap& map) override;
	void SetTexture (const sf::Texture& gameObjectTexture) override;
	void Draw (sf::RenderWindow& window) override;
	void MoveRight() override;
	void MoveUp() override;
	void MoveDown() override;
	void MoveLeft() override;


	
};

#endif