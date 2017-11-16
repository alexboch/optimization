#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "OptInfo.h"
using namespace boost::numeric::ublas;

OptInfo Optimize(vector<double> x0, double(*f)(vector<double>), vector<double>(*grad)(vector<double>), 
	double step, double eps, int maxIter, double maxStep=1);

//ћинимизаци€ методом золотого сечени€
double GoldenSectionSearch(double x,double a,double b, std::function<double(double)> f,double eps);