#ifndef APPETIZER_H
#define APPETIZER_
#include "dish.h"
#include <string>
class Appetizer : public Dish {
private:
    bool isSpicy;
public:
    Appetizer(std::string dishName, double dishPrice, bool spicy);
    void display() const;
};
#endif
