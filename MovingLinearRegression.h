#pragma once

#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/rolling_sum.hpp>

namespace ba = boost::accumulators;

class MovingLinearRegression {
public:
    struct Result{
        double a = 0.0;
        double b = 0.0;
    };

public:
    explicit MovingLinearRegression(size_t window_size)
        : _window_size(window_size)
        , _x(ba::tag::rolling_sum::window_size = window_size)
        , _y(ba::tag::rolling_sum::window_size = window_size)
        , _x2(ba::tag::rolling_sum::window_size = window_size)
        , _xy(ba::tag::rolling_sum::window_size = window_size)
    {}

    void Push(double x, double y) noexcept {
        _x(x);
        _y(y);
        _x2(x * x);
        _xy(x * y);
        _size = std::min(_size + 1, _window_size);
    }

    Result Get() const noexcept {
        if(_size < 2) {
            return {};
        }

        const auto N = static_cast<double>(_size);
        const auto sum_x = ba::rolling_sum(_x);
        const auto sum_y = ba::rolling_sum(_y);
        const auto sum_x2 = ba::rolling_sum(_x2);
        const auto sum_xy = ba::rolling_sum(_xy);

        const auto Sxy = N * sum_xy - sum_x * sum_y;
        const auto Sxx = N * sum_x2 - sum_x * sum_x;
        if(std::abs(Sxx) <= std::numeric_limits<double>::epsilon()) {
            return {};
        }
    
        const auto b = Sxy / Sxx;
        const auto a = (sum_y - b * sum_x) / N;

        return {.a = a, .b = b};
    }

private:
    using Container = ba::accumulator_set<double, ba::stats<ba::tag::rolling_sum>>;

    const size_t _window_size;
    size_t _size = 0;

    Container _x, _y, _x2, _xy;
};
