#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
class RegisterScreen
{
    public:
        RegisterScreen();
        virtual ~RegisterScreen();

        void show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif // REGISTERSCREEN_H
