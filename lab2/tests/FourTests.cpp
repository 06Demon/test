#include "gtest/gtest.h"
#include "Four.h"

TEST(FourTests, Constructors) {
    Four f1;
    EXPECT_EQ(f1.toString(), "0");

    Four f2(3, 2);
    EXPECT_EQ(f2.toString(), "222");

    Four f3{1, 2, 3};
    EXPECT_EQ(f3.toString(), "123");

    Four f4("123");
    EXPECT_EQ(f4.toString(), "123");

    Four f5("0012");
    EXPECT_EQ(f5.toString(), "12");

    EXPECT_THROW(Four("12a3"), std::invalid_argument);
}

TEST(FourTests, CopyAssignment) {
    Four copy(Four("123"));
    EXPECT_EQ(copy.toString(), "123");

    Four assigned;
    assigned = copy;
    EXPECT_EQ(assigned.toString(), "123");
}

TEST(FourTests, Arithmetic) {
    EXPECT_EQ(Four("12").add(Four("3")).toString(), "21");
    EXPECT_EQ(Four("3").add(Four("1")).toString(), "10");
    EXPECT_EQ(Four("123").add(Four("0")).toString(), "123");

    EXPECT_EQ(Four("21").subtract(Four("3")).toString(), "12");
    EXPECT_THROW(Four("1").subtract(Four("2")), std::invalid_argument);
    EXPECT_EQ(Four("123").subtract(Four("0")).toString(), "123");
}

TEST(FourTests, Comparison) {
    EXPECT_TRUE(Four("123").equals(Four("123")));
    EXPECT_FALSE(Four("21").lessThan(Four("12")));
    EXPECT_FALSE(Four("12").greaterThan(Four("21")));
    EXPECT_TRUE(Four("100").greaterThan(Four("33")));
}

TEST(FourTests, AccessMethods) {
    Four f("123");
    EXPECT_EQ(f.getDigit(0), 3);
    EXPECT_EQ(f.getDigit(1), 2);
    EXPECT_EQ(f.getDigit(2), 1);
    EXPECT_THROW(f.getDigit(3), std::out_of_range);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}