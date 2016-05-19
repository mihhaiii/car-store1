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
