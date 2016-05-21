#include "DisplayCarsScreen.h"

DisplayCarsScreen::DisplayCarsScreen() :
    leftButton("images/leftbutton.gif"),
    rightButton("images/rightbutton.gif"),
    afisDetaliiButton("images/afisdetalii.png"),
    backButton("images/backButton.png")
{
    _texture.loadFromFile("images/background1.png");
    _sprite.setTexture(_texture);

    leftButton.setPosition(100,300);
    rightButton.setPosition(700,300);
    afisDetaliiButton.setPosition(300,500);
    backButton.setPosition(10,540);

    leftButton.setAction(ShowPrevCar);
    rightButton.setAction(ShowNextCar);
    afisDetaliiButton.setAction(ShowCarScreen);
    backButton.setAction(Back);
}

DisplayCarsScreen::~DisplayCarsScreen()
{
    //dtor
}

ButtonAction DisplayCarsScreen::show(sf::RenderWindow& window, MasinaManager *mm)
{
    int curr = 0;
    int nr = mm->getMasinaCount();

   vector<Button*> shopButtons;
   shopButtons.push_back(&leftButton);
   shopButtons.push_back(&rightButton);
   shopButtons.push_back(&afisDetaliiButton);
   shopButtons.push_back(&backButton);

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
                for(auto button:shopButtons) {
                    if (button->isButtonPressedAt(event.mouseButton.x,event.mouseButton.y)) {
                        if (button->getAction() == ShowPrevCar) {mm->MoveBackward(); curr--; if (curr==-1) curr=nr-1;}
                         else
                        if (button->getAction() == ShowNextCar) {mm->MoveForward(); curr++; if (curr==nr) curr=0; }
                         else
                            return button->getAction();
                    }
                }
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->getCurrentMasina()->showImage(window);
        mm->getCurrentMasina()->showInfo(window);
        leftButton.show(window);
        rightButton.show(window);
        afisDetaliiButton.show(window);
        backButton.show(window);

        showText(int2str(curr+1), window, 25,25);

        window.display();
    }
}
