#ifndef DISPLAYCARSSCREEN_H
#define DISPLAYCARSSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"

#include "Masina.h"
#include "MasinaManager.h"
#include "Screen.h"
#include "Button.h"
#include "utils.h"
#include "Label.h"

using namespace std;

class DisplayCarsScreen
{
    public:
        DisplayCarsScreen();
        virtual ~DisplayCarsScreen();

        ButtonAction show(sf::RenderWindow&,MasinaManager*);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button leftButton, rightButton, afisDetaliiButton, backButton;

};

#endif // DISPLAYCARSSCREEN_H
