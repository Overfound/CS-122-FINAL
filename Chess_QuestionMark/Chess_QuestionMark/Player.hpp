#pragma once
#include "Board.hpp"


class Player{
public:
	Player();
	~Player();

	List<Pieces>* getTaken();
	List<Pieces>* getPieces();

	void setTaken(List<Pieces>* taken);
	void setPieces(List<Pieces>* pieces);
protected:
	List<Pieces>* TakenPieces = new List<Pieces>();
	List<Pieces>* RemaningPieces = new List<Pieces>();
};
