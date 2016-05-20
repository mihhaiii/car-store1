#ifndef REGISTERSCREEN_H
#define REGISTERSCREEN_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "utils.h"
#include "Label.h"
#include "FormField.h"
#include "UserManager.h"
#include "Checker.h"
using namespace std;
class RegisterScreen
{
    public:
        RegisterScreen();
        virtual ~RegisterScreen();

        ButtonAction show(sf::RenderWindow&, UserManager*);
        void drawAll(sf::RenderWindow&);
        void showSuccess(sf::RenderWindow&);

    protected:

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;

        Label registerLabel, numeLabel, usernameLabel, parolaLabel, emailLabel, congratsLabel, pressKeyLabel,
         warningLabel, warningNume, warningParola, warningEmail, warningUsername;

        Button registerButton, backButton;

        FormField nume, username, parola, email;
        void setActive(FormField*);
};

#endif // REGISTERSCREEN_H
