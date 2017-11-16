// Optimization.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
# include <boost/assign/std/vector.hpp>
#include <iostream>
#include "Optimization.h"
#include "Gradients.h"
#include "OptFuncs.h"
#include "OptInfo.h"
using namespace boost::assign;
int main()
{
	double step = 1;//Шаг
	double eps = 1e-7;
	double stepEps = 0.001;
	int maxIter = 1e+3;
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
#pragma region 1.	Квадратичная функция 
	vector<double> x0(2);// начальные условия
	x0[0] = 1;
	x0[1] = 0;
	OptInfo xs=Optimize(x0,Quad,[] (vector<double> x)
	{
		return ComputeGradient(x, Quad);
	},step,eps,maxIter);
	std::cout <<"Квадратичная функция:"<<std::endl<< xs<<std::endl;
#pragma endregion
#pragma region 2.	Функция Розенброка
	x0[0] = -1.2;
	x0[1] = 1;
	/*xs = Optimize(x0, Rozenbrock, [](vector<double> x)
	{
		return ComputeGradient(x, Rozenbrock);
	}, 0.001, eps, maxIter);*/
	xs = Optimize(x0, Rozenbrock,RosenGrad, step, eps, 1e+6);
	std::cout <<"Функция Розенброка\n"<< xs<<std::endl;
#pragma endregion
#pragma region 3.	Ассиметричная долинаs
	x0[0] = 0;
	x0[1] = -1;
	xs = Optimize(x0, Valley, ValleyGrad, step, eps, 1e+8);
#pragma region output
	/*xs.MinVector[0] = 2.999;
	xs.MinVector[1] = 2.85019;
	xs.MinValue = Valley(xs.MinVector);*/
	std::cout << "Ассиметричная долина\n" << xs << std::endl;
#pragma endregion
#pragma endregion 
#pragma region 4.	Функция Пауэлла
	
	x0.resize(4);
	x0[0] = 3;
	x0[1] = -1;
	x0[2] = 0;
	x0[3] = 1;
	xs = Optimize(x0, Powell, PowellGrad, step, eps
		, 1e+8);
	std::cout << "Функция Пауэлла\n" << xs << std::endl;
#pragma endregion
#pragma region 5.	Пример, связанный с оценкой экспериментальных данных методом наименьших квадратов
	x0[0] = 2.7;
	x0[1] = 90;
	x0[2] = 1500;
	x0[3] = 10;
	xs = Optimize(x0, LMS, [](vector<double> x)
	{
		return ComputeGradient(x, LMS);
	}, step, eps, 1e+7);

	/*xs = Optimize(x0, LMS, LMSGrad, step, eps, 1e+7);*/
#pragma region output1
	/*vector<double> y(4);
	y[0] = 2.71399;
	y[1] = 140.42;
	y[2] = 1706.998;
	y[3] = 31.5099;
	xs.MinVector = y;
	xs.MinValue = LMS(y)*10000;*/
	std::cout << "Метод наименьших квадратов\n";
	xs.MinValue *= 10000;
	std::cout << xs;
#pragma endregion
#pragma endregion 
	
	/*double x = GoldenSectionSearch(5, -10, 10, [](double x)
	{
		return x*x;
	},0.01
	);*/
	system("PAUSE");
    return 0;
}

