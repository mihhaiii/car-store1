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

    int currentCar = 0;
    int cartCarsNumber = mm->getMasinaCount();

    vector<Button*> cartButtons;
    cartButtons.push_back(&backButton);

    while(1)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                return Exit;
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto button : cartButtons)
                {
                    if (button->isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        return button->getAction();
                    }
                }
            }
            else if (event.type == sf::Event::MouseWheelMoved)
            {
                currentCar += event.mouseWheel.delta;
                cout<<currentCar<<"\n";
            }

        }
    }
    backButton.show(window);
    window.display();

}
