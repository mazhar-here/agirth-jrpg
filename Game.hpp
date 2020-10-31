#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "TileMap.hpp"

class Game{
    public:
    Game();
    void Run();
    

    private:
    void ProcessEvents();
    void Update(sf::Time elapsedTime);
    void Draw();
    void HandleInput(sf::Keyboard::Key key,bool isPressed);
	

    sf::RenderWindow mWindow;
    sf::Texture playerTexture;
    GameObject player;
	//GameObject npc;
    sf::Texture mapTexture;
    TileMap map;
	
    bool right;
	bool left;
	bool up;
	bool down;
	
    int levelWidth;
    int levelHeight;
    
    sf::View mainView;
    sf::Time timePerFrame;
    

    
};