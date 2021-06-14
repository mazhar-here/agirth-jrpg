#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Npc.hpp"
#include "TileMap.hpp"
#include <vector>

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
	sf::Texture npcTexture;
    Player player;
	// Npc npc;
    sf::Texture mapTexture;
    TileMap map;
	std::vector<Npc> NpcList;
	
    bool right;
	bool left;
	bool up;
	bool down;
	
    int levelWidth;
    int levelHeight;
    
    sf::View mainView;
    sf::Time timePerFrame;
    

    
};

#endif