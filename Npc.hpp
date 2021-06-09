#ifndef NPC_HPP
#define NPC_HPP

#include "GameObject.hpp"
#include "AnimatedSprite.hpp"
#include "Animation.hpp"


class Npc: public GameObject{
	
	
	float timePerFrame;
	
    AnimatedSprite gameObjectSprite;
    Animation walkAnimationDown;
	
	public:
	
	Npc();
	void SetTexture (const sf::Texture& gameObjectTexture) override;
	void SetTexture (sf::IntRect textrRect, 
		const sf::Texture& gameObjectTexture) ;
	void Update(sf::Time elapsedTime, const TileMap& map) override;
	void Draw (sf::RenderWindow& window) override;
	
	
};

#endif