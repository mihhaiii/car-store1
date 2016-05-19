#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Button.h"
#include "Label.h"
#include "FormField.h"

using namespace std;
class LogScreen
{
    public:
        LogScreen();
        virtual ~LogScreen();

        ButtonAction show(sf::RenderWindow&);
        void drawAll(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button OKButton;
        FormField username, parola;
        Label parolaLabel, usernameLabel, logareLabel;
};

#endif // LOGSCREEN_H
