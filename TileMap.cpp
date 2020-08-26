#include "TileMap.hpp"
using json = nlohmann::json;

void TileMap::Initialize(const sf::Texture& tileset,const int* level,const int levelWidth,const int levelHeight){
    
    
    json demoMap;
    std::ifstream iDemoMap("DemoMap.json")>>demoMap;
    std::vector<int>tempDemoMap=demoMap["layers"][0]["data"];
    mapLayer=tempDemoMap;
    
    // this->levelHeight=levelHeight;
    // this->levelWidth=levelWidth;

    this->levelHeight1=demoMap["layers"][0]["gridCellsY"];
    this->levelWidth1=demoMap["layers"][0]["gridCellsX"];;

    vertexArray.setPrimitiveType(sf::Quads);
    TILE_SIZE=16;
    vertexArray.resize(levelWidth1*levelHeight1*4);
    int textureColumns=tileset.getSize().x/TILE_SIZE;
    int currentVertex=0;
    

    
    

            
    
    for(int row=0;row<levelWidth1;row++){
        for(int column=0;column<levelHeight1;column++){

            int currentTile=mapLayer[row+column*levelWidth1];
            int currentTextureColumn=currentTile%textureColumns;
            int currentTextureRow=currentTile/textureColumns;
            
            vertexArray[currentVertex+0].position=sf::Vector2f(row*TILE_SIZE,column*TILE_SIZE);
            vertexArray[currentVertex+1].position=sf::Vector2f((row+1)*TILE_SIZE,column*TILE_SIZE);
            vertexArray[currentVertex+2].position=sf::Vector2f((row+1)*TILE_SIZE,(column+1)*TILE_SIZE);
            vertexArray[currentVertex+3].position=sf::Vector2f(row*TILE_SIZE,(column+1)*TILE_SIZE);

            vertexArray[currentVertex+0].texCoords=
            sf::Vector2f(currentTextureColumn * TILE_SIZE,currentTextureRow*TILE_SIZE);
            vertexArray[currentVertex+1].texCoords=
            sf::Vector2f((currentTextureColumn+1)*TILE_SIZE,currentTextureRow*TILE_SIZE);
            vertexArray[currentVertex+2].texCoords=
            sf::Vector2f((currentTextureColumn+1)*TILE_SIZE,(currentTextureRow+1)*TILE_SIZE);
            vertexArray[currentVertex+3].texCoords=
            sf::Vector2f(currentTextureColumn*TILE_SIZE,(currentTextureRow+1)*TILE_SIZE);
            
            currentVertex=currentVertex+4;
            

            

        }
    }





}

void TileMap::Draw(sf::RenderWindow& window,const sf::Texture& tileset){
    window.draw(vertexArray,&tileset);
}

int TileMap::GetTileSize(){
        return TILE_SIZE;
}

sf::Vector2<int> TileMap::GetTileIndex(sf::Vector2f position){
   int tileX=position.x/TILE_SIZE;
   int tileY=position.y/TILE_SIZE;
   return sf::Vector2<int>(tileX,tileY); 
}

sf::Vector2f TileMap::GetTilePixelPosition(int x, int y){
    return sf::Vector2f(x*TILE_SIZE,y*TILE_SIZE);
}







