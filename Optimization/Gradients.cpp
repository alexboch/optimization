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

vector<double> RosenGrad(vector<double> x)
{
	vector<double> grad(2);
	grad[0] = 2 * (200 * x[0] * x[0] * x[0] - 200 * x[0] * x[1] + x[0] - 1);
	grad[1] = -200 * (x[0] * x[0] - x[1]);
	return grad;
}

vector<double> ValleyGrad(vector<double> x)
{
	vector<double> grad(x.size());
	grad[0] = -20 * exp(20*(x[1] - x[0])) + (x[0] - 3) / 5000 + 1;
	grad[1] = 20 * exp(20*(x[1] - x[0])) - 1;
	return grad;
}

double G(vector<double> x, double a,double b)
{
	return (-b*(a*x[3] * x[3] + 1) + a*(a*x[2] * x[2]) + x[1] * x[1]) / (pow((a*x[3] * x[3] + 1), 2));
}

vector<double> LMSGrad(vector<double> x)
{
	vector<double> grad(x.size());
	const int n = 7;
	double a[n] = { 0,0.428e-3,1e-3,1.61e-3,2.09e-3,3.48e-3,5.25e-3 };
	double b[n] = { 7.391,11.18,16.44,16.20,22.2,24.02,31.32 };
	for (int i = 0; i < grad.size(); i++)
		grad[i] = 0;
	for (int i = 0; i < n; i++)
	{
		double g = G(x, a[i], b[i]);
		double s1 = x[0] * g;
		double s2 = a[i]*x[1] * g;
		double s3 = a[i] * a[i] *x[2]* g;
		double s4 = -1 * (a[i] * x[3] * (a[i] * (a[i] * x[2] * x[2]) + x[0] * x[0])*g / (pow(a[i] * x[3] * x[3] + 1, 3)));
		grad[0] += s1;
		grad[1] += s2;
		grad[2] += s3;
		grad[3] += s4;
	}
	return grad*2;
}

vector<double> PowellGrad(vector<double> x)
{
	vector<double> grad(x.size());
	grad[0] = 2 * (20 * pow((x[0] - x[3]), 3) + x[0] + 10 * x[1] * x[1]);
	grad[1] = 40 * x[1] * (x[0] + 10 * x[1] * x[1]) + 4 * pow(x[1] - 2 * x[2], 3);
	grad[2] = 10 * (x[2] - x[3]) - 8 * pow(x[1] - 2 * x[2], 3);
	grad[3] = 10 * (-4 * pow(x[0] - x[3], 3)) - x[2] + x[3];
	return grad;
}