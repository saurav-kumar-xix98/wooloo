#include <gtest/gtest.h>
#include <library/Hello.hpp>

TEST(Hello, Hello) {
    ASSERT_EQ(sayHello(), "Hello World!");
}
