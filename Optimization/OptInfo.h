#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

struct OptInfo
{
	double MinValue;//��������� ��������
	vector<double> MinVector;
	int Iterations;
	std::vector<double> Values;//�������� �������, ���������� ��� ������
	OptInfo();
	friend std::ostream& operator<<(std::ostream& os, const OptInfo& dt);//������������� �������� ������

	OptInfo(double minVal, vector<double> minVec,int iters,std::vector<double> values);
	~OptInfo();
};

