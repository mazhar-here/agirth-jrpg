#include "Player.hpp"
#include "iostream"

Player::Player()

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

    playerSprite.setFrameTime(sf::seconds(0.2f));
    playerSprite.play();
    playerSprite.setLooped(true);
	

    
    
}



void Player::SetTexture(const sf::Texture& playerTexture){
    walkAnimationLeft.setSpriteSheet(playerTexture);
    walkAnimationRight.setSpriteSheet(playerTexture);
    walkAnimationUp.setSpriteSheet(playerTexture);
    walkAnimationDown.setSpriteSheet(playerTexture);
    
}


void Player::Update(sf::Time elapsedTime,sf::View& view,TileMap& map){

	
	sf::Vector2f oldPosition=GetPosition();
	
	if(!ableToMove){
		position.x+=moveDirection.x*speed*elapsedTime.asSeconds();
		position.y+=moveDirection.y*speed*elapsedTime.asSeconds();
	}
	
	sf::Vector2i playerTile=map.GetTileIndex(GetPosition());	
	
	
	
    
	
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
	
	if(map.collisionLayer[playerTile.x+playerTile.y*map.GetMapDimensions().x]=="1" && (isMovingLeft || isMovingUp)){
			SetPosition(oldPosition);
        }
		// else if(map.collisionLayer[playerTile.x+playerTile.y*map.GetMapDimensions().x]=="1" && (isMovingUp)){
            // SetPosition(oldPosition);
        // }
        else if(map.collisionLayer[playerTile.x+1+playerTile.y*map.GetMapDimensions().x]=="1" && (isMovingRight))
        {
            SetPosition(oldPosition);

        }
        else if(map.collisionLayer[playerTile.x+(playerTile.y+1)*map.GetMapDimensions().x]=="1" && (isMovingDown)){
			SetPosition(oldPosition);
		}

	
    playerSprite.play(*currentAnimation);
    playerSprite.update(elapsedTime);

}

void Player::Draw(sf::RenderWindow& window){
    playerSprite.setPosition(sf::Vector2f((int)position.x,(int)position.y));
    window.draw(playerSprite);
    
}

sf::Vector2f Player::GetPosition(){
    return position;
}

void Player::SetPosition(sf::Vector2f position){
	this->position=position;
    targetTilePosition=position;
}



void Player::MoveRight(){
	if(ableToMove){
		targetTilePosition.x=position.x+16;
		ableToMove=false;
		isMovingRight=true;
		moveDirection.x=1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationRight;
	}
}

void Player::MoveLeft(){
	if(ableToMove){
		targetTilePosition.x=position.x-16;
		ableToMove=false;
		isMovingLeft=true;
		moveDirection.x=-1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationLeft;
	}
}

void Player::MoveUp(){
	if(ableToMove){
		targetTilePosition.y=position.y-16;
		ableToMove=false;
		isMovingUp=true;
		moveDirection.y=-1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationUp;
	}
}

void Player::MoveDown(){
	if(ableToMove){
		targetTilePosition.y=position.y+16;
		ableToMove=false;
		isMovingDown=true;
		moveDirection.y=1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationDown;
	}
}


