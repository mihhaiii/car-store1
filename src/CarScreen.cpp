
#include "CarScreen.h"

CarScreen::CarScreen() : backButton("images/backbutton.png")
{
    _texture.loadFromFile("images/background1.png");
    _sprite.setTexture(_texture);
    backButton.setPosition(10,540);
}
CarScreen::~CarScreen()
{
    //dtor
}
void CarScreen::drawAll(sf::RenderWindow& window, Masina* masina) {
    window.draw(_sprite);
    masina->showImage(window);
    masina->showInfo(window);
    backButton.show(window);
}
ButtonAction CarScreen::show(sf::RenderWindow& window, Masina* masina)
{
    window.clear();
    drawAll(window,masina);
    window.display();

    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                return Nothing;
                break;
            case sf::Event::MouseButtonPressed:
                if (backButton.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        return Back;
            }
        }

        window.clear();
        drawAll(window,masina);
        window.display();

    }
}
