#include "Game.hpp"


Game::Game()
{
    
    mWindow.create(sf::VideoMode(768, 672), "SFML Application");
    //mWindow.setVerticalSyncEnabled(true);
    //mWindow.setFramerateLimit(30);
    playerTexture.loadFromFile("purple.png");
	npcTexture.loadFromFile("characters.png");
    mapTexture.loadFromFile("basictiles.png");
	left=up=down=right=false;
	
    map.Initialize(mapTexture,"DemoMap.json");
    player.SetTexture(playerTexture);
    player.SetPosition(map.GetStartPlayerPosition());
	// npc.SetTexture(sf::IntRect(96,0, 192, 128), npcTexture);
	// npc.SetPosition(sf::Vector2f(96,48));
	auto tempNpcList=map.GetNpcList();
	for(auto it=tempNpcList.cbegin(); it!=tempNpcList.cend();it++){
		Npc tempNpc;
		tempNpc.SetPosition(it->second);
		if(it->first=="bob")
			tempNpc.SetTexture(sf::IntRect(96,0, 192, 128), npcTexture);
		else if(it->first=="tom")
			tempNpc.SetTexture(sf::IntRect(144,0, 192, 128), npcTexture);
		else if(it->first=="jerry")
			tempNpc.SetTexture(sf::IntRect(0,64, 192, 128), npcTexture);
		
		
		NpcList.push_back(tempNpc);
	}
	
	
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
        
        
        
        

        if(right)
			player.MoveRight();
		else if(left)
			player.MoveLeft();
		else if(up)
			player.MoveUp();
		else if(down)
			player.MoveDown();
		
        player.Update(elapsedTime, map);
		// npc.Update(elapsedTime, map);  
		for (auto it = NpcList.begin(); it != NpcList.end(); ++it){
			it->Update(elapsedTime, map);
		}

        mainView.setCenter(sf::Vector2f((int)player.GetPosition().x,
			(int)player.GetPosition().y));

}

void Game::Draw(){
    mWindow.clear();
    mWindow.setView(mainView);
    map.Draw(mWindow,mapTexture);
    player.Draw(mWindow);
	// npc.Draw(mWindow);
	for (auto it = NpcList.begin(); it != NpcList.end(); ++it){
			it->Draw(mWindow);
	}
	
    mWindow.display();
}

void Game::HandleInput(sf::Keyboard::Key key,bool isPressed){
    if(key==sf::Keyboard::Up)
        up=isPressed;
    if(key==sf::Keyboard::Down)
        down=isPressed;
    if(key==sf::Keyboard::Left)
        left=isPressed;
    if(key==sf::Keyboard::Right)
        right=isPressed;
    
}

