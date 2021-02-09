#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class HealthBar
{
public:
    Image hb_image;
    Texture hb_texture;
    Sprite hb_sprite;
    RectangleShape bar;

    int max;  

    HealthBar(); 
    void hb_update(int, float, float);
    
};