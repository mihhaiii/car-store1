#include "Limuzina.h"

Limuzina::Limuzina()
{
    //ctor
}
Limuzina::Limuzina(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{

}

Limuzina::~Limuzina()
{
    //dtor
}

void Limuzina::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void Limuzina::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}
string Limuzina::toName() {
    return "Limuzina";
}



