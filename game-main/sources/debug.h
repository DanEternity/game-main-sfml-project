#pragma once

#include <iostream>
#include <string>

#ifndef DEBUG_H
#define DEBUG_H


void Log(std::string output);
void Logs(std::string output);
void Logp(const void * output);
void Logln(std::string output);

#endif // DEBUG_H
