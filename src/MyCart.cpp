#include <iostream>
#include "MyCart.h"
using namespace std;

MyCart::MyCart()
{

}

MyCart::~MyCart()
{
    for (auto it: myCars)
        delete it;
}

void MyCart::addMasina(Masina* toAdd)
{
    myCars.push_back(toAdd);
    cout<<"Masina cumparata";
}
