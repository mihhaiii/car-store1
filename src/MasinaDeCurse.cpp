#include "MasinaDeCurse.h"

MasinaDeCurse::MasinaDeCurse()
{
    //ctor
}


MasinaDeCurse::~MasinaDeCurse()
{
    //dtor
}
MasinaDeCurse::MasinaDeCurse(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{

}
void MasinaDeCurse::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void MasinaDeCurse::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}

string MasinaDeCurse::toName() {
    return "MasinaDeCurse";
}

