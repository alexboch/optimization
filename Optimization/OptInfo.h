#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

struct OptInfo
{
	double MinValue;//Найденное значение
	vector<double> MinVector;
	int Iterations;
	std::vector<double> Values;//Значения функции, получаемые при спуске
	OptInfo();
	friend std::ostream& operator<<(std::ostream& os, const OptInfo& dt);//Перегруженный оператор вывода

	OptInfo(double minVal, vector<double> minVec,int iters,std::vector<double> values);
	~OptInfo();
};

