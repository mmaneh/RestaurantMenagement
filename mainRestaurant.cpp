#include <gtest/gtest.h>
#include "../dish.h"
#include "../customer.h"
#include "../order.h"
#include "../appetizer.h"
#include "../dessert.h"
#include "../entree.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(DishTest, PriceAndName) {
    Dish d("xorovats", 15.000);
    EXPECT_EQ(d.getPrice(), 15.000);
    EXPECT_EQ(d.getName(), "xorovats");
}

TEST(CustomerTest, OrderHistory) {
    Customer c("Meri", "12345");
    Order o(&c);
    Dish d("caeser salad", 2000);
    o.addDish(&d);
    o.calculateTotal();
    c.placeOrder(o);

    ASSERT_NO_THROW(c.viewOrderHistory());
}

TEST(CustomerTest, GetName) {
    Customer c("Mane", "12345");
    EXPECT_EQ(c.getName(), "Mane");
}

TEST(AppetizerTest, SpicyTest) {
    Appetizer a("Fries", 700, true);
    EXPECT_EQ(a.getName(), "Fries");
    EXPECT_EQ(a.getPrice(), 700);
}

TEST(DessertTest, Nuttest) {
    Dessert d("Cake", 1800, true);
    EXPECT_EQ(d.getName(), "Cake");
    EXPECT_EQ(d.getPrice(), 1800);
  
}

TEST(EntreeTest, Calories) {
    Entree e("Steak", 2000, 800);
    EXPECT_EQ(e.getName(), "Steak");
    EXPECT_EQ(e.getPrice(), 2000);

}

