#include "Magazin.h"
#include "Masina.h"
#include <ctime>
#include <random>
Magazin::Magazin()
{
    //ctor
    // incarc 10 masini random in listaMasini
    for (int i=0;i<10;i++)
    {
        _masinaManager.addMasina(new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950));
    }

    _state = uninitialized;

   /* for (auto m:listaMasini)
    {
        cout << Brands2Str[m->getMarca()] << ' ' << Models2Str[m->getModel()] << ' ' << m->getPret() << ' ' << m->getAn() << endl;
    }*/

    freopen("bazadedateuseri.txt","r",stdin);
    string a, b, c;
    while (cin>>a>>b>>c) {
        _userManager.AddUser(new User(a,b,c));
    }
}

Magazin::~Magazin()
{
    //dtorf
    _userManager.writeData("bazadedateuseri.txt");
}

void Magazin::startApp()
{
    for (int i=0;i<10;i++)
    {
        _masinaManager.addMasina(new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%20 + 1995));
    }

    cout << "----------------Start aplicatie!-----------------"<<endl;
    if (_state != uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(800,600),"Magazin de masini");
    _state=showingSplash;

    while (_mainWindow.isOpen())
    {
        appLoop();
    }
}

void Magazin::appLoop()
{
    switch(_state)
    {
    case exiting:
        _mainWindow.close();
        break;
    case showingSplash:
        showSplash();
        break;
    case showingMenu:
        showMenu();
        break;
    case showingLogInfo:
        showLogInfo();
        break;
    case logging:
        showLogScreen();
        break;
    case registering:
        showRegisterScreen();
        break;
    case displayingCars:
        displayCars();
        break;
    case showingCarScreen:
        showCarScreen();
        break;
    case showingMyCart:
        showMyCartScreen();
        break;
    }
}

void Magazin::showMenu()
{
    Menu m;
    ButtonAction res = m.show(_mainWindow);
    switch(res)
    {
    case ShowCars:
        _state = displayingCars;
        break;
    case Exit:
        _state = exiting;
        break;
    case ShowLogInfo:
        _state = showingLogInfo;
        break;
    case ShowMyCart:
        _state = showingMyCart;
        break;
    }

}
void Magazin::showSplash()
{
    SplashScreen ss;
    ss.show(_mainWindow);
    _state=showingLogInfo;
}

void Magazin::showLogInfo()
{
    LogInfoScreen lis;
    ButtonAction res = lis.show(_mainWindow);
    switch(res)
    {
    case ShowLogSreen:
        _state = logging;
        break;
    case ShowRegisterScreen:
        _state = registering;
    }
}
void Magazin::showLogScreen()
{

    LogScreen ls;
    ButtonAction res = ls.show(_mainWindow,
                               &_userManager);
    switch(res)
    {
    case ShowMenu:
        _state = showingMenu;
        break;
    case Back:
        _state = showingLogInfo;
        break;
    case Exit:
        _state = exiting;
    }
}

void Magazin::showRegisterScreen()
{
    RegisterScreen rs;
     ButtonAction res =  rs.show(_mainWindow,
                                 &_userManager);
    switch(res)
    {
    case ShowMenu:
        _state = showingMenu;
        break;
    case Back:
        _state = showingLogInfo;
        break;
    case Exit:
        _state = exiting;
    }
}

void Magazin::displayCars()
{
    DisplayCarsScreen dcs;

    ButtonAction res = dcs.show(_mainWindow,
                                &_masinaManager);
    switch(res)
    {
    case ShowCarScreen:
        _state = showingCarScreen;
        cout<<"show cars";
        break;
    case Back:
        _state = showingMenu;
        break;
    case Exit:
        _state = exiting;
    }
}

void Magazin::showCarScreen()
{
    CarScreen cs;
      ButtonAction res = cs.show(_mainWindow,
                                 _masinaManager.getCurrentMasina());
    switch(res)
    {
    case Back:
        _state = displayingCars;
        break;
    case Exit:
        _state = exiting;
        break;
    }
}

void Magazin::showMyCartScreen()
{
    MyCartScreen mcs;
    ButtonAction res = mcs.show(_mainWindow,
                                &_masinaManager);
    switch(res)
    {
    case Back:
        _state = showingMenu;
        break;
    case Exit:
        _state = exiting;
        break;
    }
}
