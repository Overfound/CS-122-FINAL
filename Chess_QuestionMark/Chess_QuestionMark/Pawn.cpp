#include "Pawn.hpp"
#include "Board.hpp"

std::string Pawn::specialFunction(Board* curboard, std::string marker) {
	std::string returnval = "";
	Pieces* board[8][8];
	curboard->getBoard(board);
	if (marker == "move") {
		moves++;
		if (this->getPieceSide() == "white" && this->curPos.y == 7) {
			returnval = "SWAP";
		}
		else if ((this->getPieceSide() == "black") && this->curPos.y == 0) {
			returnval = "SWAP";
		}
	}
	return returnval;
}
List<Cordinate>* Pawn::canMoveTo(Board* curboard) {
	List<Cordinate>* okMove = new List<Cordinate>;
	
	Pieces* board[8][8];
	curboard->getBoard(board);
	if (curPos.y + 1 < 8 && this->getPieceSide() == "white" && board[curPos.x][curPos.y + 1]->is_Blank()) {
		okMove->insertFront(Cordinate(this->curPos.x, this->curPos.y+1));
		if (curPos.y + 2 < 8 && moves < 1 && board[curPos.x][curPos.y + 2]->is_Blank()) {
			okMove->insertFront(Cordinate(this->curPos.x, this->curPos.y+2));
		}
	}
	else if (curPos.y - 1 >= 0 && this->getPieceSide() == "black" && board[curPos.x][curPos.y - 1]->is_Blank()) {
		okMove->insertFront(Cordinate(this->curPos.x, this->curPos.y - 1));
		if (curPos.y - 2 >= 0 && moves < 1 && board[curPos.x][curPos.y - 2]->is_Blank()) {
			okMove->insertFront(Cordinate(this->curPos.x, this->curPos.y - 2));
		}
	}
	if (this->getPieceSide() == "white") {
		if (curPos.y + 1 < 8 && curPos.x +1 < 8 && board[curPos.x + 1][curPos.y + 1]->getPieceSide() == "black") {
			okMove->insertFront(Cordinate(this->curPos.x + 1, this->curPos.y + 1));
		}else if (curPos.y + 1 < 8 && curPos.x - 1 >= 0 && board[curPos.x - 1][curPos.y + 1]->getPieceSide() == "black") {
			okMove->insertFront(Cordinate(this->curPos.x - 1, this->curPos.y + 1));
		}
	}
	else if (this->getPieceSide() == "black") {
		if (curPos.y >= 0 && curPos.x +1 < 8 && board[curPos.x + 1][curPos.y - 1]->getPieceSide() == "white") {
			okMove->insertFront(Cordinate(this->curPos.x + 1, this->curPos.y - 1));
		}
		else if (curPos.y -1 >= 0 && curPos.x - 1 >= 0 && board[curPos.x - 1][curPos.y - 1]->getPieceSide() == "white") {
			okMove->insertFront(Cordinate(this->curPos.x - 1, this->curPos.y - 1));
		}
	}
	this->AvalibleMovement = okMove;
	return okMove;
}