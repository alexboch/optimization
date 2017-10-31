#include "stdafx.h"
#include "Optimization.h"


OptInfo Optimize(vector<double> x0,double (*f)(vector<double>), vector<double> (*grad)(vector<double>), double step, double eps, int maxIter)
{
	vector<double> optArgs=x0;//������ � �����������, ��� ������� �������� �-� ����������
	for(int i=0;i<maxIter;i++)
	{
		vector<double> newArgs = optArgs - step*grad(optArgs);//����� ������ ���������� �������
		double d = abs(f(newArgs) - f(optArgs));
		if (d < eps)//�������� ��������
		{
			//return optArgs;
			//OptInfo opt(f(optArgs), optArgs);
			return OptInfo(f(optArgs), optArgs);
		}
		optArgs = newArgs;
	}
	return OptInfo(f(optArgs), optArgs);
}
