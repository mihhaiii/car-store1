#include "MasinaSport.h"

MasinaSport::MasinaSport()
{
    //ctor
}

MasinaSport::MasinaSport(Brands b, Models m, int x ,int y)
: Masina(b,m,x,y)
{

}
MasinaSport::~MasinaSport()
{
    //dtor
}

void MasinaSport::showImage(sf::RenderWindow& window) {
    Masina::showImage(window);
}
void MasinaSport::showInfo(sf::RenderWindow& window) {
    Masina::showInfo(window);
}
string MasinaSport::toName() {
    return "MasinaSport";
}


