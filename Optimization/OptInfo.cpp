#include "stdafx.h"
#include "OptInfo.h"


OptInfo::OptInfo()
{
}

OptInfo::OptInfo(double minVal, vector<double> minVec,int iters,std::vector<double> values)
{
	MinValue = minVal;
	MinVector = minVec;
	Iterations = iters;
	Values = values;
}


OptInfo::~OptInfo()
{
}

std::ostream& operator<<(std::ostream& os, const OptInfo& opt)
{
	os << "Минимальное значение:" << opt.MinValue << std::endl;
	os << "Минимальная точка:" << opt.MinVector;
	return os;
}
