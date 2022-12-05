#pragma once
#include "BlankPiece.hpp"

class Board {
public:
	Board();
	~Board();

	Board(Board& rhs);

	void getBoard(Pieces* returnArr[8][8]);
	void setBoard(Pieces* newBoard[8][8]);

	Pieces* MovePiece(Cordinate a, Cordinate b);

	void placePiece(Cordinate a, Pieces* b);

	void createBoard(std::string arr[8][8]);

private:
	Pieces* board[8][8];
};