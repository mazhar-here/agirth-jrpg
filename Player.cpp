#include "Player.hpp"


Player::Player(){
	
    speed=70;
	
   
    targetTilePosition=position;
    walkAnimationDown.addFrame(sf::IntRect(0, 0, 16, 16));
    walkAnimationDown.addFrame(sf::IntRect(32, 0, 16, 16));
    
    walkAnimationLeft.addFrame(sf::IntRect(0, 16, 16, 16));
    walkAnimationLeft.addFrame(sf::IntRect(32, 16, 16, 16));

    walkAnimationRight.addFrame(sf::IntRect(0, 32, 16, 16));
    walkAnimationRight.addFrame(sf::IntRect(32, 32, 16, 16));

    walkAnimationUp.addFrame(sf::IntRect(0, 48, 16, 16));
    walkAnimationUp.addFrame(sf::IntRect(32, 48, 16, 16));

    currentAnimation=&walkAnimationDown;
	

    gameObjectSprite.setFrameTime(sf::seconds(0.2f));
    gameObjectSprite.play();
    gameObjectSprite.setLooped(true);
}

void Player::Update(sf::Time elapsedTime, const TileMap& map){
		
		sf::Vector2f oldPosition=GetPosition();
		sf::Vector2i gameObjectTile;
		
		MovableGameObject::Update(elapsedTime, map );
		
		switch(gameObjectState){
			
			
			
			case state::MOVING_RIGHT:
				gameObjectTile=map.GetTileIndex(GetPosition());
				

				
				if(map.IsPassable(sf::Vector2i(gameObjectTile.x+1,gameObjectTile.y))){
					SetPosition(oldPosition);
					gameObjectState=state::IDLE;

				}
				
				break;
				
			case state::MOVING_LEFT:
				gameObjectTile=map.GetTileIndex(GetPosition());
				
				if(map.IsPassable(gameObjectTile)){
					SetPosition(oldPosition);
					gameObjectState=state::IDLE;
				}
				
				
				break;
				
			case state::MOVING_UP:
				gameObjectTile=map.GetTileIndex(GetPosition());
				
				
				if(map.IsPassable(gameObjectTile)){
					SetPosition(oldPosition);
					gameObjectState=state::IDLE;
				}
				
				break;
				
			case state::MOVING_DOWN:
				gameObjectTile=map.GetTileIndex(GetPosition());
				
		
				if(map.IsPassable(sf::Vector2i(gameObjectTile.x,gameObjectTile.y+1))){
					SetPosition(oldPosition);
					gameObjectState=state::IDLE;
				}
				
				break;
			
			case state::IDLE:
				break;
				
				
			
			
		}
		
		gameObjectSprite.play(*currentAnimation);
		gameObjectSprite.update(elapsedTime);
		gameObjectSprite.setPosition(sf::Vector2f((int)position.x,(int)position.y));
	
}

void Player::SetTexture(const sf::Texture& gameObjectTexture){
    walkAnimationLeft.setSpriteSheet(gameObjectTexture);
    walkAnimationRight.setSpriteSheet(gameObjectTexture);
    walkAnimationUp.setSpriteSheet(gameObjectTexture);
    walkAnimationDown.setSpriteSheet(gameObjectTexture);
    
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(gameObjectSprite);	
}

void Player::MoveRight(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_RIGHT;
		targetTilePosition.x=position.x+16;
		currentAnimation=&walkAnimationRight;
	}
}

void Player::MoveLeft(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_LEFT;
		targetTilePosition.x=position.x-16;
		currentAnimation=&walkAnimationLeft;
	}
}

void Player::MoveUp(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_UP;
		targetTilePosition.y=position.y-16;
		currentAnimation=&walkAnimationUp;
	}
	
}

void Player::MoveDown(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_DOWN;
		targetTilePosition.y=position.y+16;
		currentAnimation=&walkAnimationDown;
	}
	
}


