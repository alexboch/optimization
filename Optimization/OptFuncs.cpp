#include "stdafx.h"
#include "OptFuncs.h"

double Quad(vector<double> x)
{
	return ((x[0] - x[1])*(x[0] - x[1]) + (x[0] + x[1] - 10)*(x[0] + x[1] - 10)) / 9;
}

double Rozenbrock(vector<double> x)
{
	return 100 * (x[0]*x[0] - x[1])*(x[0] * x[0] - x[1]) + (1 - x[0])*(1 - x[0]);
}
