#include "Queen.hpp"

Queen::Queen(std::string SideTWFB, Cordinate InitalLocation) {
	memcpy(this->movement, movements, sizeof(movement));
	this->setPieceSide(SideTWFB);
	this->setCurPos(InitalLocation);
	Identifer = "Queen";
	Blank = false;
	canJump = false;
	genMoveList();
}
Queen::~Queen() {

}
