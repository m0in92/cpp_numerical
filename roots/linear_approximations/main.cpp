/*
 * This code finds the root of a function (x^2 - 3) using approximation methods, i.e., secant and Newton-Rhaphson method.
 * Pros of approximation method: Fast convergence if it converges
 * Cons of approximation method: convergence is not guaranteed.
 */

#include <iostream>
#include <cmath>

double EP = 0.00000001;

double func (double x) {
    return pow(x,2) - 3;
}

double secant(double a, double b) {
    double root = b;
    double criteria = 1000;
    while (fabs(criteria) > EP) {
        double root_temp = root;
        root = a - func(a) * (b-a) / (func(b)-func(a));
        a = b;
        b = root;
        criteria = root - root_temp;
    }
    return root;
}

double diff_func (double x) {
    return 2 * x;
}

double Newton_Raphson(double a) {
    double root = a;
    double criteria = 1000;
    while (fabs(criteria) > EP) {
        double root_temp = root;
        root = root - func(root)/ diff_func(root);
        criteria = root - root_temp;
    }
    return root;
}

int main() {
    double a = 1, b = 2;
    std::cout.precision(11);
    std::cout << secant(a,b) << std::endl;
    std::cout << Newton_Raphson(2) << std::endl;
    return 0;
}
