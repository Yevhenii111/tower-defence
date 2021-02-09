#include "healthbar.hpp"

HealthBar::HealthBar()
{
    hb_image.loadFromFile("images/healthbar.png");
    hb_texture.loadFromImage(hb_image);
    hb_sprite.setTexture(hb_texture);

    bar.setFillColor(sf::Color(0,0,0));
    max = 10;

}

void HealthBar::hb_update(int Health, float X, float Y)
{
    if(Health > 0 && Health < max)
    {
        bar.setSize(Vector2f(-((max - Health) * 35 / max), 6));
    }

    hb_sprite.setPosition(X + 10,Y + 10);
    bar.setPosition(X + 46,Y + 10);
}