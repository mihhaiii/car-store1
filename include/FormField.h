#ifndef FORMFIELD_H
#define FORMFIELD_H



#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "utils.h"
#include "Label.h"

class FormField
{
    public:
        FormField();
        virtual ~FormField();

        void addLetter(char);
        void popLetter();
        void setPosition(int,int);
        void show(sf::RenderWindow&);
        bool isButtonPressedAt(int,int);
        string getText();
        void setActive(bool);
        bool isActive();
        void setPasswordType(bool);

    protected:
        sf::RectangleShape shape;
        Label text;
        bool active;
        sf::Clock clock;

        void showCursor(sf::RenderWindow&);
        bool passwordType;

    private:
};

#endif // FORMFIELD_H
