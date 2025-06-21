#include "order.h"
#include <iostream>

Order::Order(Customer* customer) : customer(customer), totalPrice(0) {}

Order::Order(const Order& other) : customer(other.customer), totalPrice(other.totalPrice), orderedDishes(other.orderedDishes) {}

Order& Order::operator= (const Order& other) {
	if(this != &other) {
		customer = other.customer;
		totalPrice = other.totalPrice;
		orderedDishes = other.orderedDishes;

	}

	return *this;
}

Order::Order(Order&& other) noexcept {
	customer = other.customer;
	totalPrice = other.totalPrice;
	orderedDishes= other.orderedDishes;
	other.totalPrice = 0;
	other.customer = nullptr;
}

Order& Order::operator= (Order&& other) noexcept {
      if(this != &other){
	customer = other.customer;
        totalPrice = other.totalPrice;
        orderedDishes = other.orderedDishes;
        other.totalPrice = 0;
        other.customer = nullptr;
      }
      return *this;
}

void Order::addDish(Dish* dish) {
	orderedDishes.emplace_back(dish);
}

void Order::calculateTotal() {
	totalPrice = 0;
	for (int i = 0; i < orderedDishes.size(); ++i) {
		totalPrice += orderedDishes[i]->getPrice();
	}
}

void Order::displayOrder() const {
	for (int i = 0; i < orderedDishes.size(); ++i) {
		orderedDishes[i]->display();
	}
}

