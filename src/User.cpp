#include "User.h"

User::User()
{
    //ctor
}

User::User(string a, string b, string c) :
    _name(a), _username(b), _password(c)
{

}
User::~User()
{
    //dtor
}

string User::GetName()
{
    return _name;
}
string User::GetUsername()
{
    return _username;
}
string User::GetPassword()
{
    return _password;
}
MyCart* User::GetMyCart()
{
    return &myCart;
}
bool User::CheckPassword(string password)
{
    return this->_password == password;
}
int noUsers = 0; //?? TODO

void User::AddCarToCart(Masina* masina)
{
    myCart.AddMasina(masina);
}

void User::LogIn()
{
    _loggedIn = true;
}

void User::LogOut()
{
    _loggedIn = false;
}

bool User::IsLoggedIn()
{
    return _loggedIn;
}
