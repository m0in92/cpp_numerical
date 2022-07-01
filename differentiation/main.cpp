/*
 * forward, central, and backward difference methods. Adopted from Rajan et al.
 */

#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include "NumDerivative.h"

double MyFunction(int fnc, double dX) {
    double df = 0.0;
    if (fnc == 1)
        df = pow(dX, 3)-2.0*dX*dX+10*dX-5.0;
    else if (fnc==2)
        df = dX/(dX*dX-1);

    return df;
}

int main() {
    const int FNC = 1;
    double dhTrial[] = {1.0e-15, 1.0e-10, 1.0e-8, 1.0e-5, 1.0e-2, 1.0e-1};
    double dX = 2.0;
    double dExact = 14.0;

    int nElements = sizeof(dhTrial)/ sizeof(dhTrial[0]);
    double dBest = std::numeric_limits<double>::max();
    double dBestDeriv, dBesth;
    std::string BestMethod = "None";
    for (int i=0; i < nElements; i++) {
        double dH = dhTrial[i];
        double dDerivFD = ForwardDiff(dX, FNC, dH, MyFunction);
        double dRelErrorFD = (dDerivFD-dExact)/dExact;
        if (fabs(dRelErrorFD)< dBest) {
            dBest = fabs(dRelErrorFD);
            dBestDeriv = dDerivFD;
            dBesth = dH;
            BestMethod = "Forward Difference";
        }
        double dDerivBD = BackwardDiff(dX, FNC, dH, MyFunction);
        double dRelErrorBD = (dDerivBD-dExact)/dExact;
        if (fabs(dRelErrorBD) < dBest) {
            dBest = fabs(dRelErrorBD);
            dBestDeriv = dDerivBD;
            dBesth = dH;
            BestMethod = "Backward Difference";
        }

        double dDerivCD = CentralDiff(dX, FNC, dH, MyFunction);
        double dRelErrorCD = (dDerivCD-dExact)/dExact;
        if (fabs(dRelErrorCD) < dBest) {
            dBest = fabs(dRelErrorCD);
            dBestDeriv = dDerivCD;
            dBesth = dH;
            BestMethod = "Centered Difference";
        }
    }
    std::cout << dBestDeriv << std::endl;
    std::cout << dBesth << std::endl;
    std::cout << dBest << std::endl;
    std::cout << BestMethod << std::endl;

    return 0;
}
