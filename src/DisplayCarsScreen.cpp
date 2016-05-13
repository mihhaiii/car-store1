#include "DisplayCarsScreen.h"

DisplayCarsScreen::DisplayCarsScreen() :
    leftButton("images/leftbutton.gif"),
    rightButton("images/rightbutton.gif"),
    afisDetaliiButton("images/afisdetalii.png")
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
  //  leftButton.show(window,400,400);
   // rightButton.show(window,400,400);

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
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (leftButton.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {mm->MoveBackward(); curr--; if (curr==-1) curr=nr-1; }
                if (rightButton.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                     { mm->MoveForward(); curr++; if (curr==nr) curr=0; }
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->getCurentMasina()->showImage(window);
        mm->getCurentMasina()->showInfo(window);

        leftButton.show(window,200,300);
        rightButton.show(window,700,300);
        afisDetaliiButton.show(window,450,500);


        showText(int2str(curr+1), window);

        window.display();
    }
}
