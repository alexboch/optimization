#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
using namespace boost::numeric::ublas;


//��������� �������� ��������� �������
vector<double> ComputeGradient(vector<double> x,double(*f)(vector<double>));

vector<double> QuadGrad(vector<double> args);//�������� ������������ �������

vector<double> RosenGrad(vector<double> x);//�������� ������� ����������

vector<double> ValleyGrad(vector<double> x);//�������� ������������� ������

vector<double> PowellGrad(vector<double> x);//�������� ������� �������

vector<double> LMSGrad(vector<double> x);//�������� ��� ������ ���������� ���������