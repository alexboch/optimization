#include "stdafx.h"
#include "Optimization.h"


OptInfo Optimize(vector<double> x0,double (*f)(vector<double>), vector<double> (*grad)(vector<double>), double step, double eps, int maxIter)
{
	vector<double> optArgs=x0;//������ � �����������, ��� ������� �������� �-� ����������
	double val = f(optArgs);
	std::vector<double> values;
	values.push_back(val);
	int iters = 0;
	for(iters=0;iters<maxIter;iters++)
	{
		vector<double> newArgs = optArgs - step*grad(optArgs);//����� ������ ���������� �������
		val = f(newArgs);
		double d = abs(f(newArgs) - f(optArgs));
		if (d < eps)//�������� ��������
		{
			//return optArgs;
			//OptInfo opt(f(optArgs), optArgs);
			return OptInfo(f(optArgs), optArgs,iters+1,values);
		}
		values.push_back(val);
		optArgs = newArgs;
	}
	return OptInfo(f(optArgs), optArgs,iters,values);
}
