#include "MasinaManager.h"

MasinaManager::MasinaManager()
{
    _currentCarIndex = 0;
}

MasinaManager::~MasinaManager()
{
    //dtor
}

void MasinaManager::AddCar(Masina* m) {
    _carList.push_back(m);
}
void MasinaManager::DeleteCar(int id) {

}

Masina* MasinaManager::GetCurrentCar() {
    return _carList[_currentCarIndex];
}

void MasinaManager::MoveForward() {
    _currentCarIndex++;
    if (_currentCarIndex == _carList.size()) _currentCarIndex = 0;
}
void MasinaManager::MoveBackward() {
    _currentCarIndex--;
    if (_currentCarIndex == -1) _currentCarIndex = _carList.size() - 1;
}

int MasinaManager::GetCarsCount(){
    return _carList.size();
}
