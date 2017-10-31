#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;


//Вычисляет градиент численным методом
vector<double> ComputeGradient(vector<double> x,double(*f)(vector<double>));

vector<double> QuadGrad(vector<double> args);//градиент квадратичной функции
