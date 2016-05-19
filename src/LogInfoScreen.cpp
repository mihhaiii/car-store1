#include "LogInfoScreen.h"

LogInfoScreen::LogInfoScreen()
{
    //ctor
    _texture.loadFromFile("images/loginfo.png");
    _sprite.setTexture(_texture);

}

LogInfoScreen::~LogInfoScreen()
{
    //dtor
}
ButtonAction LogInfoScreen::show(sf::RenderWindow& window)
{
    Button b1("images/loginbutton.png");
    b1.setPosition(264,245);
    b1.setAction(ShowLogSreen);

    Button b2("images/registerbutton.png");
    b2.setPosition(264, 291);
    b2.setAction(ShowRegisterScreen);

    items.push_back(b1);
    items.push_back(b2);

    window.clear();
    window.draw(_sprite);
    for (auto b : items) b.show(window);
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
                for(auto b :items) if (b.isButtonPressedAt((int)event.mouseButton.x, (int)event.mouseButton.y))
                    if (b.getAction() != Nothing) return b.getAction();
            }
        }
    }
}

