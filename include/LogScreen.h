#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class LogScreen
{
    public:
        LogScreen();
        virtual ~LogScreen();

        void show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif // LOGSCREEN_H
