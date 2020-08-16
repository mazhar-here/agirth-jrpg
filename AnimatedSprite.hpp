#include <SFML/Graphics.hpp>

class AnimatedSprite{
    std::vector<sf::IntRect> frameList;
    float timePerFrame;
    sf::Sprite& sprite;
    int currentFrame;
    float progress;





    
    
    public:
    //AnimatedSprite();
    AnimatedSprite(sf::Sprite& sprite,float timePerFrame);
    //AnimatedSprite& operator=(const AnimatedSprite &rhs);
    void Update(float);
    void AddFrame(sf::IntRect); 
    void Initialize(int rows,int columns,int spriteHeight,int spriteWidth);
};
