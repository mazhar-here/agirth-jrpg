#include "GameObject.hpp"

GameObject::GameObject(){
	
	
	
	// gameObjectSprite.setTextureRect(sf::IntRect(0,0,48,64));
	
}


void GameObject::Update(sf::Time elapsedTime, const TileMap& map){
	
	gameObjectSprite.setPosition(sf::Vector2f((int)position.x,(int)position.y));
	
}


void GameObject::SetTexture(const sf::Texture& gameObjectTexture){
	
	// gameObjectSprite.setTextureRect(textrRect);
	gameObjectSprite.setTexture(gameObjectTexture);
}

void GameObject::Draw(sf::RenderWindow& window){
    window.draw(gameObjectSprite);	
}

sf::Vector2f GameObject::GetPosition(){
	return position;
}

void GameObject::SetPosition(sf::Vector2f position){
	this->position=position;	
}



	