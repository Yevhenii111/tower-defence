#pragma once

#include "map.hpp"
#include "enemy.hpp"
#include <math.h>

class Tower
{
private:
    Image image;
    Texture texture;
    Sprite sprite;
    Image image_b;
    Texture texture_b;
    Sprite sprite_b;
    float distance_b;
    Vector2f pos_b;
    bool bullet_life;
    int is_attack, ii;
    float power;
    RectangleShape attackZone;

public:
    static std::list<Tower *> towers;
    static std::list<Tower *>::iterator towers_it;
    static int tower_type, i_tow, j_tow;
    static void full_create(int &);
    static void tower_game(RenderWindow &, float &, int &, Data &);

    Vector2f getPosition();
    Vector2f getPosition_b();
    void update(float);
    void create(int);
    void setPosition(Vector2f);
    void setPosition_b(Vector2f);
    void draw(RenderWindow &);
    void draw_b(RenderWindow &);
    void upgrade();
    Tower();
    ~Tower();
};