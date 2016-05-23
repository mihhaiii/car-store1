#include "Magazin.h"
#include "Masina.h"

#include <ctime>
#include <random>

Magazin::Magazin()
{
    // incarc 10 masini random in _carList
    for (int i=0;i<10;i++)
    {
        _carManager.AddCar(new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%60 + 1950));
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
    _userManager.WriteData("bazadedateuseri.txt");
}

void  Magazin::startApp()
{
    for (int i=0;i<10;i++)
    {
        _carManager.AddCar(new Masina(Masina::getRandBrand(), Masina::getRandModel(), rand() % 1000 + 10000, rand()%20 + 1995));
    }

    cout << "----------------Bine ati Venit!!!-----------------"<<endl;
    if (_state != uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(800,600),"Magazin de masini");
    _state=showingSplashState;

    while (_mainWindow.isOpen())
    {
        appLoop();
    }
}

void Magazin::appLoop()
{
    switch(_state)
    {
    case exitingState:
        _mainWindow.close();
        break;
    case showingSplashState:
        ShowSplash();
        break;
    case showingMenuState:
        ShowMenu();
        break;
    case showingLogInfoState:
        ShowLogInfo();
        break;
    case loggingState:
        ShowLogScreen();
        break;
    case registeringState:
        ShowRegisterScreen();
        break;
    case displayingCarsState:
        DisplayCars();
        break;
    case showingCarScreenState:
        ShowCarScreen();
        break;
    case showingMyCartState:
        ShowMyCartScreen();
        break;
    }
}

void Magazin::ShowMenu()
{
    Menu m;
    ButtonAction res = m.Show(_mainWindow);
    switch(res)
    {
        case ShowCarsAction:
            _state = displayingCarsState;
            break;
        case ExitAction:
            _state = exitingState;
            break;
        case ShowLogInfoAction:
            _state = showingLogInfoState;
            break;
        case ShowMyCartAction:
            _state = showingMyCartState;
            break;
    }

}
void Magazin::ShowSplash()
{
    SplashScreen ss;
    ss.show(_mainWindow);
    _state=showingLogInfoState;
}

void Magazin::ShowLogInfo()
{
    LogInfoScreen lis;
    ButtonAction res = lis.Show(_mainWindow);
    switch(res)
    {
        case ShowLogSreenAction:
            _state = loggingState;
            break;
        case ShowRegisterScreenAction:
            _state = registeringState;
    }
}
void Magazin::ShowLogScreen()
{

    LogScreen ls;
    ButtonAction res = ls.Show(_mainWindow, &_userManager);

    switch(res)
    {
        case ShowMenuAction:
            _state = showingMenuState;
            break;
        case BackAction:
            _state = showingLogInfoState;
            break;
        case ExitAction:
            _state = exitingState;
    }
}

void Magazin::ShowRegisterScreen()
{
    RegisterScreen rs;
    ButtonAction res =  rs.Show(_mainWindow, &_userManager);
    switch(res)
    {
    case ShowMenuAction:
        _state = showingMenuState;
        break;
    case BackAction:
        _state = showingLogInfoState;
        break;
    case ExitAction:
        _state = exitingState;
    }
}

void Magazin::DisplayCars()
{
    DisplayCarsScreen dcs;

    ButtonAction res = dcs.Show(_mainWindow,&_carManager);
    switch(res)
    {
    case ShowCarScreenAction:
        _state = showingCarScreenState;
        break;
    case BackAction:
        _state = showingMenuState;
        break;
    case ExitAction:
        _state = exitingState;
    }
}

void Magazin::ShowCarScreen()
{
    CarScreen cs;
    ButtonAction res = cs.Show(_mainWindow, _carManager.GetCurrentCar());
    switch(res)
    {
    case BackAction:
        _state = displayingCarsState;
        break;
    case ExitAction:
        _state = exitingState;
        break;
    }
}

void Magazin::ShowMyCartScreen()
 {
    MyCartScreen mcs;
    ButtonAction res = mcs.Show(_mainWindow, &_carManager);
    switch(res)
    {
        case BackAction:
            _state = showingMenuState;
            break;
        case ExitAction:
            _state = exitingState;
            break;
    }
 }
