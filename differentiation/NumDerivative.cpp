//
// Created by Moin on 2022-06-30.
//
#include "NumDerivative.h"

double ForwardDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX)) {
    double fxph = userfunc(fnc, dX + dH);
    double fx = userfunc(fnc, dX);
    double dDirev = (fxph - fx)/dH;

    return dDirev;
}

double BackwardDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX)) {
    double fxph = userfunc(fnc, dX);
    double fx = userfunc(fnc, dX - dH);
    double dDirev = (fxph - fx)/dH;

    return dDirev;
}

double CentralDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX)) {
    double fxph = userfunc(fnc, dX + dH);
    double fx = userfunc(fnc, dX - dH);
    double dDirev = (fxph - fx)/(2*dH);

    return dDirev;
}