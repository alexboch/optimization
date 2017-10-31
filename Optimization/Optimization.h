#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "OptInfo.h"
using namespace boost::numeric::ublas;

OptInfo Optimize(vector<double> x0, double(*f)(vector<double>), vector<double>(*grad)(vector<double>), double step, double eps, int maxIter);