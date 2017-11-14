/*������� ��� ������������*/
#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;

double Quad(vector<double> args);//������������
double Rozenbrock(vector<double> args);
double Valley(vector<double> args);//������������� ������
double Powell(vector<double> args);//�������
double LMS(vector<double> args);//���������� ���������
double LMS_0(vector<double> x);
