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

bool User::checkName(string s){
    return s.size()>=3;
}
bool User::checkParola(string s){
    return s.size()>=3;
}
bool User::checkUsername(string s, UserManager* um){
   return um->existsUser(s) == false && s.size()>=3;
}

int noUsers = 0;

