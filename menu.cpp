#include "menu.h"
#include <iostream>

Menu::Menu(const Menu& other) {
	for (int i = 0; i < other.dishes.size(); ++i) {
		dishes.emplace_back(other.dishes[i]);
	}
}

Menu& Menu::operator= (const Menu& other) {
	if (this != &other) {
		for (int i = 0; i < other.dishes.size(); ++i) {
                	dishes.emplace_back(other.dishes[i]);
        	}
	}

	return * this;
}

Menu::Menu(Menu&& other) noexcept : dishes(other.dishes) {}

Menu& Menu::operator= (Menu&& other) noexcept {
	if (this != &other) {
        dishes = other.dishes;
    }
    return *this;
}

void Menu::addDish(Dish* dish) {
    dishes.emplace_back(dish);
}

void Menu::displayMenu() const {
    for (int i = 0; i < dishes.size(); ++i) {
        dishes[i]->display();
    }
}

Dish* Menu::getDishByName(const std::string& dishName) const {
    for (int i = 0; i < dishes.size(); ++i) {
        if (dish->getName() == dishName) {
            return dish;
        }
    }
    return nullptr;
}

