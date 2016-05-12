#include "DisplayCarsScreen.h"

DisplayCarsScreen::DisplayCarsScreen()
{
    //ctor
}

DisplayCarsScreen::~DisplayCarsScreen()
{
    //dtor
}

void DisplayCarsScreen::show(sf::RenderWindow& window, MasinaManager* mm)
{
    int curr=0;
    int nr = mm->getMasinaCount();

    while (1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                    {mm->MoveBackward(); curr--; if (curr==-1) curr=nr-1; }
                if (event.key.code == sf::Keyboard::Right)
                   { mm->MoveForward(); curr++; if (curr==nr) curr=0; }
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->getCurentMasina()->showImage(window);
        mm->getCurentMasina()->showInfo(window);

        showText(int2str(curr+1), window);

        window.display();
    }
}
