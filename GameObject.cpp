#include "GameObject.hpp"
#include "iostream"

GameObject::GameObject()

{
    isMovingRight=false;
    isMovingLeft=false;
    isMovingUp=false;
    isMovingDown=false;
    speed=100;
    ableToMove=true;
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



void GameObject::SetTexture(const sf::Texture& gameObjectTexture){
    walkAnimationLeft.setSpriteSheet(gameObjectTexture);
    walkAnimationRight.setSpriteSheet(gameObjectTexture);
    walkAnimationUp.setSpriteSheet(gameObjectTexture);
    walkAnimationDown.setSpriteSheet(gameObjectTexture);
    
}


void GameObject::Update(sf::Time elapsedTime,sf::View& view,const TileMap& map){

	
	sf::Vector2f oldPosition=GetPosition();
	
	if(!ableToMove){
		position.x+=moveDirection.x*speed*elapsedTime.asSeconds();
		position.y+=moveDirection.y*speed*elapsedTime.asSeconds();
	}
	
	sf::Vector2i gameObjectTile=map.GetTileIndex(GetPosition());	
	
	
	
    
	
    if(isMovingRight && position.x>=targetTilePosition.x){
        position.x=targetTilePosition.x;
        ableToMove=true;
        isMovingRight=false;
		std::cout<<"oldPosition: "<<oldPosition.x<<" , "<<oldPosition.y<<std::endl;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
	}
    
	if(isMovingLeft && position.x<=targetTilePosition.x){
        position.x=targetTilePosition.x;
        ableToMove=true;
        isMovingLeft=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
	}
    
	if(isMovingUp && position.y<=targetTilePosition.y){
        position.y=targetTilePosition.y;
        ableToMove=true;
        isMovingUp=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
    }
	
	if(isMovingDown && position.y>=targetTilePosition.y){
        position.y=targetTilePosition.y;
        ableToMove=true;
        isMovingDown=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
    }
	
	if(map.IsPassable(gameObjectTile) && (isMovingLeft || isMovingUp)){
			SetPosition(oldPosition);
        }

        else if(map.IsPassable(sf::Vector2i(gameObjectTile.x+1,gameObjectTile.y)) && (isMovingRight))
        {
            SetPosition(oldPosition);

        }

        else if(map.IsPassable(sf::Vector2i(gameObjectTile.x,gameObjectTile.y+1)) && (isMovingDown)){
			SetPosition(oldPosition);
		}

	
    gameObjectSprite.play(*currentAnimation);
    gameObjectSprite.update(elapsedTime);

}

void GameObject::Draw(sf::RenderWindow& window){
    gameObjectSprite.setPosition(sf::Vector2f((int)position.x,(int)position.y));
    window.draw(gameObjectSprite);
    
}

sf::Vector2f GameObject::GetPosition(){
    return position;
}

void GameObject::SetPosition(sf::Vector2f position){
	this->position=position;
    targetTilePosition=position;
}



void GameObject::MoveRight(){
	if(ableToMove){
		targetTilePosition.x=position.x+16;
		ableToMove=false;
		isMovingRight=true;
		moveDirection.x=1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationRight;
	}
}

void GameObject::MoveLeft(){
	if(ableToMove){
		targetTilePosition.x=position.x-16;
		ableToMove=false;
		isMovingLeft=true;
		moveDirection.x=-1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationLeft;
	}
}

void GameObject::MoveUp(){
	if(ableToMove){
		targetTilePosition.y=position.y-16;
		ableToMove=false;
		isMovingUp=true;
		moveDirection.y=-1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationUp;
	}
}

void GameObject::MoveDown(){
	if(ableToMove){
		targetTilePosition.y=position.y+16;
		ableToMove=false;
		isMovingDown=true;
		moveDirection.y=1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationDown;
	}
}


