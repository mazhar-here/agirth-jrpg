#include "AnimatedSprite.hpp"




AnimatedSprite::AnimatedSprite(sf::Sprite& sprite,float timePerFrame)
:sprite(sprite)
{
    this->timePerFrame=timePerFrame;
    currentFrame=0;
    progress=0;
}



void AnimatedSprite::Update(float elapsedTime){
    progress+=elapsedTime;
    if(progress>=timePerFrame){
        currentFrame=(currentFrame+1)%frameList.size();
        sprite.setTextureRect(frameList[currentFrame]);
    }
}

void AnimatedSprite::Initialize(int rows, int columns, int spriteHeight,int spriteWidth){
    
    for(int i=0;i<columns;i++){
        for(int j=0;j<rows;j++ )
            frameList.push_back(sf::IntRect(i*spriteWidth,j*spriteHeight,spriteWidth,spriteHeight));
    }    
}

void AnimatedSprite::AddFrame(sf::IntRect frameRect){
    frameList.push_back(frameRect);
}

