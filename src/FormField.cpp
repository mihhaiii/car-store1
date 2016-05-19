#include "FormField.h"

FormField::FormField()
{
    //ctor
    shape.setSize(sf::Vector2f(200,20));
    text.setCharacterSize(12);
    text.setStyle("normal");
    active = false;
}

void FormField::setPosition(int x, int y) {
    shape.setPosition(sf::Vector2f(x,y));
    text.setPosition(x+5,y+4);
}

void FormField::addLetter(char c)  {
    if (text.getLength() + 15 > shape.getSize().x ) return;
     string s = text.getText();
    if (s[s.size() - 1] == '|') {
        text.popLetter();
        text.addLetter(c);
        text.addLetter('|');
    } else
    text.addLetter(c);
}
void FormField::popLetter() {
    string s = text.getText();
    if (s[s.size() - 1] == '|') {
        text.popLetter();
        text.popLetter();
        text.addLetter('|');
    } else
    text.popLetter();
}
void FormField::show(sf::RenderWindow& window) {
    window.draw(shape);
    text.show(window);
    if (active) {
        sf::Time time = clock.getElapsedTime();
        if ((int)time.asSeconds() % 2 == 1) {
            string s = text.getText();
            if (s[s.size()-1] != '|')
                text.addLetter('|');
        }
        else {
                string s = text.getText();
            if (s[s.size()-1] == '|')
            {
                s = s.substr(0,s.size()-1);
                text.setText(s);
            }
        }
    }
}
void FormField::showCursor(sf::RenderWindow& window){

}
string FormField::getText(){
    return text.getText();
}

bool FormField::isButtonPressedAt(int x, int y) {
    sf::Rect<float> rect =  shape.getGlobalBounds();
    return x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.height;
}

void FormField::setActive(bool f) {
    active = f;
    if (!active) {
         string s = text.getText();
            if (s[s.size()-1] == '|')
            {
                s = s.substr(0,s.size()-1);
                text.setText(s);
            }
    }
}
bool FormField::isActive(){
    return active;
}
FormField::~FormField()
{
    //dtor
}
