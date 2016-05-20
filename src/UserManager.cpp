#include "UserManager.h"

UserManager::UserManager()
{
    //ctor
}

UserManager::~UserManager()
{
    //dtor
}

void UserManager::AddUser(User* u) {
    listaUseri.push_back(u);
}
void UserManager::DeleteUser(string username){

}

bool UserManager::existsUser(string username) {
    for (auto user:listaUseri)
        if (user->getUsername() == username) return true;
    return false;
}

bool UserManager::checkLogInfo(string username, string parola) {
    for(auto user:listaUseri) {
        if (user->getUsername() == username)
            return user->checkParola(parola);
    }
}

void UserManager::writeData(const char* filename) {
    freopen(filename,"w",stdout);
    for(auto user:listaUseri) {
        cout << user->getName() << "\n" << user->getUsername() << "\n" << user->getParola() << "\n\n";
    }
}
