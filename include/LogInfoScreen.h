#ifndef LOGINFOSCREEN_H
#define LOGINFOSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Button.h"
using namespace std;
class LogInfoScreen
{
    public:
        LogInfoScreen();
        virtual ~LogInfoScreen();

        ButtonAction show(sf::RenderWindow&);


    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        vector<Button> items;
};

#endif // LOGINFOSCREEN_H
