#include "Cordinate.hpp"
Cordinate::Cordinate(int x, int y)
{
	this->x = x;
	this->y = y;
}

Cordinate::~Cordinate()
{
}
Cordinate::Cordinate(const Cordinate& rhs) {
	this->x = rhs.x;
	this->y = rhs.y;
}
std::ostream& operator<< (std::ostream& lhs, Cordinate& rhs) {
	return lhs << rhs.x << "," << rhs.y << std::endl;
}
bool operator== (Cordinate& lhs, Cordinate& rhs) {
	if (lhs.x == rhs.x && lhs.y == rhs.y) {
		return true;
	}
	else {
		return false;
	}
}
bool operator== (Cordinate* lhs, Cordinate& rhs) {
	if (lhs->x == rhs.x && lhs->y == rhs.y) {
		return true;
	}
	else {
		return false;
	}
}