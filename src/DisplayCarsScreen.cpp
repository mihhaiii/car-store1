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
                    mm->MoveBackward();
                if (event.key.code == sf::Keyboard::Right)
                    mm->MoveForward();
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->getCurentMasina()->showImage(window);
        mm->getCurentMasina()->showInfo(window);

        window.display();
    }
}
