#include "Game.hpp"


Game::Game()
//:player(playerTexture)
{
    
    mWindow.create(sf::VideoMode(768, 672), "SFML Application");
    //mWindow.setVerticalSyncEnabled(true);
    //mWindow.setFramerateLimit(30);
    playerTexture.loadFromFile("blue.png");
    mapTexture.loadFromFile("basictiles.png");
    levelWidth=levelHeight=60;
    for(int row=0;row<levelHeight;row++){
        for(int column=0;column<levelWidth;column++){
            if(row==0||column==0||row==levelHeight-1||column==levelWidth-1 )
                level[column+row*levelWidth]=0;
            else
                level[column+row*levelWidth]=13;
        } 
    }
    map.Initialize(mapTexture,level,levelWidth,levelHeight);
    player.SetTexture(playerTexture);
    mainView.reset(sf::FloatRect(0,0,256,224));
    timePerFrame=sf::seconds(1.0f/30.0f);
    

    
    
}

void Game::Run(){
    sf::Clock time;
    
    while (mWindow.isOpen()){
        sf::Time elapsedTime=time.restart();
        ProcessEvents();
        Update(elapsedTime);
        Draw();
    }
}

void Game::ProcessEvents(){
    sf::Event event;
    while(mWindow.pollEvent(event)){
        if(event.type==sf::Event::Closed)
            mWindow.close();
        
        if(event.type==sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape){
            //HandleInput(event.key.code,true);
            mWindow.close();
            
        }
            
        if(event.type==sf::Event::KeyPressed){
            HandleInput(event.key.code,true);
            
        }
        if(event.type==sf::Event::KeyReleased){
            HandleInput(event.key.code,false);   
            
        }
        
    }

    
}

void Game::Update(sf::Time elapsedTime){
    

    
    
        sf::Vector2f oldPosition=player.GetPosition();
        player.Update(elapsedTime,mainView);
        sf::Vector2i playerTile=map.GetTileIndex(player.GetPosition());
        if(level[playerTile.x+playerTile.y*levelWidth]==0 && (player.isMovingLeft || player.isMovingUp)){
            player.SetPosition(oldPosition);
            //player.targetTilePosition=oldPosition;
        }
        else if(level[playerTile.x+1+playerTile.y*levelWidth]==0 && (player.isMovingRight))
        {
            player.SetPosition(oldPosition);
            //player.targetTilePosition=oldPosition;

        }
        else if(level[playerTile.x+(playerTile.y+1)*levelWidth]==0 && (player.isMovingDown)){
            player.SetPosition(oldPosition);
            //player.targetTilePosition=oldPosition;

        }
        //**player.Update2(elapsedTime);


   
        std::cout<<"Position is: "<<player.position.x<<","<<player.position.y<<"\n";

        mainView.setCenter(sf::Vector2f((int)player.GetPosition().x,(int)player.GetPosition().y));
        //mainView.setCenter(player.GetPosition());

}

void Game::Draw(){
    mWindow.clear();
    mWindow.setView(mainView);
    map.Draw(mWindow,mapTexture);
    player.Draw(mWindow);
    mWindow.display();
}

void Game::HandleInput(sf::Keyboard::Key key,bool isPressed){
    if(key==sf::Keyboard::Up)
        player.moveUp=isPressed;
    if(key==sf::Keyboard::Down)
        player.moveDown=isPressed;
    if(key==sf::Keyboard::Left)
        player.moveLeft=isPressed;
    if(key==sf::Keyboard::Right)
        player.moveRight=isPressed;
    
}

