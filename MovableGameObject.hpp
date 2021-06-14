#ifndef MOVABLE_GAME_OBJECT_HPP
#define MOVABLE_GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.hpp"
#include "GameObject.hpp"


class MovableGameObject: public GameObject{
	
	// sf::Sprite gameObjectSprite;
	
	protected:
	
	int speed;
	enum class state {MOVING_RIGHT,MOVING_LEFT,MOVING_UP,MOVING_DOWN,IDLE};
	state gameObjectState=state::IDLE;
	// float timePerFrame;

	sf::Vector2f targetTilePosition;
	
	public:
	
	MovableGameObject();

	// void SetSpeed(int speed);
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void Update(sf::Time elapsedTime, const TileMap& map) override;
	
	virtual ~MovableGameObject(){};

};

#endif