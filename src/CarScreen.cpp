
#include "CarScreen.h"

CarScreen::CarScreen() : backButtonObj("images/backbutton.png")
{
    _texture.loadFromFile("images/background1.png");
    _sprite.setTexture(_texture);
    backButtonObj.SetPosition(10,540);
}
CarScreen::~CarScreen()
{
    //dtor
}
void CarScreen::DrawAll(sf::RenderWindow& window, Masina* masina) {
    window.draw(_sprite);
    masina->showImage(window);
    masina->showInfo(window);
    backButtonObj.Show(window);
}
ButtonAction CarScreen::Show(sf::RenderWindow& window, Masina* masina)
{
    window.clear();
    DrawAll(window,masina);
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
                return NothingAction;
                break;
            case sf::Event::MouseButtonPressed:
                if (backButtonObj.IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        return BackAction;
            }
        }

        window.clear();
        DrawAll(window,masina);
        window.display();

    }
}
