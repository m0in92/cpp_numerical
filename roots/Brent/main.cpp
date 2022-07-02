#include <iostream>
#include <iomanip>
#include <cmath>

double sign (double a)
{
    if (a >= 0.0)
        return 1.0;
    else
        return -1.0;
}

double Func(double x, int EQNTOSOLVE, int& nFE) {
    ++nFE;
    if (EQNTOSOLVE == 1)
        return ((x-1.0)*(1.0+pow((x-1.0),2)));
    else if (EQNTOSOLVE == 2)
        return (x*x-1.0);
    else if (EQNTOSOLVE == 3)
        return (-1.0+x*(3.0+x*(-3.0+x)));
    else if (EQNTOSOLVE == 4)
        return ((x-1.0)*exp(-1.0/((x-1.0)*(x-1.0))));
    else {
        std::cerr << "Invalid equation to solve.\n";
        exit(1);
    }
}

int main() {
    const int MAXITERS = 100;
    const int EQNTOSOLVE = 1;

    // Step 1
    double a = 3.0, b = 0.0;
    double delta = 0.00001;
    double bpp, bp;
    int nIter = 0, nFE = 0;

    double dfa = Func(a, EQNTOSOLVE, nFE);
    double dfb = Func(b, EQNTOSOLVE, nFE);
    if (dfa * dfb > 0.0) {
        std::cout << "Bad initial bracket.\n";
        return 1;
    }

    // iteration until root is found
    double c = a;
    std::cout << std::setw(15) << b << std::setw(15) << "f(b)"
              << std::setw(15) << "c" << "\n" << std::string(14, '-') << "\n";
    for (;;) {
        if (++nIter > MAXITERS) {
            std::cout << "Unable to converge";
            return 1;
        }

        //Update m
        double m = 0.5 * (c - b);

        //Step 2
        if (abs(dfa) <= delta || abs(m) <= delta) {
            std::cout << "\n" << "The root is :" << b << "\n"
                      << "Final Func.Value: " << dfb << "\n" << "# of Func. Evals: "
                      << nFE << "\n";
            return 0;
        }

        //Step 3
        double dNum = dfb * (b - a);
        double dDenom = dfb - dfa;
        double i = dNum / dDenom;

        //Step 4
        if (b <= i && i <= (b + m))
            bpp = i;
        else
            bpp = b + m;

        if (abs(b-bpp) > delta)
            bp = bpp;
        else
            bp = b + delta*sign(m);

        // Step 5
        double bnew = bp;
        a = b;
        double dfbnew = Func(bnew, EQNTOSOLVE, nFE);
        if (dfbnew * dfb < 0)
            c = b;
        b = bnew;
        dfb = dfbnew;
    }

    return 0;
}
