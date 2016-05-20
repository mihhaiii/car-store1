#ifndef MASINA_H
#define MASINA_H

#include <iostream>
#include <string>
#include <map>
#include "SFML/Graphics.hpp"
#include "utils.h"

using namespace std;

class Masina
{
    public:
        Masina();
        Masina(Brands,Models,int,int);
        virtual ~Masina();

        static Models getRandModel();
        static Brands getRandBrand();

        Brands getMarca();
        Models getModel();
        int getPret();
        int getAn();
        string getFilename();
        void setFilename(string);

        void showImage(sf::RenderWindow&);
        void showInfo(sf::RenderWindow&);

    protected:

    private:
        Brands marca;
        Models model;
        int pret;
        int an;
        int id;

        static int nrMasini;

        sf::Sprite _sprite;
        sf::Texture _texture;
        string _filename;
};

#endif // MASINA_H
