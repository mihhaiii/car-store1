#ifndef MENU_H
#define MENU_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class Menu
{
    public:
        Menu();
        virtual ~Menu();

        enum MenuResult { AfiseazaMasini, Iesire, Nothing };

        struct MenuItem
        {
            sf::Rect<int> rect;
            MenuResult action;
        };

        MenuResult show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        vector<MenuItem> items;

        MenuResult HandleClick(int,int);
};

#endif // MENU_H
