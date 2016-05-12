#ifndef DISPLAYCARSSCREEN_H
#define DISPLAYCARSSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "Masina.h"
#include "MasinaManager.h"
#include "Screen.h"
class DisplayCarsScreen : public Screen
{
    public:
        DisplayCarsScreen();
        virtual ~DisplayCarsScreen();

        void show(sf::RenderWindow&,MasinaManager*);

    protected:

    private:
};

#endif // DISPLAYCARSSCREEN_H
