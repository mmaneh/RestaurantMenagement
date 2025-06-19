#ifndef ENTREE_H
#define ENTREE_H
#include "dish.h"

class Entree : public Dish {
private:
    int calories;
public:
    Entree(std::string dishName, double dishPrice, int cal);
    void display() const;
};
#endif
