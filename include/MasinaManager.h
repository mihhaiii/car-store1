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

        void addMasina(Masina*);
        void deleteMasina(int id);

        Masina* getCurentMasina();
        void MoveForward();
        void MoveBackward();

    protected:

    private:
        vector<Masina*> listaMasini;
        int curentMasinaIndex;



};

#endif // MASINAMANAGER_H
