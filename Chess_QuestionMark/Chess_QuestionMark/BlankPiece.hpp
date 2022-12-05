#pragma once
#include "Pieces.hpp"


class BlankPiece: public Pieces {
public:
	BlankPiece(std::string SideTWFB = "", Cordinate InitalLocation = NULL) {
		memcpy(this->movement, movements, sizeof(movement));
		this->setPieceSide(SideTWFB);
		this->setCurPos(InitalLocation);
		Identifer = "BLANK";
		Blank = true;
		canJump = false;
		genMoveList();
	}
	~BlankPiece() {

	}
	std::string specialFunction(Board* curboard, std::string marker = "") {
		return "";
	}
private:

	char movements[15][15] = { {'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','I','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'} };
	
};