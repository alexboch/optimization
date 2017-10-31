#include "stdafx.h"
#include "OptFuncs.h"

double Quad(vector<double> x)
{
	return ((x[0] - x[1])*(x[0] - x[1]) + (x[0] + x[1] - 10)*(x[0] + x[1] - 10)) / 9;
}

double Rozenbrock(vector<double> x)
{
	return 100 * (x[0]*x[0] - x[1])*(x[0] * x[0] - x[1]) + (1 - x[0])*(1 - x[0]);
}

double Valley(vector<double> x)
{
	return ((x[0] - 3) / 100)*((x[0] - 3) / 100) - (x[1] - x[0]) + exp(20 * (x[1] - x[0]));
}

double Powell(vector<double> x)
{
	return pow((x[0] + 10 * x[1] * x[1]),2) + 5 * pow((x[2] - x[3]) , 2) + pow(x[1] - 2 * x[2], 4) + 10 * pow(x[0] - x[3], 4);
}

double LMS(vector<double> x)
{
	const int n = 7;
	double a[n] = { 0,0.428,1,1.61,2.09,3.48,5.25 };
	double b[n] = { 7.391,11.18,16.44,16.20,22.2,24.02,31.32 };

	for(int i=0;i<n;i++)
	{
		a[i] /= 1000.0;
	}
	double s = 0;
	for(int i=0;i<n;i++)
	{
		double s1 = (x[0] * x[0] + x[1] * x[1] * a[i] + x[2] * x[2] * a[i] * a[i])/(1+x[3]*x[3]*a[i])-b[i];
		s += (s1 / b[i])*(s1 / b[i]);
	}
	return s * 10000;
}
