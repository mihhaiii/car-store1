#include "MyCartScreen.h"

MyCartScreen::MyCartScreen() : backButtonObj("images/backbutton.png")
{
    //ctor
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);
    backButtonObj.SetPosition(10,540);
    backButtonObj.SetAction(BackAction);
}

MyCartScreen::~MyCartScreen()
{
    //dtor
}

ButtonAction MyCartScreen::Show(sf::RenderWindow& window, MasinaManager* mm)
{
    window.clear();
    window.draw(_sprite);
    backButtonObj.Show(window);
    window.display();

    int currentCarIndex = 0;
    int cartCarsNumber = mm->GetCarsCount();

    vector<Button*> cartButtons;
    cartButtons.push_back(&backButtonObj);

    while(1)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                return ExitAction;
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto button : cartButtons)
                {
                    if (button->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        return button->GetAction();
                    }
                }
            }
            else if (event.type == sf::Event::MouseWheelMoved)
            {
                currentCarIndex += event.mouseWheel.delta;
                cout << currentCarIndex << "\n";
            }

        }
    }
    backButtonObj.Show(window);
    window.display();

}
