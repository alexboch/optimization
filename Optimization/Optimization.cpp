#include "stdafx.h"
#include "Optimization.h"


OptInfo Optimize(vector<double> x0, double(*f)(vector<double>), vector<double>(*grad)(vector<double>), 
	double step0, double eps, int maxIter, double stepFraction,double stepEps)
{
	vector<double> optArgs = x0;//������ � �����������, ��� ������� �������� �-� ����������
	double val = f(optArgs);
	std::vector<double> values;
	values.push_back(val);
	int iters = 0;
	for (iters = 0; iters < maxIter; iters++)
	{
		double step = step0;
		vector<double> g = grad(optArgs);//��������
		vector<double> newArgs = optArgs - step*g;
		double newVal = f(newArgs);
		while (newVal > val - stepEps*step*norm_2(g))
		{
			step *= stepFraction;
			newArgs = optArgs - step*g;
			newVal = f(newArgs);

		}
		double d = abs(newVal - val);
		if (d < eps)//�������� ��������
		{
			//return optArgs;
			//OptInfo opt(f(optArgs), optArgs);
			return OptInfo(val, optArgs, iters + 1, values);
		}
		val = newVal;
		/*val = f(newArgs);
		*/
		values.push_back(val);
		optArgs = newArgs;
	}
	return OptInfo(val, optArgs, iters, values);
}
