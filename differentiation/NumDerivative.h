//
// Created by Moin on 2022-06-30.
//

#ifndef DIFFERENTIATION_NUMDERIVATIVE_H
#define DIFFERENTIATION_NUMDERIVATIVE_H

double ForwardDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX));
double BackwardDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX));
double CentralDiff (double dX, int fnc, double dH, double(*userfunc)(int fnc, double dX));

#endif //DIFFERENTIATION_NUMDERIVATIVE_H
