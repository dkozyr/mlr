#pragma once

#include <eigen3/Eigen/LU>

//https://online.stat.psu.edu/stat462/node/132/
//https://www.statology.org/multiple-linear-regression-by-hand/
class MultipleLinearRegression {
public:
    template<typename TFloat = float, int N = Eigen::Dynamic, int K = Eigen::Dynamic>
    static Eigen::Matrix<TFloat, K, 1> Estimate(const Eigen::Matrix<TFloat, N, K>& X, const Eigen::Matrix<TFloat, N, 1>& Y) {
        const auto Xt = X.transpose();
        return (Xt * X).inverse() * Xt * Y;
    }
};
