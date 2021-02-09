#pragma once

#include "map.hpp"

class BG
{
private:
    int type_BG;
    Image image_BG;
    Texture texture_BG;
public:
    bool select_tower_BG;
    int tower_type_BG;
    Sprite sprite_BG;
    BG(int);
};

void bg_draw(RenderWindow &, bool &, int &, Map &, Data &, int &);