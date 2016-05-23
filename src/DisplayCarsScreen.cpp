#include "DisplayCarsScreen.h"

DisplayCarsScreen::DisplayCarsScreen() :
    leftButtonObj("images/leftbutton.gif"),
    rightButtonObj("images/rightbutton.gif"),
    detailsButtonObj("images/afisdetalii.png"),
    backButtonObj("images/backButton.png")
{
    _texture.loadFromFile("images/background1.png");
    _sprite.setTexture(_texture);

    leftButtonObj.SetPosition(100,300);
    rightButtonObj.SetPosition(700,300);
    detailsButtonObj.SetPosition(300,500);
    backButtonObj.SetPosition(10,540);

    leftButtonObj.SetAction(ShowPrevCarAction);
    rightButtonObj.SetAction(ShowNextCarAction);
    detailsButtonObj.SetAction(ShowCarScreenAction);
    backButtonObj.SetAction(BackAction);
}

DisplayCarsScreen::~DisplayCarsScreen()
{
    //dtor
}

ButtonAction DisplayCarsScreen::Show(sf::RenderWindow& window, MasinaManager* mm)
{
    int currentCarIndex = 0;
    int carsNumber = mm->GetCarsCount();



   vector<Button*> buttons;
   buttons.push_back(&leftButtonObj);
   buttons.push_back(&rightButtonObj);
   buttons.push_back(&detailsButtonObj);
   buttons.push_back(&backButtonObj);

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
                    {
                        mm->MoveBackward();
                        currentCarIndex--;
                        if (currentCarIndex == -1)
                            currentCarIndex = carsNumber - 1;
                    }
                if (event.key.code == sf::Keyboard::Right)
                   {
                       mm->MoveForward();
                       currentCarIndex++;
                       if (currentCarIndex == carsNumber)
                            currentCarIndex = 0;
                   }

            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto button : buttons)
                {
                    if (button->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        if (button->GetAction() == ShowPrevCarAction)
                        {
                            mm->MoveBackward();
                            currentCarIndex--;
                            if (currentCarIndex == -1)
                                currentCarIndex = carsNumber - 1;
                        }
                        else if (button->GetAction() == ShowNextCarAction)
                        {
                            mm->MoveForward();
                            currentCarIndex++;
                            if (currentCarIndex == carsNumber)
                                currentCarIndex = 0;
                        }
                        else
                            return button->GetAction();
                    }
                }
            }
        }
        window.clear();
        window.draw(_sprite);
        mm->GetCurrentCar()->showImage(window);
        mm->GetCurrentCar()->showInfo(window);
        leftButtonObj.Show(window);
        rightButtonObj.Show(window);
        detailsButtonObj.Show(window);
        backButtonObj.Show(window);

        showText(int2str(currentCarIndex+1), window, 25,25);

        window.display();
    }
}
