#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

vector<double> Optimize(vector<double> x0, double(*f)(vector<double>), vector<double>(*grad)(vector<double>), double step, double eps, int maxIter);