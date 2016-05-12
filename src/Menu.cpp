#include "Menu.h"

Menu::Menu()
{
    //ctor
    _texture.loadFromFile("images/menu.png");
    _sprite.setTexture(_texture);

    MenuItem m1;
    m1.action = AfiseazaMasini;
    m1.rect.top = 78;
    m1.rect.height = 38;
    m1.rect.left = 82;
    m1.rect.width = 248;

    MenuItem m2;
    m2.action = Iesire;
    m2.rect.top = 132;
    m2.rect.height = 38;
    m2.rect.left = 84;
    m2.rect.width = 244;


    items.push_back(m1);
    items.push_back(m2);
}

Menu::~Menu()
{
    //dtor
}

Menu::MenuResult Menu::show(sf::RenderWindow& window)
{
    window.clear();
    window.draw(_sprite);
    window.display();

    sf::Event e;
    while (1)
    {
        while (window.pollEvent(e))
        {
            switch(e.type)
            {
            case sf::Event::Closed:
                window.close();
                return Nothing;
                break;
            case sf::Event::MouseButtonPressed:
                MenuResult res=HandleClick((int)e.mouseButton.x,(int)e.mouseButton.y);
                if (res != Nothing) return res;
            }
        }
    }
}

Menu::MenuResult Menu::HandleClick(int x, int y)
{
    for(auto it : items)
    {
        sf::Rect<int> r = it.rect;
        if (x>=r.left && x<=r.left+r.width &&y>=r.top && y<=r.top+r.height)
            return it.action;
    }
    return Nothing;
}
