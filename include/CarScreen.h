#ifndef CARSCREEN_H
#define CARSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"
#include "MasinaManager.h"
#include "Button.h"
#include "Label.h"

using namespace std;

class CarScreen
{
    public:
        CarScreen();
        virtual ~CarScreen();

        ButtonAction show(sf::RenderWindow&, Masina*);
        void drawAll(sf::RenderWindow&, Masina*);

    protected:

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

        Button backButton;
};

#endif // CARSCREEN_H
