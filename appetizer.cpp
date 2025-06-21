#include "appetizer.h"
#include <iostream>

Appetizer::Appetizer(std::string dishName, double dishPrice, bool spicy) : Dish(dishName, dishPrice), isSpicy(spicy){}

void Appetizer::display() const{
	std::cout << name << "appetizer" << (isSpicy ? "Spicy" : "Not spicy") <<price << std::endl;
}
