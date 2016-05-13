#ifndef BUTTON_H
#define BUTTON_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "C:\Users\Mihai\Desktop\magazin_masini\utils.h"

class Button
{
    public:
        Button(string);
        virtual ~Button();

        bool isButtonPressedAt(int,int);
        void show(sf::RenderWindow&,int,int);

    protected:

        sf::Rect<int> rect;
        ButtonAction action;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        string _filename;
};

#endif // BUTTON_H
