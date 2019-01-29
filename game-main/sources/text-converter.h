#pragma once

#include "lib\RichText.hpp"
#include "debug.h"
#include "utility.h"

#include <string>
#include <vector>
#include <sstream>

void RichStringParse(sfe::RichText * stream, std::string source, std::vector<void*> values);


// private section

bool ConvertCommand(sfe::RichText * q, std::string s, std::vector<void*> v1);

int StringToInt(std::string a);
int HexToDec(std::string a);