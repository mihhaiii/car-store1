#ifndef MYCARTSCREEN_H
#define MYCARTSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Button.h"
#include "MasinaManager.h"

class MyCartScreen
{
    public:
        MyCartScreen();
        virtual ~MyCartScreen();

        ButtonAction show(sf::RenderWindow& , MasinaManager*);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button backButton;
        MasinaManager _MyCartCars;
};

#endif // MYCARTSCREEN_H
