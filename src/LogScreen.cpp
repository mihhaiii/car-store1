#include "LogScreen.h"

LogScreen::LogScreen() :
     OKButton("images/okbutton.png"),
     backButton("images/backbutton.png")
{
    //ctor
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);

    username.setPosition(100,100);
    parola.setPosition(100,130);
    OKButton.setPosition(100,160);
    backButton.setPosition(10,540);

    parola.setPasswordType(true);

    logareLabel.setText("Logare");
    logareLabel.setStyle("italic");
    logareLabel.setCharacterSize(30);
    logareLabel.setPosition(50,50);

    usernameLabel.setText("Username:");
    usernameLabel.setStyle("italic");
    usernameLabel.setCharacterSize(12);
    usernameLabel.setPosition(20,100);

    parolaLabel.setText("Parola:");
    parolaLabel.setStyle("italic");
    parolaLabel.setCharacterSize(12);
    parolaLabel.setPosition(20,130);

    warningLabel.setText("Combinatia user-parola nu este recunoscuta");
    warningLabel.setStyle("italic");
    warningLabel.setColor("red");
    warningLabel.setCharacterSize(30);
    warningLabel.setPosition(150,250);
    warningLabel.setVisible(false);
}

LogScreen::~LogScreen() {
    //dtor
}

void LogScreen::drawAll(sf::RenderWindow& window) {
     window.draw(_sprite);
     username.show(window);
     parola.show(window);
     OKButton.show(window);
     logareLabel.show(window);
     usernameLabel.show(window);
     parolaLabel.show(window);
     warningLabel.show(window);
     backButton.show(window);
}

ButtonAction LogScreen::show(sf::RenderWindow& window, UserManager*  userManager) {
     window.clear();
    drawAll(window);
    window.display();



    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                return Exit;
                break;
            case sf::Event::MouseButtonPressed:
                if (username.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    username.setActive(true), parola.setActive(false);
                else if (parola.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    username.setActive(false), parola.setActive(true);
                        else username.setActive(false), parola.setActive(false);
                if (OKButton.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                        if (Checker::check(username.getText(),parola.getText(), userManager))
                            return ShowMenu;
                        else warningLabel.setVisible(true);
                if (backButton.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    return Back;

                break;
            case sf::Event::TextEntered:
                if (event.text.unicode == 8) {
                    if (parola.isActive())  parola.popLetter();
                            else if (username.isActive()) username.popLetter();
                } else {
                    if (parola.isActive()) parola.addLetter((char)event.text.unicode);
                        else if (username.isActive()) username.addLetter((char)event.text.unicode);
                }
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Tab) {
                    if (username.isActive()) username.setActive(false), parola.setActive(true), parola.popLetter();
                }
            }
        }

        window.clear();
        drawAll(window);
        window.display();




    }
}
