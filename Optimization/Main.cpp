// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
# include <boost/assign/std/vector.hpp>
#include <iostream>
#include "Optimization.h"
#include "Gradients.h"
#include "OptFuncs.h"
using namespace boost::assign;
int main()
{
	double step = 1.5;
	double eps = 1e-5;
	int maxIter = 1e+8;
	vector<double> x0(2);// начальные условия
	x0[0] = 1;
	x0[1] = 0;
	
	vector<double> xs=Optimize(x0,Quad,[] (vector<double> x)
	{
		return ComputeGradient(x, Quad);
	},step,eps,maxIter);
	std::cout << "Quad:" << xs << std::endl;
	x0[0] = -1.2;
	x0[1] = 1;
	xs = Optimize(x0, Rozenbrock, [](vector<double> x)
	{
		return ComputeGradient(x, Rozenbrock);
	}, step, eps, maxIter);
	std::cout <<"Rozenbrock:"<< xs<<std::endl;
	system("PAUSE");
    return 0;
}

