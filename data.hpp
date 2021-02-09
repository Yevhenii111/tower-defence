#pragma once

#include <SFML\Graphics.hpp>
#include <sstream>
using namespace sf;

class Data
{
public:
    int health;
    int score;
    int coins;
    static int full_score;
    Data(int, int);
};

class MyText
{
private:
    Font font;
    Text text;
public: 
    MyText();
    MyText(RenderWindow &);
    void text_display(RenderWindow &, Data &);
};