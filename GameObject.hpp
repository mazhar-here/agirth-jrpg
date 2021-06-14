#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
// #include "TileMap.hpp"
class TileMap;

class GameObject{
	
	
	sf::Sprite gameObjectSprite;
	protected:
	sf::Vector2f position;

	
	public:
	
	GameObject();
	virtual void SetTexture(const sf::Texture& gameObjectTexture);
    virtual void Update(sf::Time elapsedTime, const TileMap& map);
    virtual void Draw(sf::RenderWindow& window);
	virtual sf::Vector2f GetPosition();
    virtual void SetPosition(sf::Vector2f position);
	virtual ~GameObject(){};
	
};
 
#endif