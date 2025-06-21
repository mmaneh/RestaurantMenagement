// restaurant.cpp
#include "restaurant.h"
#include <iostream>

Restaurant::Restaurant() {}

Restaurant::Restaurant(const Restaurant& other)
    : menu(other.menu), customers(other.customers), orders(other.orders) {}

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other) {
        menu = other.menu;
        customers = other.customers;
        orders = other.orders;
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& other) noexcept
    : menu(std::move(other.menu)),
      customers(std::move(other.customers)),
      orders(std::move(other.orders)) {}

Restaurant& Restaurant::operator=(Restaurant&& other) noexcept {
    if (this != &other) {
        menu = std::move(other.menu);
        customers = std::move(other.customers);
        orders = std::move(other.orders);
    }
    return *this;
}

Restaurant::~Restaurant() {
    for (Customer* c : customers) {
        delete c;
    }
}

void Restaurant::showMenu() const {
    menu.displayMenu();
}

Customer* Restaurant::getCustomerByName(const std::string& name) {
    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i]->getName() == name) {
            return customers[i];
        }
    }
    Customer* newCustomer = new Customer(name, "0000");
    customers.push_back(newCustomer);
    return newCustomer;
}

void Restaurant::placeNewOrder(const std::string& customerName) {
    Customer* customer = getCustomerByName(customerName);
    Order newOrder(customer);

    Dish* sampleDish = menu.getDishByName("SampleDish");
    if (sampleDish) {
        newOrder.addDish(sampleDish);
    }

    newOrder.calculateTotal();
    orders.push_back(newOrder);
    customer->placeOrder(newOrder);
}

void Restaurant::viewCustomerOrderHistory(const std::string& customerName) const {
    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i]->getName() == customerName) {
            customers[i]->viewOrderHistory();
            return;
        }
    }
    std::cout << "Customer not found.\n";
}

