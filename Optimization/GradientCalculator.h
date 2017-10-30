#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;
class GradientCalculator
{
public:
	GradientCalculator();
	~GradientCalculator();
	vector<double> operator()(vector<double>);

};

