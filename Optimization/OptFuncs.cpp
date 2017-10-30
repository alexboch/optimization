#include "stdafx.h"
#include "OptFuncs.h"

double Quad(vector<double> x)
{
	return ((x[0] - x[1])*(x[0] - x[1]) + (x[0] + x[1] - 10)*(x[0] + x[1] - 10)) / 9;
}
