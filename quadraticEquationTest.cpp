#include "quadraticEquation.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class QuadraticEquationTest : public ::testing::Test
{
};


// (x-3)(x+3)
TEST_F(QuadraticEquationTest, GivenEquationWithTwoQuadraticRoots)
{
    std::pair<unsigned, std::pair<float, float>> expectetResult {2, {-3,3}};
    EXPECT_EQ(expectetResult, utils::quadraticEquation(1,0,-9));
    
}

// (x+3)^2
TEST_F(QuadraticEquationTest, GivenEquationWithTwoSameQuadraticRoots)
{
    float expectedNumberOfRoots {1};
    float expectedRoot {3};
    auto result = utils::quadraticEquation(1,-6,9);

    EXPECT_EQ(expectedNumberOfRoots, result.first);
    EXPECT_EQ(expectedRoot, result.second.first);
}

TEST_F(QuadraticEquationTest, it_returns_0_as_solution_for_equation_x_pow_2_equals_0)
{
    auto answer = utils::quadraticEquation(1, 0, 0);

    auto numberOfSolutions = answer.first;
    auto solutions = answer.second;

    EXPECT_EQ(numberOfSolutions, 1);
    EXPECT_EQ(solutions.first, 0);
}

using Solution = std::pair<unsigned, std::pair<float, float>>;

TEST_F(QuadraticEquationTest, it_returns_1_and_minus_1_as_soultion_for_equation_x_pow_2_minus_1_equals_0)
{
    Solution expectedSolution{2, {-1, 1}};
    EXPECT_EQ(utils::quadraticEquation(1, 0, -1), expectedSolution);
}

//(x-5)(x-13)=x^2-13x-5x+5*13
TEST_F(QuadraticEquationTest, it_returns_5_and_13_as_solution_for_equation_x_pow_2_minus_18_plus_65)
{
    unsigned expectedNumberOfSolutions{2};
    float expectedSlution1{5};
    float expectedSolution2{13};
    Solution expectedSolution{expectedNumberOfSolutions, {expectedSlution1, expectedSolution2}};
    EXPECT_EQ(utils::quadraticEquation(1, -18, 65), expectedSolution);
}

TEST_F(QuadraticEquationTest, it_returns_two_float_solutions_for_equation_4x_pow_2_minus_15_plus_1)
{
    unsigned expectedNumberOfSolutions{2};
    float expectedSolution1{0.067896};
    float expectedSolution2{3.6821};

    auto receivedAnswer = utils::quadraticEquation(4, -15, 1);
    auto receivedSolutions = receivedAnswer.second;
    EXPECT_EQ(receivedAnswer.first, expectedNumberOfSolutions);
    EXPECT_NEAR(receivedSolutions.first, expectedSolution1, 0.0001);
    EXPECT_NEAR(receivedSolutions.second, expectedSolution2, 0.0001);
}
