#include "MasinaManager.h"

MasinaManager::MasinaManager()
{
    //ctor
    currentMasinaIndex = 0;
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

Masina* MasinaManager::getCurrentMasina() {
    return listaMasini[currentMasinaIndex];
}

void MasinaManager::MoveForward() {
    currentMasinaIndex++;
    if (currentMasinaIndex == listaMasini.size()) currentMasinaIndex = 0;
}
void MasinaManager::MoveBackward() {
    currentMasinaIndex--;
    if (currentMasinaIndex == -1) currentMasinaIndex = listaMasini.size() - 1;
}

int MasinaManager::getMasinaCount(){
    return listaMasini.size();
}
