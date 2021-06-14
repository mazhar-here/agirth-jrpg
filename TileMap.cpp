#include "TileMap.hpp"
using json = nlohmann::json;

void TileMap::Initialize(const sf::Texture& tileset,const std::string mapPath){
    
    std::ifstream iDemoMap(mapPath);
    json demoMap;
    iDemoMap>>demoMap;
    
    // std::vector<int>tempMapLayer=demoMap["layers"][0]["data"];
    mapLayer=demoMap["layers"][0]["data"];
    // mapLayer=tempMapLayer;

    // std::vector<int>tempMapLayer2=demoMap["layers"][1]["data"];
    mapLayer2=demoMap["layers"][1]["data"];
    // mapLayer2=tempMapLayer2;    

    // std::vector<std::string>tempCollisionLayer=demoMap["layers"][2]["grid"];
    collisionLayer=demoMap["layers"][2]["grid"];
    // collisionLayer=tempCollisionLayer;

	entityLayer=demoMap["layers"][3]["entities"];


    mapHeight=demoMap["layers"][0]["gridCellsY"];
    mapWidth=demoMap["layers"][0]["gridCellsX"];;
    TILE_SIZE=demoMap["layers"][0]["gridCellWidth"];
    startPlayerPosition=sf::Vector2f(entityLayer[0]["x"],demoMap["layers"][3]["entities"][0]["y"]);


    vertexArray.setPrimitiveType(sf::Quads);
    vertexArray.resize(mapWidth*mapHeight*4);

    vertexArray2.setPrimitiveType(sf::Quads);
    vertexArray2.resize(mapWidth*mapHeight*4);

    int textureColumns=tileset.getSize().x/TILE_SIZE;
    int currentVertex=0;
    

    
    

            
    
    for(int column=0;column<mapWidth;column++){
        for(int row=0;row<mapHeight;row++){

            int currentTile=mapLayer[row+column*mapWidth];
            int currentTextureColumn=currentTile%textureColumns;
            int currentTextureRow=currentTile/textureColumns;

            int currentTile2=mapLayer2[row+column*mapWidth];
            if (currentTile2==-1)
                currentTile2=82;
            int currentTextureColumn2=currentTile2%textureColumns;
            int currentTextureRow2=currentTile2/textureColumns;

            
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

            vertexArray2[currentVertex+0].position=sf::Vector2f(row*TILE_SIZE,column*TILE_SIZE);
            vertexArray2[currentVertex+1].position=sf::Vector2f((row+1)*TILE_SIZE,column*TILE_SIZE);
            vertexArray2[currentVertex+2].position=sf::Vector2f((row+1)*TILE_SIZE,(column+1)*TILE_SIZE);
            vertexArray2[currentVertex+3].position=sf::Vector2f(row*TILE_SIZE,(column+1)*TILE_SIZE);

            vertexArray2[currentVertex+0].texCoords=
            sf::Vector2f(currentTextureColumn2 * TILE_SIZE,currentTextureRow2*TILE_SIZE);
            vertexArray2[currentVertex+1].texCoords=
            sf::Vector2f((currentTextureColumn2+1)*TILE_SIZE,currentTextureRow2*TILE_SIZE);
            vertexArray2[currentVertex+2].texCoords=
            sf::Vector2f((currentTextureColumn2+1)*TILE_SIZE,(currentTextureRow2+1)*TILE_SIZE);
            vertexArray2[currentVertex+3].texCoords=
            sf::Vector2f(currentTextureColumn2*TILE_SIZE,(currentTextureRow2+1)*TILE_SIZE);

            currentVertex=currentVertex+4;
            

            

        }
    }
	
	GetNpcList();




}

void TileMap::Draw(sf::RenderWindow& window,const sf::Texture& tileset){
    window.draw(vertexArray,&tileset);
    window.draw(vertexArray2,&tileset);
   
}

int TileMap::GetTileSize(){
        return TILE_SIZE;
}

sf::Vector2<int> TileMap::GetTileIndex(sf::Vector2f position) const{
   int tileX=position.x/TILE_SIZE;
   int tileY=position.y/TILE_SIZE;
   return sf::Vector2<int>(tileX,tileY); 
}

sf::Vector2f TileMap::GetTilePixelPosition(int x, int y){
    return sf::Vector2f(x*TILE_SIZE,y*TILE_SIZE);
}

sf::Vector2i TileMap::GetMapDimensions() const{
    return sf::Vector2i(mapWidth,mapHeight);
}



sf::Vector2f TileMap::GetStartPlayerPosition(){
    return startPlayerPosition;
}

bool TileMap::IsPassable(const sf::Vector2i gameObjectTile) const{
	if(collisionLayer[gameObjectTile.x+gameObjectTile.y*GetMapDimensions().x]=="1"){
			return true;
        }
	return false;
}

std::map<std::string, sf::Vector2f> TileMap::GetNpcList(){
	
	std::map<std::string, sf::Vector2f> tempNpcList;
	
	for (json::iterator it = entityLayer.begin()+1 ; it != entityLayer.end(); ++it) {
		std::string tempName=(*it)["name"];
		sf::Vector2f tempPosition=sf::Vector2f((*it)["x"],(*it)["y"]);
		
		std::cout<<tempName<<":"<<tempPosition.x<<","<<tempPosition.y<<std::endl;
		tempNpcList.insert({tempName,tempPosition});
	}
	
	return tempNpcList;
	
}






