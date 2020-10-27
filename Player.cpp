#include "Player.hpp"
#include "iostream"

Player::Player()

{
    moveUp=false;
    moveDown=false;
    moveLeft=false;
    moveRight=false;
    isMovingRight=false;
    isMovingLeft=false;
    isMovingUp=false;
    isMovingDown=false;
    speed=100;
    canMove=true;
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


void Player::Update(sf::Time elapsedTime,sf::View& view){

	if(!canMove){
		position.x+=moveDirection.x*speed*elapsedTime.asSeconds();
		position.y+=moveDirection.y*speed*elapsedTime.asSeconds();
	}
    
	
    if(isMovingRight && position.x>=targetTilePosition.x){
        position.x=targetTilePosition.x;
        canMove=true;
        isMovingRight=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
	}
    
	if(isMovingLeft && position.x<=targetTilePosition.x){
        position.x=targetTilePosition.x;
        canMove=true;
        isMovingLeft=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
	}
    
	if(isMovingUp && position.y<=targetTilePosition.y){
        position.y=targetTilePosition.y;
        canMove=true;
        isMovingUp=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
    }
	
	if(isMovingDown && position.y>=targetTilePosition.y){
        position.y=targetTilePosition.y;
        canMove=true;
        isMovingDown=false;
		std::cout<<"X Position"<<position.x;
		std::cout<<" Y Position"<<position.y<<std::endl;
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
	if(canMove){
		targetTilePosition.x=position.x+16;
		canMove=false;
		isMovingRight=true;
		moveDirection.x=1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationRight;
	}
}

void Player::MoveLeft(){
	if(canMove){
		targetTilePosition.x=position.x-16;
		canMove=false;
		isMovingLeft=true;
		moveDirection.x=-1;
		moveDirection.y=0;
		currentAnimation=&walkAnimationLeft;
	}
}

void Player::MoveUp(){
	if(canMove){
		targetTilePosition.y=position.y-16;
		canMove=false;
		isMovingUp=true;
		moveDirection.y=-1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationUp;
	}
}

void Player::MoveDown(){
	if(canMove){
		targetTilePosition.y=position.y+16;
		canMove=false;
		isMovingDown=true;
		moveDirection.y=1;
		moveDirection.x=0;
		currentAnimation=&walkAnimationDown;
	}
}


