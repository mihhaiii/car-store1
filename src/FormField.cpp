#include "FormField.h"

FormField::FormField()
{
    //ctor
    shape.setSize(sf::Vector2f(200,20));
    text.setCharacterSize(12);
}

void FormField::setPosition(int x, int y) {
    shape.setPosition(sf::Vector2f(x,y));
    text.setPosition(x+5,y+4);
}

void FormField::addLetter(char c)  {
    if (text.getLength() + 10 > shape.getSize().x ) return;
    text.addLetter(c);
}
void FormField::popLetter() {
    text.popLetter();
}
void FormField::show(sf::RenderWindow& window) {
    window.draw(shape);
    text.show(window);
    if (active) {
        sf::Time time = clock.getElapsedTime();
        if ((int)time.asSeconds() % 2 == 1) {
            showCursor(window);
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
}
bool FormField::isActive(){
    return active;
}
FormField::~FormField()
{
    //dtor
}
