#include "Checker.h"

Checker::Checker()
{
    //ctor
}

Checker::~Checker()
{
    //dtor
}

bool Checker::check(string username, string parola, UserManager* userManager)
{
    if (username.size() < 3) return false;
    if (parola.size() < 5) return false;

    if (userManager->existsUser(username))  {
        if (userManager->checkLogInfo(username, parola))
            return true;
    }
    return false;
}
bool Checker::checkRegisterInfo(string nume, string username, string parola, string email, UserManager* userManager)
{
    if (nume.size()<3) return false;
    if (username.size()<3) return false;
    if (parola.size()<5) return false;
    if (email.size()<5) return false;

    bool aron=false, punct = false;
    for(auto ch : email) {
        if (ch =='@') aron=true;
        if (ch =='.' && aron) punct=true;
    }
    if (!aron || !punct) return false;
    if (userManager->existsUser(username))
        return false;
    return true;
}
