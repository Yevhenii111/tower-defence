#include "data.hpp"

int Data::full_score = 0;

Data::Data(int Helth, int Coins)
{
    health = Helth;
    coins = Coins;
    score = 0;
}

MyText::MyText()
{
    font.loadFromFile("GothicE.ttf");
    text.setFont(font);
    text.setString("");
    text.setCharacterSize(38);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
}

MyText::MyText(RenderWindow &window)
{
    font.loadFromFile("GothicE.ttf");
    text.setFont(font);
    std::ostringstream full_scoreString;
    full_scoreString << "Your score: " << Data::full_score;
    text.setCharacterSize(64);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setString(full_scoreString.str());
    text.setPosition(30, 500);
    window.draw(text);
}

void MyText::text_display(RenderWindow &window, Data &data)
{
    std::ostringstream healthString, scoreString, coinsString;
    healthString << data.health;
    text.setString(healthString.str());
    text.setPosition(805, 19);
    window.draw(text);

    scoreString << data.score;
    text.setString(scoreString.str());
    text.setPosition(785, 77);
    window.draw(text);

    coinsString << data.coins;
    text.setString(coinsString.str());
    text.setPosition(785, 137);
    window.draw(text);
}