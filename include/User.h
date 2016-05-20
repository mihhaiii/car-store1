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



        string getUsername();
        string getName();
        string getParola();

        bool checkParola(string);

    protected:

    private:
        int id;
        string name;
        string username;
        string parola;

        static int noUsers;
};

#endif // USER_H
