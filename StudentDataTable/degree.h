#ifndef DEGREE_H
#define DEGREE_H
#include <iostream>
#include <string>

using namespace std;

enum class DegreeType {SECURITY, NETWORK, SOFTWARE}; //Three different degrees.

static const std::string DegreeTypeStrings[] = { "SECURITY","NETWORK","SOFTWARE" }; //assigns string based on number called in enum.

#endif


