#pragma once

#include <vector>
#include <iostream>
#include <list>
#include "menu.hpp"
#include "data.hpp"
#include "towers.hpp"
using namespace sf;

class Map
{
public:
    int HEIGHT_MAP, WIDTH_MAP, num;
    bool wall_select;
    static String TileMap[20];
    Map(int);
    String getTileCode(int , int );
    void setTileCode(int, int, char);
};

class Cell
{
private:
    int type_Cell;
    Image image_Cell;
    Texture texture_Cell;
public:
    Sprite sprite_Cell;
    Cell(int);
};

void map_draw(RenderWindow &, bool &, int &,  Data &, int &);