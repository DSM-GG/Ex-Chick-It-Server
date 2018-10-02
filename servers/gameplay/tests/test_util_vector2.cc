//
// Created by moreal-gram on 2018-10-01.
//

#include <gtest/gtest.h>

#include <core/util.h>

using Util::Vector2;

struct vector_state {
    Vector2 a, b;
    double literal;

    struct result {
        Vector2 sum, sub, mul, div;
    } result;
};

struct Vector2Test : public testing::WithParamInterface<vector_state>, testing::Test {
    Vector2 GetSum(Vector2 a, Vector2 b) const {
        return a + b;
    }

    Vector2 GetSub(Vector2 a, Vector2 b) const {
        return a - b;
    }

    Vector2 GetMul(Vector2 a, double literal) const {
        return a * literal;
    }

    Vector2 GetDiv(Vector2 a, double literal) const {
        return a / literal;
    }
};

TEST_P(Vector2Test, SumTest) {
    auto as = GetParam();
    EXPECT_EQ(GetSum(as.a, as.b), as.result.sum);
}

TEST_P(Vector2Test, SubTest) {
    auto as = GetParam();
    EXPECT_EQ(GetSub(as.a, as.b), as.result.sub);
}

TEST_P(Vector2Test, MulTest) {
    auto as = GetParam();
    EXPECT_EQ(GetMul(as.a, as.literal), as.result.mul);
}

TEST_P(Vector2Test, DivTest) {
    auto as = GetParam();
    EXPECT_EQ(GetDiv(as.a, as.literal), as.result.div);
}

INSTANTIATE_TEST_CASE_P(Default, Vector2Test,
        testing::Values(
                vector_state { {1, 1}, {2, 3}, 4,
                               {{3, 4}, {-1, -2}, {4, 4}, {0.25, 0.25}}},
                vector_state { {15, 40}, {25, 55}, 5,
                               {{40, 95}, {-10, -15}, {75,200}, {3, 8}}}));