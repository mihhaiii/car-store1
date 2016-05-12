#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <bits/stdc++.h>
using namespace std;
class User;
class UserManager
{
    public:
        UserManager();
        virtual ~UserManager();

        void AddUser(User*);
        void DeleteUser(string);
        bool existsUser(string);

    protected:

    private:
        vector<User*> listaUseri;
};

#endif // USERMANAGER_H
