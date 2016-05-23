#include "FormField.h"

FormField::FormField()
{
    shape.setSize(sf::Vector2f(200, 20));
    textLabelObj.SetCharacterSize(12);
    textLabelObj.SetStyle("normal");
    _active = false;
    _passwordType = false;
}

FormField::~FormField()
{
    //dtor
}

void FormField::SetPosition(int x, int y) {
    shape.setPosition(sf::Vector2f(x, y));
    textLabelObj.SetPosition(x+5, y+4);
}

void FormField::AddLetter(char c) {
    if (textLabelObj.GetLength() + 15 > shape.getSize().x )
        return;
    string s = textLabelObj.GetText();
    if (s[s.size() - 1] == '|') {
        textLabelObj.PopLetter();
        textLabelObj.AddLetter(c);
        textLabelObj.AddLetter('|');
    }
    else
        textLabelObj.AddLetter(c);
}
void FormField::PopLetter() {
    string s = textLabelObj.GetText();
    if (s[s.size() - 1] == '|') {
        textLabelObj.PopLetter();
        textLabelObj.PopLetter();
        textLabelObj.AddLetter('|');
    }
    else
        textLabelObj.PopLetter();
}
void FormField::Show(sf::RenderWindow& window) {
    window.draw(shape);
    if (_passwordType) {
        textLabelObj.ShowPasswordType(window);
    }
    else textLabelObj.Show(window);
    if (_active) {
        sf::Time time = clock.getElapsedTime();
        if ((int)time.asSeconds() % 2 == 1) {
            string s = textLabelObj.GetText();
            if (s[s.size()-1] != '|')
                textLabelObj.AddLetter('|');
        }
        else {
            string s = textLabelObj.GetText();
            if (s[s.size()-1] == '|') {
                s = s.substr(0,s.size()-1);
                textLabelObj.SetText(s);
            }
        }
    }
}
void FormField::ShowCursor(sf::RenderWindow& window) {

}
string FormField::GetText() {
    return textLabelObj.GetText();
}

bool FormField::IsButtonPressedAt(int x, int y) {
    sf::Rect<float> rect =  shape.getGlobalBounds();
    return x >= rect.left && x <= rect.left + rect.width && y >= rect.top && y <= rect.top + rect.height;
}

void FormField::SetActive(bool f) {
    _active = f;
    if (!_active) {
         string s = textLabelObj.GetText();
            if (s[s.size()-1] == '|')
            {
                s = s.substr(0,s.size()-1);
                textLabelObj.SetText(s);
            }
    }
}
bool FormField::IsActive(){
    return _active;
}

void FormField::SetPasswordType(bool f) {
    _passwordType = f;
}

