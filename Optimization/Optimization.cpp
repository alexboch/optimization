#include "stdafx.h"
#include "Optimization.h"


OptInfo Optimize(vector<double> x0, double(*f)(vector<double>), vector<double>(*grad)(vector<double>), 
	double step0, double eps, int maxIter,double maxStep)
{
	vector<double> optArgs = x0;//вектор с аргументами, при которых значение ф-и минимально
	double val = f(optArgs);
	std::vector<double> values;
	values.push_back(val);
	int iters = 0;
	for (iters = 0; iters < maxIter; iters++)
	{
		double step = step0;
		vector<double> g = grad(optArgs);//градиент
		
		step = GoldenSectionSearch(step0, 0, maxStep,//Оптимизация шага методом золотого сечения
			[&](double s) {
			return f(optArgs - s*g);
		}, 1e-5);
		
		vector<double> newArgs = optArgs - step*g;
		double newVal = f(newArgs);


		/*while (newVal > val - stepEps*step*norm_2(g))
		{
			step *= stepFraction;
			newArgs = optArgs - step*g;
			newVal = f(newArgs);

		}*/
		//double d = abs(newVal - val);
		double d = norm_2(newArgs - optArgs);
		if (d < eps)//критерий останова
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

const double GoldenRatio = (1 + sqrt(5)) / 2.0;
double GoldenSectionSearch(double x,double a, double b, std::function<double(double)> f, double eps)
{
	while (abs(b - a) >= eps)
	{
		double x1 = b - (b - a) / GoldenRatio;
		double x2 = a + (b - a) / GoldenRatio;
		double y1 = f(x1);
		double y2 = f(x2);
		if (y1 >= y2)
			a = x1;
		else
			b = x2;
	}
	return (a + b) / 2;
}
