#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

vector<double> Optimize(vector<double> x0, vector<double> grad, double step, double eps, int maxIter);