#include "Npc.hpp"

Npc::Npc(){
	
    	
    gameObjectSprite.setFrameTime(sf::seconds(0.2f));
    gameObjectSprite.play();
    gameObjectSprite.setLooped(true);
	
}

void Npc::SetTexture (const sf::Texture& gameObjectTexture){
	walkAnimationDown.setSpriteSheet(gameObjectTexture);
	
}

void Npc::SetTexture (sf::IntRect textrRect, const sf::Texture& gameObjectTexture){
	walkAnimationDown.addFrame(sf::IntRect(textrRect.left, textrRect.top , 16, 16));
    walkAnimationDown.addFrame(sf::IntRect(
		textrRect.left+32, textrRect.top , 16, 16));
	walkAnimationDown.setSpriteSheet(gameObjectTexture);
	
	
}

void Npc::Update(sf::Time elapsedTime, const TileMap& map){
	
	gameObjectSprite.play(walkAnimationDown);
	gameObjectSprite.update(elapsedTime);
	gameObjectSprite.setPosition(sf::Vector2f((int)position.x,(int)position.y));
	
	
}

void Npc::Draw (sf::RenderWindow& window){
	window.draw(gameObjectSprite);
	
}