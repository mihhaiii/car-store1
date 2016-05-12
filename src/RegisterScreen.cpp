#include "RegisterScreen.h"

RegisterScreen::RegisterScreen()
{
    //ctor
    _texture.loadFromFile("images/registerscreen.png");
    _sprite.setTexture(_texture);
}

RegisterScreen::~RegisterScreen()
{
    //dtor
}


void RegisterScreen::show(sf::RenderWindow& window) {
    window.clear();
    window.draw(_sprite);
    window.display();

    sf::Clock c;
    sf::Time t = sf::seconds(5);
    while (c.getElapsedTime() < t) {};
}

