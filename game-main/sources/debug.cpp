#include "debug.h"

void Log(std::string output)
{
	std::cout << output << std::endl;
}

void Logs(std::string output)
{
	std::cout << output;
}

void Logs(const void * output)
{
	std::cout << output;
}

void Logln(std::string output)
{
	Log(output);
}
