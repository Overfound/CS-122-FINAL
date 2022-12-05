#include "Pieces.hpp"


class Knight : public Pieces {
public:
	Knight(std::string SideTWFB = "", Cordinate InitalLocation = NULL) {
		memcpy(this->movement, movements, sizeof(movement));
		this->setPieceSide(SideTWFB);
		this->setCurPos(InitalLocation);
		Identifer = "Knight";
		Blank = false;
		canJump = true;
		genMoveList();
	}
	~Knight() {

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
							,{'`','`','`','`','`','`','X','`','X','`','`','`','`','`','`'}
							,{'`','`','`','`','`','X','`','`','`','X','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','I','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','X','`','`','`','X','`','`','`','`','`'}
							,{'`','`','`','`','`','`','X','`','X','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'} };
	

};