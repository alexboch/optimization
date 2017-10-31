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
	double eps = 1e-5;
	int maxIter = 1e+6;
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
	xs = Optimize(x0, Rozenbrock, [](vector<double> x)
	{
		return ComputeGradient(x, Rozenbrock);
	}, step, eps, maxIter);
	std::cout <<"Функция Розенброка\n"<< xs<<std::endl;
#pragma endregion
#pragma region 3.	Ассиметричная долинаs
	step = 0.001;
	x0[0] = 0;
	x0[1] = -1;
	xs = Optimize(x0, Valley, [](vector<double> x)
	{
		return ComputeGradient(x, Valley);
	}, step, eps, maxIter);
	std::cout << "Ассиметричная долина\n" << xs << std::endl;
#pragma endregion 
#pragma region 4.	Функция Пауэлла
	step = 1;
	x0.resize(4);
	x0[0] = 3;
	x0[1] = -1;
	x0[2] = 0;
	x0[3] = 1;
	xs = Optimize(x0, Powell, [](vector<double> x)
	{
		return ComputeGradient(x, Powell);
	}, step, eps, maxIter);
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
	}, step, eps, maxIter);
	std::cout << "Метод наименьших квадратов\n" << xs << std::endl;
#pragma endregion 
	system("PAUSE");
    return 0;
}

