#include "customer.h"
#include <iostream>

Customer::Customer(std::string customerName, std::string contact) : name(customerName), contactInfo(contact){}

Customer::Customer(const Customer& other) : name(other.name), contactInfo(other.contactInfo), orderHistory(other.orderHistory) {}

Customer& Customer::operator= (const Customer& other) {
	if(this != &other) {
		name = other.name;
		contactInfo = other.contactInfo;
		orderHistory = other.orderHistory;
	}
	return *this;
}

Customer::Customer(Customer&& other) noexcept {
	if (this != &other) {
		name = other.name;
		contactInfo = other.contactInfo;
		orderHistory = other.orderHistory;

	}
	
}

Customer& Customer::operator= (Customer&& other) noexcept {
	if(this != &other) {
                name = other.name;
                contactInfo = other.contactInfo;
                orderHistory = other.orderHistory;
        }
        return *this;
}

void Customer::placeOrder(Order order) {
	orderHistory.emplace_back(order);
}

void Customer::viewOrderHistory() const {
	for (int i = 0; i < orderHistory.size(); ++i) {
		orderHistory[i].displayOrder();
	}
}

std::string Customer::getName() const {
	return name;
}
