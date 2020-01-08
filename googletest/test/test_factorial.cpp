# include "gtest/gtest.h"
# include "factorial.h"

TEST(IntegerFunctionTest, NegativeInputs) {
        EXPECT_EQ(1, factorial(-6)) << "factorial(6) == 1";
        EXPECT_EQ(1, factorial(-1));
        EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, InputZero) {
         EXPECT_EQ(1, factorial(0));
}

TEST(IntegerFunctionTest, PositiveInput) {
         EXPECT_EQ(1, factorial(1));
         EXPECT_EQ(2, factorial(2));
         EXPECT_EQ(6, factorial(3));
         EXPECT_EQ(40320, factorial(8));
}