#ifndef LABEL_H
#define LABEL_H


#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "utils.h"

class Label
{
    public:
        Label();
        virtual ~Label();

        void show(sf::RenderWindow&);
        void setText(string);
        void setPosition(int,int);
        void setStyle(string);
        void setCharacterSize(int);
        void popLetter();
        void addLetter(char);
        int getLength();
        string getText();
        void setVisible(bool);
        void setColor(string);

    protected:
        string str;
        sf::Text text;
        sf::Font font;
    private:
        bool visible;
};

#endif // LABEL_H
