#ifndef LIMUZINA_H
#define LIMUZINA_H

#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
#include "utils.h"
#include "Masina.h"

using namespace std;

class Limuzina : public Masina
{
    public:
        Limuzina();
        virtual ~Limuzina();

        virtual void showImage(sf::RenderWindow&);
        virtual void showInfo(sf::RenderWindow&);

    protected:

    private:
        int maximPasageri;
        int lungime;
};

#endif // LIMUZINA_H
