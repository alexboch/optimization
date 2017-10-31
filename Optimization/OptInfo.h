#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

struct OptInfo
{
	double MinValue;
	vector<double> MinVector;
	OptInfo();
	friend std::ostream& operator<<(std::ostream& os, const OptInfo& dt);//Перегруженный оператор вывода

	OptInfo(double minVal, vector<double> minVec);
	~OptInfo();
};

