#ifndef MYCARTSCREEN_H
#define MYCARTSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Button.h"
#include "MasinaManager.h"

using namespace std;

class MyCartScreen
{
    public:
        MyCartScreen();
        virtual ~MyCartScreen();

        ButtonAction Show(sf::RenderWindow& , MasinaManager*);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button backButtonObj;
};

#endif // MYCARTSCREEN_H
