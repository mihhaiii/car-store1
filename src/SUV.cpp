#include "SUV.h"

SUV::SUV()
{
    //ctor
}
SUV::SUV(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{

}

SUV::~SUV()
{
    //dtor
}

void SUV::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void SUV::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}



