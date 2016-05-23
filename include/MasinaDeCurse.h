#ifndef MASINADECURSE_H
#define MASINADECURSE_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class MasinaDeCurse : public Masina
{
    public:
        MasinaDeCurse();
        MasinaDeCurse(Brands,Models,int,int);
        virtual ~MasinaDeCurse();

        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);

    protected:
        int viteza_maxima;
        int acceleratie;

    private:
};

#endif // MASINADECURSE_H
