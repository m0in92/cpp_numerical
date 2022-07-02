/*
 * Finding root of a function using bracketing methods, i.e., bisection and false method.
 * Pros of bracketing methods: easy to implement and root is guaranteed.
 * Cons of brackets methods: slow convergence.
 * */

#include <iostream>
#include <cmath>

double EP = 0.000001;

double func(double x) {
    return pow(x,2) - 3;
}

double sign(double a, double b) {
    if (func(a)*func(b) == 0) {
        return 0;
    }
    else if (func(a)*func(b) > 0) {
        return 1;
    }
    else {
        return -1;
    }
}

double calc_midpoint(double a, double b) {
    return (a+b)/2;
}

double bisection(double a, double b) {
    if (func(a) * func(b) >= 0) {
        throw std::invalid_argument("Choose another interval.");
    }
    else {
        double c;
        while ((b - a) >= EP) {
            c = calc_midpoint(a, b);
            if (func(c) == 0.0) {
                break;
            } else if (sign(c, a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
        return c;
    }
}

double false_method_c(double a, double b) {
    return a - func(a)*(b-a)/(func(b)-func(a));
}

double false_method(double a, double b) {
    if (func(a) * func(b) >= 0) {
        throw std::invalid_argument("Choose another interval.");
    }
    else {
        double c;
        while ((b - a) >= EP) {
            c = false_method_c(a, b);
            if (func(c) == 0.0) {
                break;
            } else if (sign(c, a) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
        return c;
    }
}

int main(){
    double a = 1, b = 2;
    std::cout << bisection(a,b) << std::endl;
    std::cout << false_method(a,b) << std::endl;

    return 0;
}


