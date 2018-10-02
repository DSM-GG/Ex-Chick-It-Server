//
// Created by moreal-gram on 2018-10-01.
//

#include <gtest/gtest.h>

#include <core/util.h>

struct vector_state {
    Util::Vector2 sum, sub, mul;
};
struct Vector2Test : public testing::WithParamInterface<>

TEST_P(Vector2SumTest, SumTest) {
    Util::Vector2 vector2 { 10, 30 };
    vector2
}