#include "MasinaManager.h"

MasinaManager::MasinaManager()
{
    currentCarIndex = 0;
}

MasinaManager::~MasinaManager()
{
    //dtor
}

void MasinaManager::AddCar(Masina* m) {
    carList.push_back(m);
}
void MasinaManager::DeleteCar(int id) {

}

Masina* MasinaManager::GetCurrentCar() {
    return carList[currentCarIndex];
}

void MasinaManager::MoveForward() {
    currentCarIndex++;
    if (currentCarIndex == carList.size()) currentCarIndex = 0;
}
void MasinaManager::MoveBackward() {
    currentCarIndex--;
    if (currentCarIndex == -1) currentCarIndex = carList.size() - 1;
}

int MasinaManager::GetCarsCount(){
    return carList.size();
}

void MasinaManager::moveNext_Limuzina() {
    MoveForward();
        while (carList[currentCarIndex]->toName() != "Limuzina")
            MoveForward();
}
void MasinaManager::moveNext_MasinaDeCurse() {
    MoveForward();
     while (carList[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveForward();
}
void MasinaManager::moveNext_SUV() {
    MoveForward();
     while (carList[currentCarIndex]->toName() != "SUV")
            MoveForward();
}
void MasinaManager::moveNext_MasinaSport() {
    MoveForward();
     while (carList[currentCarIndex]->toName() != "MasinaSport")
            MoveForward();
}



void MasinaManager::movePrev_Limuzina() {
    MoveBackward();
     while (carList[currentCarIndex]->toName() != "Limuzina")
            MoveBackward();
}
void MasinaManager::movePrev_MasinaDeCurse() {
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "MasinaDeCurse")
            MoveBackward();
}
void MasinaManager::movePrev_SUV() {
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "SUV")
            MoveBackward();
}
void MasinaManager::movePrev_MasinaSport() {
    MoveBackward();
    while (carList[currentCarIndex]->toName() != "MasinaSport")
            MoveBackward();
}

int MasinaManager::getCurrentCarIndex() {
    return currentCarIndex;
}



