#ifndef BUTTON_H
#define BUTTON_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "utils.h"

class Button
{
    public:
        Button(string);
        virtual ~Button();

        bool isButtonPressedAt(int,int);
        void show(sf::RenderWindow&);
        void setPosition(int,int);
        sf::Vector2i getPosition();
        ButtonAction getAction();
        void setAction(ButtonAction);


    protected:

        sf::Rect<int> rect;
        ButtonAction action;

    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        string _filename;
};

#endif // BUTTON_H
