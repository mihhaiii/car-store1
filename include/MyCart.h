#ifndef __MY_CART_H__
#define __MY_CART_H__

#include <vector>
#include "Masina.h"

class MyCart
{
public:
    MyCart();
    ~MyCart();

    void addMasina(Masina* toAdd);

protected:

private:
    std::vector<Masina*> myCars;

};

#endif // __MY_CART_H__
