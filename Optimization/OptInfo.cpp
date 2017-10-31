#include "stdafx.h"
#include "OptInfo.h"


OptInfo::OptInfo()
{
}

OptInfo::OptInfo(double minVal, vector<double> minVec)
{
	MinValue = minVal;
	MinVector = minVec;
}


OptInfo::~OptInfo()
{
}

std::ostream& operator<<(std::ostream& os, const OptInfo& opt)
{
	os << "Mimimum value:" << opt.MinValue << std::endl;
	os << "Minimum vector:" << opt.MinVector;
	return os;
}
