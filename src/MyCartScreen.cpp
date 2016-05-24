#include "MyCartScreen.h"

MyCartScreen::MyCartScreen() :
    backButtonObj("images/backbutton.png"),
    upButtonObj("images/upButton.png"),
    downButtonObj("images/downButton.png")
{
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);

    backButtonObj.SetPosition(10,540);
    upButtonObj.SetPosition(300,30);
    downButtonObj.SetPosition(300,540);

    backButtonObj.SetAction(BackAction);
    upButtonObj.SetAction(ShowPrevCarAction);
    downButtonObj.SetAction(ShowNextCarAction);
}

MyCartScreen::~MyCartScreen()
{
    //dtor
}

ButtonAction MyCartScreen::Show(sf::RenderWindow& window, MasinaManager* mm)
{

    int currentCarIndex = 0;
    int cartCarsNumber = mm->GetCarsCount();

    vector<Button*> cartButtons;
    cartButtons.push_back(&backButtonObj);
    cartButtons.push_back(&upButtonObj);
    cartButtons.push_back(&downButtonObj);

    for(int i=0;i<5;i++)
       boxes.push_back(new CheckBox());
   for(int i=0;i<5;i++)
       boxes[i]->setPosition(sf::Vector2f(30,i*100+50));

   boxes[0]->setText("Toate");
   boxes[1]->setText("Limuzine");
   boxes[2]->setText("Masini\nsport");
   boxes[3]->setText("Masini\nde\ncurse");
   boxes[4]->setText("SUV");
   boxes[0]->setCheck(true);

    while(1)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
                return ExitAction;
            }
            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)  ||
                     (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta < 0))
            {
                if (boxes[0]->getCheck()) mm->MoveBackward();
                if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                if (boxes[4]->getCheck()) mm->movePrev_SUV();
            }
            else if ((event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up) ||
                      (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta > 0))
            {
                if (boxes[0]->getCheck()) mm->MoveForward();
                if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                if (boxes[4]->getCheck()) mm->moveNext_SUV();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                for(auto button : cartButtons)
                {
                    if (button->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        if (button->GetAction() == ShowPrevCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveBackward();
                            if (boxes[1]->getCheck()) mm->movePrev_Limuzina();
                            if (boxes[2]->getCheck()) mm->movePrev_MasinaSport();
                            if (boxes[3]->getCheck()) mm->movePrev_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->movePrev_SUV();
                        }
                        else if (button->GetAction() == ShowNextCarAction)
                        {
                            if (boxes[0]->getCheck()) mm->MoveForward();
                            if (boxes[1]->getCheck()) mm->moveNext_Limuzina();
                            if (boxes[2]->getCheck()) mm->moveNext_MasinaSport();
                            if (boxes[3]->getCheck()) mm->moveNext_MasinaDeCurse();
                            if (boxes[4]->getCheck()) mm->moveNext_SUV();
                        }
                        else return button->GetAction();
                    }
                }
                for (int i=0;i<5;i++)
                {
                    if (boxes[i]->IsButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    {
                        for(int j=0;j<5;j++)
                            boxes[j]->setCheck(false);
                        boxes[i]->setCheck(true);
                        if (i==1) mm->moveNext_Limuzina();
                        if (i==2) mm->moveNext_MasinaSport();
                        if (i==3) mm->moveNext_MasinaDeCurse();
                        if (i==4) mm->moveNext_SUV();
                    }
                }
            }
        }
    window.clear();
    window.draw(_sprite);
    backButtonObj.Show(window);
    upButtonObj.Show(window);
    downButtonObj.Show(window);
    for(int i=0;i<5;i++)
        boxes[i]->show(window);
    window.display();
}

}
