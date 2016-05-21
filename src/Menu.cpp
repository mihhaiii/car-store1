#include "Menu.h"

Menu::Menu() :
    listaMasiniButton("images/listamasinibutton.png"),
    iesireButton("images/iesirebutton.png"),
    cosulMeuButton("images/cosulmeubutton.png"),
    logoutButton("images/logoutbutton.png")
{
    //ctor
    _texture.loadFromFile("images/meniu.png");
    _sprite.setTexture(_texture);

    listaMasiniButton.setPosition(300,70);
    cosulMeuButton.setPosition(300,105);
    logoutButton.setPosition(300,140);
    iesireButton.setPosition(300,175);

    listaMasiniButton.setAction(ShowCars);
    cosulMeuButton.setAction(ShowMyCart);
    logoutButton.setAction(ShowLogInfo);
    iesireButton.setAction(Exit);

    meniu.setPosition(370,40);
    meniu.setText("Meniu");
    meniu.setCharacterSize(24);
    meniu.setStyle("normal");
}

Menu::~Menu()
{
    //dtor
}

ButtonAction Menu::show(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_sprite);
    listaMasiniButton.show(window);
    cosulMeuButton.show(window);
    logoutButton.show(window);
    iesireButton.show(window);
    meniu.show(window);
    window.display();

    vector<Button*> buttons;
    buttons.push_back(&listaMasiniButton);
    buttons.push_back(&iesireButton);
    buttons.push_back(&logoutButton);
    buttons.push_back(&cosulMeuButton);

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
                {
                    int x=event.mouseButton.x, y=event.mouseButton.y;
                    for(auto button:buttons) {
                        if (button->isButtonPressedAt(x,y)) {
                            if (button->getAction() != Nothing) {
                                return button->getAction();
                            }
                        }
                    }
                }
            }
        }
    }
}

