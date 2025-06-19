#include "dessert.h"
#include <iostream>

Dessert::Desert(std::string dishName, double dishPrice, bool nuts) : Dish(dishName, dishPrice), containsNuts(nuts){}

void Dessert::display() const {
	std::cout << "Dessert" << name << (containsNuts ? "contains nuts" : "nut free") << price << std::endl;
}
