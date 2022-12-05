#include "Pieces.hpp"


class Pawn : public Pieces {
public:
	Pawn(std::string SideTWFB = "", Cordinate InitalLocation = NULL) {
		memcpy(this->movement, movements, sizeof(movement));
		this->setPieceSide(SideTWFB);
		this->setCurPos(InitalLocation);
		Identifer = "Pawn";
		Blank = false;
		canJump = false;
		genMoveList();
	}
	~Pawn() {

	}
	std::string specialFunction(Board* curboard,std::string marker) override;
	List<Cordinate>* canMoveTo(Board* curboard) override;
private:

	char movements[15][15] = { {'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','X','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','I','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'}
							,{'`','`','`','`','`','`','`','`','`','`','`','`','`','`','`'} };

	int moves;

};