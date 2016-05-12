#include "LogScreen.h"

LogScreen::LogScreen()
{
    //ctor
    _texture.loadFromFile("images/logscreen.png");
    _sprite.setTexture(_texture);
}

LogScreen::~LogScreen()
{
    //dtor
}

void LogScreen::show(sf::RenderWindow& window) {
    window.clear();
    window.draw(_sprite);
    window.display();

    sf::Clock c;
    sf::Time t = sf::seconds(5);
    while (c.getElapsedTime() < t) {};
}
