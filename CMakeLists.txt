cmake_minimum_required(VERSION 3.10)
project(RestaurantManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    appetizer.cpp
    dessert.cpp
    dish.cpp
    entree.cpp
    menu.cpp
    customer.cpp
    order.cpp
    restaurant.cpp
    main.cpp
)

add_executable(restaurant_app ${SOURCES})

enable_testing()

add_executable(restaurant_tests
    test/test_dish.cpp
    dish.cpp
)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(restaurant_tests ${GTEST_LIBRARIES} pthread)

add_test(NAME DishTest COMMAND restaurant_tests)
