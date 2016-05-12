#include "Screen.h"

Screen::Screen()
{
    //ctor
     _texture.loadFromFile("images/screen.jpg");
    _sprite.setTexture(_texture);
}

Screen::~Screen()
{
    //dtor
}

void Screen::show(sf::RenderWindow&w)
{
    w.draw(_sprite);
}

