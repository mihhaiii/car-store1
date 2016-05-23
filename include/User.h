#ifndef USER_H
#define USER_H

#include <string>
#include "UserManager.h"

using namespace std;

class UserManager;

class User
{
    public:
        User();
        User(string,string,string);
        virtual ~User();

        string GetUsername();
        string GetName();
        string GetPassword();

        bool CheckPassword(string);

    protected:

    private:
        int _id;
        string _name;
        string _username;
        string _password;

        static int noUsers;
};

#endif // USER_H
