#ifndef USER_H
#define USER_H

#include <string>
#include "UserManager.h"
class UserManager;
using namespace std;

class User
{
    public:
        User();
        User(string,string,string);
        virtual ~User();

        static bool checkName(string);
        static bool checkUsername(string, UserManager*);
        static bool checkParola(string);

        string getUsername();
        string getName();

    protected:

    private:
        int id;
        string name;
        string username;
        string parola;

        static int noUsers;
};

#endif // USER_H
