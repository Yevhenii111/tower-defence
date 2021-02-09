#pragma once

#include "way.hpp"
#include <vector>
#include "healthbar.hpp"

class Enemy : public HealthBar
{
private:
    float x, y, w, h, dx, dy, speed;
    int i, i_trace, i_trace_beg, ii, dir, type;
    float CurrentFrame, timer_trace;
    Image image, image_trace;
    Texture texture, texture_trace;
    Sprite sprite_trace;
    std::vector<Sprite> SpriteTrace;
    std::vector<int> way;

public:

    static std::list<Enemy *> enemyes;
    static std::list<Enemy *>::iterator it;
    static int num_i, wave, spawn_type;
    static float enemy_timer, time, spawn_kof, x_beg, y_beg;
    static bool end_enemyes;
    static Vector2i start, finish;
    static void spawn();
    static void draw(RenderWindow &, float &, Data &);
    static void begin_values(float, int, float, float, Vector2i, Vector2i, int &);

    Sprite sprite;
    int health, number;
    bool life, trace_life, new_wall;

    Enemy(float, float, float, float, int, int);
    void update(float);
    void lion_and_trace(RenderWindow &, float &, Data &);
    void trip(float &, Data &);
    FloatRect getRect();
};