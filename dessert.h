#ifndef DESSERT_H
#define DESSERT_H
#include "dish.h"
#include <string>

class Dessert : public Dish {
private:
    bool containsNuts;
public:
    Dessert(std::string dishName, double dishPrice, bool nuts);
    void display() const;
};
#endif
