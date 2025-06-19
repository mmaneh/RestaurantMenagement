#include "entree.h"
#include <iostream>


Entree::Entree(std::string dishName, double dishPrice, int cal) : Dish(dishName, dishPrice), calories(cal) {}

void Entree::display() const {
	std::cout << name << "Entree-" << calories << "cal" << price << std::endl
}
