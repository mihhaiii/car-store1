#include "Masina.h"
#include <ctime>
#include <random>
Masina::Masina()
{
     nrMasini++;
    id  = nrMasini;
    _filename = CarFiles[rand()%10];
    _texture.loadFromFile(_filename);
    _sprite.setTexture(_texture);
    _sprite.setPosition(sf::Vector2f(150,200));
}
string Masina::getFilename() {
    return _filename;
}
void Masina::setFilename(string s) {
    _filename = s;
    _texture.loadFromFile(s);
    _sprite.setTexture(_texture);
}

Masina::~Masina()
{
    //dtor
}
Masina::Masina(Brands s, Models t, int a, int b) :
   marca(s), model(t), pret(a), an(b)  {
    nrMasini++;
    id  = nrMasini;

    string filename = CarFiles[rand()%10];
    _texture.loadFromFile(filename);
    _sprite.setTexture(_texture);
    _sprite.setPosition(sf::Vector2f(150,200));
}


Brands Masina::getRandBrand()
{
    return (Brands)(rand() % 10);
}

Models Masina::getRandModel()
{
    return Models(rand() % 10);
}

Brands Masina::getMarca() {
    return marca;
}
Models Masina::getModel() {
    return model;
}
int Masina::getPret() {
    return pret;
}
int Masina::getAn() {
    return an;
}

void Masina::showImage(sf::RenderWindow& window)
{
        window.draw(_sprite);
}

void Masina::showInfo(sf::RenderWindow& window)
{
        string str;

        str = "";
        str += "Marca : ";
        str += Brands2Str[model];
        str += "\n";

        str += "Model : ";
        str += Models2Str[model];
        str += "\n";

        str += "An : ";
        str += int2str(an);
        str += "\n";

        str += "Pret : ";
        str += int2str(pret);
        str += "$";
        str += "\n";

        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(12);
        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Italic);

        text.setPosition(sf::Vector2f(350,20));
        window.draw(text);
}
void Masina::setImage(string file) {
    _filename = CarFiles[rand()%10];
    _texture.loadFromFile(_filename);
    _sprite.setTexture(_texture);
    _sprite.setPosition(sf::Vector2f(150,200));
}



int Masina::nrMasini = 0;
