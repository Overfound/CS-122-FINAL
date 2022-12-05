#pragma once
#include "Board.hpp"
#include "Pawn.hpp"
#include "Bishop.hpp"
#include "BlankPiece.hpp"
#include "King.hpp"
#include "Kinight.hpp"
#include "LongLegPawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "TallKnight.hpp"


Board::Board() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new BlankPiece();
		}
	}
}
Board::~Board() {
}
Board::Board(Board& rhs) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			this->board[i][j] = rhs.board[i][j];
		}
	}
}
void Board::getBoard(Pieces* returnArr[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			returnArr[i][j] = this->board[i][j];
		}
	}
}
void Board::setBoard(Pieces* newBoard[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			this->board[i][j] = newBoard[i][j];
		}
	}
}

Pieces* Board::MovePiece(Cordinate a, Cordinate b) {
	Pieces* temp = board[b.x][b.y];
	board[b.x][b.y] = board[a.x][a.y];
	board[b.x][b.y]->setCurPos(b);
	board[a.x][a.y] = new BlankPiece();
	return temp;
}
void Board::placePiece(Cordinate a, Pieces* b) {
	this->board[a.x][a.y] = b;
	b->setCurPos(a);
}
void Board::createBoard(std::string arr[8][8]){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::stringstream ss(arr[i][j]);
			std::string side;
			std::string piece;
			std::getline(ss, side, ',');
			std::getline(ss, piece, ',');
			if (piece == "pawn") {
				this->placePiece(Cordinate(j, i), new Pawn(side));
			}else if (piece == "bishop") {
				this->placePiece(Cordinate(j, i), new Bishop(side));
			}
			else if (piece == "king") {
				this->placePiece(Cordinate(j, i), new King(side));
			}
			else if (piece == "knight") {
				this->placePiece(Cordinate(j, i), new Knight(side));
			}
			else if (piece == "LLpawn") {
				this->placePiece(Cordinate(j, i), new LongPawn(side));
			}
			else if (piece == "queen") {
				this->placePiece(Cordinate(j, i), new Queen(side));
			}
			else if (piece == "rook") {
				this->placePiece(Cordinate(j, i), new Rook(side));
			}
			else if (piece == "Tknight") {
				this->placePiece(Cordinate(j, i), new TallKnight(side));
			}
		}
	}
}