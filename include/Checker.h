#ifndef CHECKER_H
#define CHECKER_H


#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"
using namespace std;
#include "utils.h"
#include "UserManager.h"
#include "User.h"
class Checker
{
    public:
        Checker();
        virtual ~Checker();

        static bool check(string ,string,UserManager*);
        static bool checkRegisterInfo(string,string,string,string,UserManager*);

    protected:

    private:
};

#endif // CHECKER_H
