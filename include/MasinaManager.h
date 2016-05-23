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

        void moveNext_MasinaSport();
        void moveNext_Limuzina();
        void moveNext_SUV();
        void moveNext_MasinaDeCurse();

        void movePrev_MasinaSport();
        void movePrev_Limuzina();
        void movePrev_SUV();
        void movePrev_MasinaDeCurse();
        int getCurrentCarIndex();
        int GetCarsCount();

    protected:

    private:
        vector<Masina*> carList;

        int currentCarIndex;



};

#endif // MASINAMANAGER_H
