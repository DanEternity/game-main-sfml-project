#include "utility.h"

std::string floatToString(float x)
{
	std::stringstream ss;
	std::string s;
	ss << x;
	ss >> s;
	return s;
}
