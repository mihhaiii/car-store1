#ifndef MASINAMANAGER_H
#define MASINAMANAGER_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "Masina.h"
class MasinaManager
{
    public:
        MasinaManager();
        virtual ~MasinaManager();

        void AddCar(Masina*);
        void DeleteCar(int id);

        Masina* GetCurrentCar();
        void MoveForward();
        void MoveBackward();

        int GetCarsCount();

    protected:

    private:
        vector<Masina*> _carList;
        int _currentCarIndex;



};

#endif // MASINAMANAGER_H
