#ifndef DISH_H
#define DISH_H

class Dish {
protected:
    std::string name;
    double price;
public:
    Dish(std::string dishName, double dishPrice);
   Dish(const Dish& other);
    Dish& operator=(const Dish& other);
    Dish(Dish&& other) noexcept;
    Dish& operator=(Dish&& other) noexcept;

    void display() const;
    double getPrice() const;
    std::string getName() const;
};
#endif

