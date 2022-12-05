#pragma once
#include "List.hpp"

class Board;

class Pieces {
public:
	Pieces(std::string SideTWFB = "", Cordinate InitalLocation = NULL);
	virtual~Pieces();
	
	bool is_Blank();

	virtual List<Cordinate>* canMoveTo(Board* curboard);
	
	std::string getIdentifer();

	void getMovement(char movement_graph[15][15]);

	std::string getPieceSide();
	void setPieceSide(std::string side);

	void setCurPos(Cordinate pos);
	Cordinate getCurPos();

	virtual std::string specialFunction(Board* curboard, std::string marker);

	virtual void genMoveList();
	
	List<Cordinate>* getAvalibleMovement();
	List<Cordinate>* getMoveList();



protected:

	char movement[15][15];
	std::string Identifer;
	bool Blank;
	bool canJump;


	Cordinate curPos;
	List<Cordinate>* MoveList = new List<Cordinate>();
	Cordinate* MoveListBase = new Cordinate();
	std::string PieceSide;
	List<Cordinate>* AvalibleMovement = new List<Cordinate>();
	

	
};