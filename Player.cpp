#include "Player.hpp"
//#include "TileMap.hpp"


Player::Player(){
    moveUp=false;
    moveDown=false;
    moveLeft=false;
    moveRight=false;
    isMovingRight=false;
    isMovingLeft=false;
    isMovingUp=false;
    isMovingDown=false;
    position.x=128;position.y=128;
    speed=90;
    canMove=true;
    targetTilePosition=position;
    
}


Player::Player(const sf::Texture& playerTexture)
:Player()
{
    playerSprite.setTexture(playerTexture);
    //playerAnimation=AnimatedSprite(playerSprite,0.1);
    //playerAnimation.Initialize(1,3,16,16);
}


sf::Vector2i Player::Move(sf::Vector2i currentTile){
    //sf::Vector2<int> currentTile=TileMap::GetTileIndex(position);
    if(moveUp){
        currentTile.y-=1;
        // moveUp=false;
        }
    else if(moveDown){
        // moveDown=false;
        currentTile.y+=1;
    }
    else if(moveLeft){
        // moveLeft=false;
        currentTile.x-=1;
    }
    else if(moveRight){
        // moveRight=false;
        currentTile.x+=1;
    }
    return currentTile;    
    
}

void Player::Update(sf::Time elapsedTime,sf::View& view){
    if(moveUp && canMove){
        targetTilePosition.y-=16;
        canMove=false;
        isMovingUp=true;
        }
    else if(moveDown&& canMove){
        targetTilePosition.y+=16;
        canMove=false;
        isMovingDown=true;
    }
    else if(moveLeft&& canMove){
        targetTilePosition.x-=16;
        canMove=false;
        isMovingLeft=true;
    }
    else if(moveRight&& canMove){
        targetTilePosition.x+=16;
        canMove=false;
        isMovingRight=true;
    }
    if(isMovingLeft || isMovingRight || isMovingUp || isMovingDown){
        sf::Vector2f normal=Normalize(targetTilePosition-position);
    
        sf::Vector2f oldPosition=position;
        position.x+=normal.x*speed*elapsedTime.asSeconds();
        position.y+=normal.y*speed*elapsedTime.asSeconds();
        // position.x+=normal.x*4;
        // position.y+=normal.y*4;
    
        //view.move(position-oldPosition);
    }
    if(isMovingUp && position.y<=targetTilePosition.y){
        position.y=targetTilePosition.y;
        canMove=true;
        
        isMovingUp=false;
    }
    else if(isMovingDown && position.y>=targetTilePosition.y){
        position.y=targetTilePosition.y;
        canMove=true;
        isMovingDown=false;
    }
    else if(isMovingRight && position.x>=targetTilePosition.x){
        position.x=targetTilePosition.x;
        canMove=true;
        isMovingRight=false;
    }
    else if(isMovingLeft && position.x<=targetTilePosition.x){
        position.x=targetTilePosition.x;
        canMove=true;
        isMovingLeft=false;
    }

    //playerAnimation.Update(elapsedTime.asSeconds());

    // std::cout<<"Position is: "<<position.x<<","<<position.y<<"\n";    
}

void Player::Draw(sf::RenderWindow& window){
    playerSprite.setPosition(position);
    window.draw(playerSprite);
    

}

sf::Vector2f Player::GetPosition(){
    return position;
}

void Player::SetPosition(sf::Vector2f position){
    this->position=position;
    targetTilePosition=position;
}


sf::Vector2f Player::Normalize(sf::Vector2f source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return sf::Vector2f(source.x / length, source.y / length);
    else
        return source;
}

void Player::Update2(sf::Time elapsedTime){
if(moveUp){
        position.y-=speed*elapsedTime.asSeconds();
        // moveUp=false;
        }
    else if(moveDown&& canMove){
        position.y+=speed*elapsedTime.asSeconds();
    }
    else if(moveLeft&& canMove){
        position.x-=speed*elapsedTime.asSeconds();
    }
    else if(moveRight&& canMove){
        position.x+=speed*elapsedTime.asSeconds();
    }

}

