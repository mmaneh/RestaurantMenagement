#include "dish.h"
#include <iostream>

Dish::Dish(std::string dishName, double dishPrice) : name(dishName), price(dishPrice){}

Dish::Dish(const Dish& other) {
	name = other.name;
       	price = other.price;
}

Dish::Dish(Dish&& other) noexcept {
	name = other.name;
	price = other.price;
	other.price = 0.0;
}

Dish& Dish::operator =(const Dish& other){
	if(this != &other) {
		name = other.name;
		price = other.price;
	}
	return *this;
}

Dish& Dish::operator =(Dish&& other) noexcept{
	if (this != &other) {
		name = other.name;
		price = other.price;
		other.price = 0.0;
	}
	return *this;
}

void Dish::display() const {
	std::cout << name;
	std::cout << price;
}

double Dish::getPrice() const {
	return price;
}

std::string Dish::getName() const {
	return name;
}
