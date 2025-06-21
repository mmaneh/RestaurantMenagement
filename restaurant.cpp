#include "retaurant.h"
#include <iostream>

Restaurant::Restaurant() {}

Restaurant::Restaurant(const Restaurant& other) : menu(other.menu), customers(other.customers), oders(other.orders) {}


