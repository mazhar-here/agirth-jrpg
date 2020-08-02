#include <SFML/Graphics.hpp>

class AnimatedSprite{
    std::vector<sf::IntRect> frameList;
    float timePerFrame;
    sf::Sprite& sprite;
    int currentFrame;
    float progress;
    
    public:
    AnimatedSprite();
    AnimatedSprite(sf::Sprite&,float);
    void Update(float);
    void AddFrame(sf::IntRect); 
    void Initialize(int,int,int,int);
};
