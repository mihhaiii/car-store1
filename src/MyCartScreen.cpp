#include "MyCartScreen.h"

MyCartScreen::MyCartScreen() : backButton("images/backbutton.png")
{
    //ctor
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);
    backButton.setPosition(10,540);

    backButton.setAction(Back);
}

MyCartScreen::~MyCartScreen()
{
    //dtor
}

ButtonAction MyCartScreen::show(sf::RenderWindow& window, MasinaManager* mm)
{
    window.clear();
    window.draw(_sprite);
    backButton.show(window);
    window.display();

    int curr = 0;
    int cartCarsNumber = mm->getMasinaCount();

    vector<Button*> cartButtons;
    cartButtons.push_back(&backButton);



}
