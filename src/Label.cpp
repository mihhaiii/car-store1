#include "Label.h"

Label::Label()
{
    //ctor
    font.loadFromFile("arial.ttf");
    _str = "";
    text.setString(_str);
    text.setCharacterSize(12);
    text.setFont(font);
    text.setStyle(sf::Text::Italic);
    text.setColor(sf::Color::Black);

    _visible = true;
}

Label::~Label()
{
    //dtor
}

void Label::SetVisible(bool f) {
    _visible = f;
}

void Label::SetColor(string c) {
    if (c=="red") text.setColor(sf::Color::Red);
    if (c=="blue") text.setColor(sf::Color::Blue);
    if (c=="green") text.setColor(sf::Color::Green);
    if (c=="yellow") text.setColor(sf::Color::Yellow);
}

void Label::SetText(string x) {
    _str = x;
    text.setString(_str);
}
string Label::GetText() {
  //  if (str[str.size()-1] == '|') return str.substr(0,str.size()-1);
    return _str;
}
void Label::SetPosition(int x, int y) {
    text.setPosition(sf::Vector2f(x,y));
}
void Label::SetCharacterSize(int sz)  {
    text.setCharacterSize(sz);
}
void Label::SetStyle(string st) {
   if (st == "italic") text.setStyle(sf::Text::Italic);
   if (st == "bold") text.setStyle(sf::Text::Bold);
   if (st == "underlined") text.setStyle(sf::Text::Underlined);
   if (st == "normal") text.setStyle(sf::Text::Regular);
}

void Label::AddLetter(char c) {
    _str += c;
    text.setString(_str);
}
void Label::PopLetter() {
    if (_str.size() != 0) {
        _str = _str.substr(0,_str.size()-1);
        text.setString(_str);
    }
}

int Label::GetLength() {
    return text.getLocalBounds().width;
}

void Label::Show(sf::RenderWindow& window) {
   if (_visible)
        window.draw(text);
}
void Label::ShowPasswordType(sf::RenderWindow& window) {
    if (_visible) {
        string encrypted_string = _str;
        for(int i = 0;i < encrypted_string.size(); i++)
            if (encrypted_string[i]!='|') encrypted_string[i] = '*';
        text.setString(encrypted_string);
        window.draw(text);
        text.setString(_str);
    }
}
