#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
class Cordinate
{
public:
	Cordinate(int x = 0, int y = 0);
	~Cordinate();

	Cordinate(const Cordinate& rhs);

	int x;
	int y;
private:
	
};

std::ostream& operator<< (std::ostream& lhs, Cordinate& rhs);
bool operator== (Cordinate& lhs, Cordinate& rhs);
bool operator== (Cordinate* lhs, Cordinate& rhs);