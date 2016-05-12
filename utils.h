#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "SFML/Graphics.hpp"
using namespace std;
enum Brands {
    FIAT, BMW, FORD, DACIA, AUDI
};
enum Models {
    a32, f5, h1100, j3r3, lk90
};

extern const char* Brands2Str[];
extern const char* Models2Str[];

extern string int2str(int x);
extern void showText(string x, sf::RenderWindow& window);

enum States {
    uninitialized, showingSplash, showingMenu, showingLogInfo, logging, registering, displayingCars, exiting
};

#endif // UTILS_H
