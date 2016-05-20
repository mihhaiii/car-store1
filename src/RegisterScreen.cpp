#include "RegisterScreen.h"

RegisterScreen::RegisterScreen()
: registerButton("images/registerbutton1.png")
{
    //ctor
    _texture.loadFromFile("images/background.png");
    _sprite.setTexture(_texture);


    nume.setPosition(300,300);
    username.setPosition(300,330);
    parola.setPosition(300,360);
    email.setPosition(300,390);
    registerButton.setPosition(300,420);
    parola.setPasswordType(true);

    registerLabel.setText("Înregistrare");
    registerLabel.setStyle("italic");
    registerLabel.setCharacterSize(30);
    registerLabel.setPosition(50,50);

    numeLabel.setText("Nume:");
    usernameLabel.setText("Username:");
    parolaLabel.setText("Parola:");
    emailLabel.setText("Email:");

    numeLabel.setPosition(150,300);
    usernameLabel.setPosition(150,330);
    parolaLabel.setPosition(150,360);
    emailLabel.setPosition(150,390);

    warningLabel.setText("Date incomplete sau incorecte");
    warningLabel.setCharacterSize(30);
    warningLabel.setColor("red");
    warningLabel.setPosition(300, 500);
    warningLabel.setVisible(false);

    congratsLabel.setPosition(300,300);
    congratsLabel.setText("Înregistrare reusita!");
    congratsLabel.setCharacterSize(24);
    congratsLabel.setColor("green");

    pressKeyLabel.setPosition(300,400);
    pressKeyLabel.setStyle("italic");
    pressKeyLabel.setCharacterSize(12);
    pressKeyLabel.setText("Apasati orice tasta pentru continuare...");

}

RegisterScreen::~RegisterScreen()
{
    //dtor
}
void RegisterScreen::drawAll(sf::RenderWindow& window) {
    window.draw(_sprite);
    registerLabel.show(window);
    parolaLabel.show(window);
    usernameLabel.show(window);
    emailLabel.show(window);
    numeLabel.show(window);
    warningLabel.show(window);

    nume.show(window);
    username.show(window);
    parola.show(window);
    email.show(window);

    registerButton.show(window);
}


ButtonAction RegisterScreen::show(sf::RenderWindow& window, UserManager* userManager) {
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
                    window.close();
                    return Exit;
                    break;
                case sf::Event::MouseButtonPressed:
                   {
                        int x = event.mouseButton.x, y = event.mouseButton.y;
                        if (nume.isButtonPressedAt(x,y)) setActive(&nume); else
                        if (username.isButtonPressedAt(x,y)) setActive(&username); else
                        if (parola.isButtonPressedAt(x,y)) setActive(&parola); else
                        if (email.isButtonPressedAt(x,y)) setActive(&email); else
                            setActive(NULL);

                        if (registerButton.isButtonPressedAt(x,y)) {
                            // verifica corectitudinea datelor
                            if (Checker::checkRegisterInfo(nume.getText(),username.getText(),parola.getText(),email.getText(),userManager))
                                return showSuccess(window), userManager->AddUser(new User(nume.getText(),username.getText(),parola.getText())), ShowMenu;
                                else warningLabel.setVisible(true);
                        }
                        break;
                   }
                case sf::Event::TextEntered:
                    if (event.text.unicode == 8) {
                        if (nume.isActive()) nume.popLetter();
                        if (username.isActive()) username.popLetter();
                        if (parola.isActive()) parola.popLetter();
                        if (email.isActive()) email.popLetter();
                    } else {
                        char ch = (char)event.text.unicode;
                       // if ((ch>='a'&&ch<='z') || (ch>='A' && ch<='Z'))
                        {
                            if (nume.isActive()) nume.addLetter(ch);
                            if (username.isActive()) username.addLetter(ch);
                            if (parola.isActive()) parola.addLetter(ch);
                            if (email.isActive()) email.addLetter(ch);
                        }
                    }
                    break;
            }
        }


        window.clear();
        drawAll(window);
        window.display();
    }

}


void RegisterScreen::showSuccess(sf::RenderWindow& window) {
    window.clear();
    window.draw(_sprite);
    registerLabel.show(window);
    congratsLabel.show(window);
    pressKeyLabel.show(window);

    window.display();

    sf::Event event;
    while (1)
    {
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
            case sf::Event::MouseButtonPressed:
                return;
            }
        }
    }
}

void RegisterScreen::setActive(FormField* l) {
    nume.setActive(false);
    username.setActive(false);
    parola.setActive(false);
    email.setActive(false);
    if (l!=NULL) l->setActive(true);
}
