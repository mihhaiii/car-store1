#ifndef DISPLAYCARSSCREEN_H
#define DISPLAYCARSSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "utils.h"

#include "Masina.h"
#include "MasinaManager.h"
#include "Screen.h"
#include "Button.h"

class DisplayCarsScreen : public Screen
{
    public:
        DisplayCarsScreen();
        virtual ~DisplayCarsScreen();

        void show(sf::RenderWindow&,MasinaManager*);

    protected:

    private:
        Button leftButton, rightButton, afisDetaliiButton;// backButton;
};

#endif // DISPLAYCARSSCREEN_H
