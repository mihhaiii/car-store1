#include "MasinaManager.h"

MasinaManager::MasinaManager()
{
    //ctor
    curentMasinaIndex = 0;
}

MasinaManager::~MasinaManager()
{
    //dtor
}

void MasinaManager::addMasina(Masina* m) {
    listaMasini.push_back(m);
}
void MasinaManager::deleteMasina(int id) {

}

Masina* MasinaManager::getCurentMasina() {
    return listaMasini[curentMasinaIndex];
}

void MasinaManager::MoveForward() {
    curentMasinaIndex++;
    if (curentMasinaIndex == listaMasini.size()) curentMasinaIndex = 0;
}
void MasinaManager::MoveBackward() {
    curentMasinaIndex--;
    if (curentMasinaIndex == -1) curentMasinaIndex = listaMasini.size() - 1;
}

int MasinaManager::getMasinaCount(){
    return listaMasini.size();
}
