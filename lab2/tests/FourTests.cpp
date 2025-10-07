#include "gtest/gtest.h"
#include "Four.h"

// Тесты конструкторов
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

    EXPECT_THROW(Four(2, 5), std::invalid_argument);
    EXPECT_THROW(Four({1, 4, 2}), std::invalid_argument);
    EXPECT_THROW(Four("12a3"), std::invalid_argument);
}

TEST(FourTests, CopyMove) {
    Four original("123");
    
    Four copy(original);
    EXPECT_EQ(copy.toString(), "123");

    Four moved(std::move(original));
    EXPECT_EQ(moved.toString(), "123");
    EXPECT_TRUE(original.isEmpty());

    Four assigned;
    assigned = moved;
    EXPECT_EQ(assigned.toString(), "123");
}

TEST(FourTests, Arithmetic) {
    EXPECT_EQ(Four("12").add(Four("3")).toString(), "21");
    EXPECT_EQ(Four("3").add(Four("1")).toString(), "10");

    EXPECT_EQ(Four("21").subtract(Four("3")).toString(), "12");
    EXPECT_THROW(Four("1").subtract(Four("2")), std::invalid_argument);
}

// Тесты операций сравнения
TEST(FourTests, Comparison) {
    EXPECT_TRUE(Four("123").equals(Four("123")));
    EXPECT_FALSE(Four("123").equals(Four("12")));

    EXPECT_TRUE(Four("12").lessThan(Four("21")));
    EXPECT_FALSE(Four("21").lessThan(Four("12")));

    EXPECT_TRUE(Four("21").greaterThan(Four("12")));
    EXPECT_FALSE(Four("12").greaterThan(Four("21")));

    EXPECT_TRUE(Four("33").lessThan(Four("100")));
    EXPECT_TRUE(Four("100").greaterThan(Four("33")));
}

// Тесты граничных случаев
TEST(FourTests, EdgeCases) {
    // Операции с нулем
    Four zero("0");
    Four num("123");
    
    EXPECT_EQ(num.add(zero).toString(), "123");
    EXPECT_EQ(zero.add(num).toString(), "123");
    EXPECT_EQ(num.subtract(zero).toString(), "123");
    EXPECT_EQ(zero.subtract(zero).toString(), "0");

    // Большие числа
    EXPECT_EQ(Four("333333").add(Four("1")).toString(), "1000000");
    EXPECT_EQ(Four("1000000").subtract(Four("1")).toString(), "333333");

    // Одноразрядные операции
    EXPECT_EQ(Four("2").add(Four("3")).toString(), "11");
    EXPECT_EQ(Four("1").subtract(Four("0")).toString(), "1");
}

// Тесты методов доступа
TEST(FourTests, AccessMethods) {
    Four f("123");
    
    EXPECT_EQ(f.getDigit(0), 3);
    EXPECT_EQ(f.getDigit(1), 2);
    EXPECT_EQ(f.getDigit(2), 1);
    EXPECT_THROW(f.getDigit(3), std::out_of_range);

    EXPECT_EQ(Four("0123").toString(), "123");
    EXPECT_EQ(Four("000").toString(), "0");
    EXPECT_EQ(Four("100").toString(), "100");
}

TEST(FourTests, Immutability) {
    Four original("123");
    
    Four added = original.add(Four("1"));
    Four subtracted = original.subtract(Four("1"));
    Four copied = original.copy();

    EXPECT_EQ(original.toString(), "123");
    EXPECT_NE(&original, &added);
    EXPECT_NE(&original, &copied);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}