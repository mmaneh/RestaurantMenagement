#include "appetizer.h"
#include <iostream>

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy) : Dish(dishName, dishPrice), isSice(spicy){}

void Appetizer::display() cost{
	std::cout << name << "appetizer" << (isSpicy ? "Spicy" : "Not spicy") <<price << std::endl;
}
