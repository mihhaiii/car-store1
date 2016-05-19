#include "LogScreen.h"

LogScreen::LogScreen() :
    usernameField("images/field.png"), parolaField("images/field.png"), OKButton("images/okbutton.png")
{
    //ctor
   // _texture.loadFromFile("images/logscreen.png");
   // _sprite.setTexture(_texture);

    usernameField.setPosition(100,100);
    parolaField.setPosition(100,200);
    OKButton.setPosition(200,300);
}

LogScreen::~LogScreen()
{
    //dtor
}

ButtonAction LogScreen::show(sf::RenderWindow& window) {
     window.clear();
    window.draw(_sprite);
    window.display();

    /*sf::Clock c;
    sf::Time t = sf::seconds(2);
    while (c.getElapsedTime() < t) {};*/
    writingParola = writingUsername = false;

    usernameSoFar  = parolaSoFar = "";

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
                if (usernameField.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    writingUsername = true, writingParola = false;
                else if (parolaField.isButtonPressedAt(event.mouseButton.x,event.mouseButton.y))
                    writingParola = true, writingUsername = false;
                        else writingParola = writingUsername = false;
                break;
            case sf::Event::TextEntered:
                if (event.text.unicode == 8) {
                    if (writingParola) parolaSoFar = parolaSoFar.substr(0,parolaSoFar.size()-1);
                            else if (writingUsername) usernameSoFar = usernameSoFar.substr(0,usernameSoFar.size()-1);
                } else {
                    if (writingParola) parolaSoFar += (char)event.text.unicode;
                        else if (writingUsername) usernameSoFar += (char)event.text.unicode;
                }
            }
        }

        window.clear(sf::Color::Blue);

        showText("Logare",window,50,50);

        usernameField.show(window);
        parolaField.show(window);
        OKButton.show(window);
        showText(usernameSoFar,window,100,100);
        showText(parolaSoFar,window,100,200);


        window.display();

    }
}
