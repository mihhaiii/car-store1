#ifndef LOGSCREEN_H
#define LOGSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Button.h"

using namespace std;
class LogScreen
{
    public:
        LogScreen();
        virtual ~LogScreen();

        ButtonAction show(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Button usernameField, parolaField, OKButton;
        bool writingUsername, writingParola;
        string usernameSoFar, parolaSoFar;
};

#endif // LOGSCREEN_H
