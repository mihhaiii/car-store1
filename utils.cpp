#include <string>
#include "utils.h"


const char* Brands2Str[] =
{
    "FIAT",
    "BMW",
    "FORD",
    "DACIA",
    "AUDI"
};

const char* Models2Str[] =
{
    "a32",
    "f5",
    "h1100",
    "j3r3",
    "lk90"
};

string int2str(int x){
    string s("");
    while (x) {
        s = char(x%10+'0')+s;
        x/=10;
    }
    return s;
}



void showText(string x, sf::RenderWindow& window)
{
    x += ".";
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(x);
        text.setCharacterSize(24);
        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);

        text.setPosition(50,50);
        window.draw(text);
}
