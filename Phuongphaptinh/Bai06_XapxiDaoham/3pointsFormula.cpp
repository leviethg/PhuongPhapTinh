#include <iostream>

double threePointMidpointFormula(double x0, double f0, double x1, double f1, double x2, double f2, double h) {
    double derivative = (f2 - f0) / (2 * h);
    return derivative;
}

double threePointEndpointFormula(double x0, double f0, double x1, double f1, double x2, double f2, double h) {
    double derivative = (-3 * f0 + 4 * f1 - f2) / (2 * h);
    return derivative;
}

int main() {
    double x0, f0, x1, f1, x2, f2, h;

    // Input values
    std::cout << "Enter x0: ";
    std::cin >> x0;
    std::cout << "Enter f(x0): ";
    std::cin >> f0;

    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter f(x1): ";
    std::cin >> f1;

    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter f(x2): ";
    std::cin >> f2;

    h = (x1 - x0);

    // Calculate derivatives using the formulas
    double midpointDerivative = threePointMidpointFormula(x0, f0, x1, f1, x2, f2, h);
    double endpointDerivative = threePointEndpointFormula(x0, f0, x1, f1, x2, f2, h);

    // Output the results
    std::cout << "Using Three-Point Midpoint Formula, f'(x0) = " << midpointDerivative << std::endl;
    std::cout << "Using Three-Point Endpoint Formula, f'(x0) = " << endpointDerivative << std::endl;

    return 0;
}

