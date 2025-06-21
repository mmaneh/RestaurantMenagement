#include <gtest/gtest.h>
#include "../dish.h"

TEST(DishTest, BasicProperties) {
    Dish d("Pizza", 12.5);
    EXPECT_EQ(d.getName(), "Pizza");
    EXPECT_DOUBLE_EQ(d.getPrice(), 12.5);
}
