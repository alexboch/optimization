/*Функции для оптимизациии*/
#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

double Quad(vector<double> args);//Квадратичная
double Rozenbrock(vector<double> args);
double Valley(vector<double> args);//Асимметричная долина
double Powell(vector<double> args);//Пауэлла
double LMS(vector<double> args);//Наименьших квадратов
double LMS_0(vector<double> x);
