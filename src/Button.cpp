#include "Button.h"

Button::Button(string filename)
: _filename(filename)
{
    //ctor
    _texture.loadFromFile(_filename);
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

void Button::show(sf::RenderWindow& window) {

    window.draw(_sprite);
}
void Button::setPosition(int x, int y)
{
    _sprite.setPosition(x,y);
    rect.left = x;
    rect.top = y;
    rect.width = _sprite.getLocalBounds().width;
    rect.height = _sprite.getLocalBounds().height;
}

sf::Vector2i Button::getPosition() {
    return sf::Vector2i(rect.left, rect.top);
}

ButtonAction Button::getAction() {
    return action;
}
void Button::setAction(ButtonAction g) {
    action = g;
}
