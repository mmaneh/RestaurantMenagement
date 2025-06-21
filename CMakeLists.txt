cmake_minimum_required(VERSION 3.10)
project(RestaurantManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Main application executable
add_executable(restaurant_app
    main.cpp
    dish.cpp
    customer.cpp
    order.cpp
    appetizer.cpp
    dessert.cpp
    entree.cpp
    menu.cpp
    restaurant.cpp
)

# Google Test
enable_testing()
find_package(GTest REQUIRED)

# Test executable
add_executable(run_tests
    test/test_main.cpp
    dish.cpp
    customer.cpp
    order.cpp
    appetizer.cpp
    dessert.cpp
    entree.cpp
    menu.cpp
    restaurant.cpp
)

target_link_libraries(run_tests
    GTest::gtest
    GTest::gtest_main
    pthread
)

add_test(NAME AllTests COMMAND run_tests)

