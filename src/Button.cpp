#include "Button.h"

Button::Button(string filename)
: _filename(filename)
{
    //ctor
    _texture.loadFromFile(filename);
    _sprite.setTexture(_texture);

    rect.left = 0;
    rect.width = 0;
    rect.top = 0;
    rect.height = 0;
}

Button::~Button()
{
    //dtor
}

bool Button::isButtonPressedAt(int x, int y){
    return x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.height;
}

void Button::show(sf::RenderWindow& window, int x, int y) {
    _sprite.setPosition(x,y);
    rect.left = x;
    rect.top = y;
    rect.width = _sprite.getLocalBounds().width;
    rect.height = _sprite.getLocalBounds().height;
    window.draw(_sprite);
}

