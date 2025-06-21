#include "order.h"
#include <iostream>

Order::Order(Customer* customer) totalPrice(0) {}

Order::Order(const Order& other) : customer(other.customer), totalPrice(other.totalPrice), orderedDishes(other.orderedDishes) {}

Order& Order::operator= (const Order& other) {
	if(this = &other) {
		customer = other.customer;
		totalPrice = other.totalPrice;
		orderedHistory = other.orderedHistory;

	}

	return *this;
}

Order::Order(Order&& other) noexcept {
	customer = other.customer;
	totalPrice = other.totalPrice;
	orderHistory = other.orderHistory;
	other.totalPrice = 0;
	other.customer = nullptr;
}

Order& Order::operator= (Order&& other) noexcept {
	customer = other.customer;
        totalPrice = other.totalPrice;
        orderHistory = other.orderHistory;
        other.totalPrice = 0;
        other.customer = nullptr;
}

void Order::addDish(Dish* dish) {
	orderdDishes.emplace_back(dish);
}

void Order::calculateTotal() {
	totalPrice = 0;
	for (int i = 0; i < orderedDishes.size(); ++i) {
		totalPrice += orderedDishes[i]->getPrice;
	}
}

void Order::displayOrder() const {
	for (int i = 0; i < orderedDishes.size(); ++i) {
		orderedDishes[i]->display();
	}
}

