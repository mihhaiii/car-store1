#ifndef LOGINFOSCREEN_H
#define LOGINFOSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class LogInfoScreen
{
    public:
        LogInfoScreen();
        virtual ~LogInfoScreen();

        enum MenuResult { Login, Register, Nothing };

        struct MenuItem{
            sf::Rect<int> rect;
            MenuResult action;
        };

        MenuResult show(sf::RenderWindow&);


    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

        vector<MenuItem> items;
        MenuResult HandleClick(int,int);
};

#endif // LOGINFOSCREEN_H
