#include "User.h"

User::User()
{
    //ctor
}

User::User(string a, string b, string c) :
    name(a), username(b), parola(c)
    {
    }
User::~User()
{
    //dtor
}

string User::getName(){
    return name;
}
string User::getUsername(){
    return username;
}


bool User::checkParola(string parola) {
    return this->parola == parola;
}
int noUsers = 0;

