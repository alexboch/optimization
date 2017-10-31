#include "stdafx.h"
#include "Gradients.h"

//vector<double> QuadGrad(vector<double> x)
//{
//	
//}
const double dh = 1e-9;//приращение аргумента
vector<double> ComputeGradient(vector<double> x,double(*f)(vector<double>))
{
	vector<double> grad;
	int n = x.size();
	grad.resize(n);
	for(int i=0;i<n;i++)
	{
		vector<double> xi = x;
		xi[i] += dh;//приращение i-го аргумента
		double d= (f(xi) - f(x)) / dh;//частная производная
		grad[i] = d;
	}
	return grad;
}
