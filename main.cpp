#include <iostream>

#include <boost/program_options.hpp>

#include "MovingLinearRegression.h"
#include "Utils.h"

void TrendWithNoise(double a, double b, double w);

int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    po::options_description options("Allowed options");
    options.add_options()
        ("help", "produce help message")
        ("a", po::value<double>()->default_value(0.0), "Parameter a. Linear model: y = a + bx")
        ("b", po::value<double>()->default_value(1.0), "Parameter b. Linear model: y = a + bx")
        ("w", po::value<double>()->default_value(0.0), "Noise amplitude. Model: y = a + bx + w * sin(kx)")
        ("random", po::bool_switch()->default_value(false), "Use random parameters")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, options), vm);
    po::notify(vm);    

    if(vm.count("help")) {
        std::cout << options;
        return 1;
    }

    double a = vm["a"].as<double>();
    double b = vm["b"].as<double>();
    double w = vm["w"].as<double>();
    if(vm["random"].as<bool>()) {
        a = Random(-10.0, 10.0);
        b = Random(-2.0, 2.0);
        w = Random(0.01, 0.2);
    }

    TrendWithNoise(a, b, w);
    return 0;
}

void TrendWithNoise(double a, double b, double w) {
    MovingLinearRegression mlr(100);

    for(double x = -100; x < 100.0; x += 0.1) {
        const auto noise = w * std::sin(PI * (x / 10.0));
        const auto y = a + x * b + noise;
        mlr.Push(x, y);
        const auto estimation = mlr.Get();
        std::cout << "(" << x << ", " << y << ") estimation: a = " << estimation.a << ", b = " << estimation.b << std::endl;
    }

    std::cout << std::endl << "Trend line with noise, actual parameters: a=" << a << ", b=" << b << ", w=" << w << std::endl;
}
