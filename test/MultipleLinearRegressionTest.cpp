#include "../MultipleLinearRegression.h"
#include <gtest/gtest.h>
#include <iostream>

class MultipleLinearRegressionTest : public ::testing::Test {
public:
    static constexpr auto kEps = 0.001;

public:
    MultipleLinearRegressionTest() {
        srand(static_cast<unsigned int>(time(0)));
    }
};

TEST_F(MultipleLinearRegressionTest, Basic) {
    constexpr auto N = 1024;
    constexpr auto K = 23;
    Eigen::Matrix<float, N, 1> Y;
    Eigen::Matrix<float, N, K> X;

    X.setRandom();
    X(0, 0) = 1.0;

    Eigen::Matrix<float, K, 1> A;
    A.setRandom();
    A(0, 0) = rand() / static_cast<float>(RAND_MAX);

    for(auto r = 0; r < N; ++r) {
        Y(r, 0) = 0;
        for(auto c = 0; c < K; ++c) {
            Y(r, 0) += A(c, 0) * X(r, c);
        }
    }
    std::cout << "A:\n" << A << std::endl;

    const auto W = MultipleLinearRegression::Estimate(X, Y);
    std::cout << "W:\n" << W << std::endl;

    ASSERT_EQ(A.rows(), W.rows());
    ASSERT_EQ(A.cols(), W.cols());
    for(auto c = 0; c < K; ++c) {
        ASSERT_NEAR(A(c, 0), W(c, 0), kEps);
    }    
}
