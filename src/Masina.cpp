#include "Masina.h"
#include <ctime>
#include <random>
Masina::Masina()
{
    //ctor
     nrMasini++;
    id  = nrMasini;

    if (id%2)
    _texture.loadFromFile("images/car11.png");
    else _texture.loadFromFile("images/car22.png");
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

    if (id%2)
    _texture.loadFromFile("images/car11.png");
    else _texture.loadFromFile("images/car22.png");
    _sprite.setTexture(_texture);
   }


Brands Masina::getRandBrand()
{
    return (Brands)(rand() % 5);
}

Models Masina::getRandModel()
{
    return Models(rand() % 5);
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
        _sprite.setPosition(sf::Vector2f(300,250));
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
        text.setCharacterSize(24);
        text.setColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold);

        text.setPosition(100,100);
        window.draw(text);


}


int Masina::nrMasini = 0;
