#ifndef USER_H
#define USER_H

#include <string>
#include "UserManager.h"
#include "MyCart.h"

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

        void LogIn();
        void LogOut();
        bool IsLoggedIn();

        bool CheckPassword(string);

        void AddCarToCart(Masina* masina);

    protected:

    private:
        int _id;
        string _name;
        string _username;
        string _password;
        bool _loggedIn;

        static int noUsers;
        MyCart myCart;
};

#endif // USER_H
