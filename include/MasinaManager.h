#ifndef MASINAMANAGER_H
#define MASINAMANAGER_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "Masina.h"

using namespace std;

class MasinaManager
{
    public:
        MasinaManager();
        virtual ~MasinaManager();

        void addMasina(Masina*);
        void deleteMasina(int id);

        Masina* getCurrentMasina();
        void MoveForward();
        void MoveBackward();

        int getMasinaCount();

    protected:

    private:
        vector<Masina*> listaMasini;
        int currentMasinaIndex;

};

#endif // MASINAMANAGER_H
