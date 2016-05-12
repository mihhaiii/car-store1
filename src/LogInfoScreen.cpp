#include "LogInfoScreen.h"

LogInfoScreen::LogInfoScreen()
{
    //ctor
    _texture.loadFromFile("images/loginfo.png");
    _sprite.setTexture(_texture);


    MenuItem button1;
    button1.action = Login;
    button1.rect.top = 165;
    button1.rect.height = 254;
    button1.rect.left = 28;
    button1.rect.width = 344;

    MenuItem button2;
    button2.action = Register;
    button2.rect.top = 164;
    button2.rect.height = 253;
    button2.rect.left = 394;
    button2.rect.width = 334;

    items.push_back(button1);
    items.push_back(button2);

}

LogInfoScreen::~LogInfoScreen()
{
    //dtor
}
LogInfoScreen::MenuResult LogInfoScreen::show(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_sprite);
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
                MenuResult result= HandleClick((int)event.mouseButton.x, (int)event.mouseButton.y);
                if (result != Nothing) return  result;
            }
        }
    }
}


LogInfoScreen::MenuResult LogInfoScreen::HandleClick(int x, int y)
{
    for(auto it : items)
    {
        sf::Rect<int> r = it.rect;
        if (x>=r.left && x<=r.left+r.width && y>=r.top && y<=r.top+r.height)
            return it.action;
    }
    return Nothing;
}
