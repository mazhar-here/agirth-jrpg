#include "MovableGameObject.hpp"


MovableGameObject::MovableGameObject(){
    speed=70;
    targetTilePosition=position;
}
void MovableGameObject::Update(sf::Time elapsedTime, const TileMap& map){
		std::cout<<"x: "<< position.x<<", "<<"y: "<<position.y<<std::endl;
		switch(gameObjectState){
			case state::MOVING_RIGHT:
				position.x+=speed*elapsedTime.asSeconds();
				if(position.x>=targetTilePosition.x){
					position.x=targetTilePosition.x;
					
					gameObjectState=state::IDLE;
					break;
				}
				break;
			case state::MOVING_LEFT:
				position.x-=speed*elapsedTime.asSeconds();
				if(position.x<=targetTilePosition.x){
					position.x=targetTilePosition.x;
					gameObjectState=state::IDLE;
					break;	
				}
				break;
			case state::MOVING_UP:
				position.y-=speed*elapsedTime.asSeconds();
				if(position.y<=targetTilePosition.y){
					position.y=targetTilePosition.y;
					// moveDirection.y=0;
					gameObjectState=state::IDLE;
					break;
				}
				break;
			case state::MOVING_DOWN:
				position.y+=speed*elapsedTime.asSeconds();
				if(position.y>=targetTilePosition.y){
					position.y=targetTilePosition.y;
					gameObjectState=state::IDLE;
					break;
				}
				break;
			case state::IDLE:
				break;
		}
}
void MovableGameObject::MoveRight(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_RIGHT;
		targetTilePosition.x=position.x+16;
	}
}
void MovableGameObject::MoveLeft(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_LEFT;
		targetTilePosition.x=position.x-16;
	}
}
void MovableGameObject::MoveUp(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_UP;
		targetTilePosition.y=position.y-16;
	}
}
void MovableGameObject::MoveDown(){
	if(gameObjectState==state::IDLE){
		gameObjectState=state::MOVING_DOWN;
		targetTilePosition.y=position.y+16;
	}
}