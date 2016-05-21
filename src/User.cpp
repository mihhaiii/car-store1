#include "User.h"

User::User()
{
    //ctor
}

User::User(string a, string b, string c) :
    name(a), username(b), parola(c)
    {
        //ctor
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
string User::getParola() {
    return parola;
}

bool User::checkParola(string parola) {
    return this->parola == parola;
}
int noUsers = 0;

