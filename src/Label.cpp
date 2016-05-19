#include "Label.h"

Label::Label()
{
    //ctor
    font.loadFromFile("arial.ttf");
    str = "";
    text.setString(str);
    text.setCharacterSize(12);
    text.setFont(font);
    text.setStyle(sf::Text::Italic);
    text.setColor(sf::Color::Black);

    visible = true;
}

void Label::setVisible(bool f) {
    visible = f;
}

void Label::setColor(string c) {
    if (c=="red") text.setColor(sf::Color::Red);
    if (c=="blue") text.setColor(sf::Color::Blue);
    if (c=="green") text.setColor(sf::Color::Green);
    if (c=="yellow") text.setColor(sf::Color::Yellow);
}

void Label::setText(string x) {
    str=x;
    text.setString(str);
}
string Label::getText() {
    return str;
}
void Label::setPosition(int x, int y) {
    text.setPosition(sf::Vector2f(x,y));
}
void Label::setCharacterSize(int sz)  {
    text.setCharacterSize(sz);
}
void Label::setStyle(string st) {
   if (st == "italic") text.setStyle(sf::Text::Italic);
   if (st == "bold") text.setStyle(sf::Text::Bold);
   if (st == "underlined") text.setStyle(sf::Text::Underlined);
   if (st == "normal") text.setStyle(sf::Text::Regular);
}

void Label::addLetter(char c) {
    str += c;
    text.setString(str);
}
void Label::popLetter() {
    if (str.size() != 0) {
        str=str.substr(0,str.size()-1);
        text.setString(str);
    }
}

int Label::getLength() {
    return text.getLocalBounds().width;
}

Label::~Label()
{
    //dtor
}

void Label::show(sf::RenderWindow& window) {
   if (visible) window.draw(text);
}
