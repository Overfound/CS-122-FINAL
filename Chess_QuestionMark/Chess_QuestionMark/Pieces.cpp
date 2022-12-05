#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

Pieces::Pieces(std::string SideTWFB, Cordinate InitalLocation) {
	//genMoveList();
	this->PieceSide = SideTWFB;
	this->curPos = InitalLocation;
}
Pieces::~Pieces() {

}

bool Pieces::is_Blank() {
	return Blank;
}

List<Cordinate>* Pieces::canMoveTo(Board* curboard) {
	List<Cordinate>*  okMove = new List<Cordinate>;
	Node<Cordinate>* pcur = MoveList->getHeadNode();
	int xdiff = curPos.x - MoveListBase->x;
	int ydiff = curPos.y - MoveListBase->y;
	Pieces* board[8][8];
	curboard->getBoard(board);
	while (pcur != nullptr) {
		if (((pcur->getData()->x + xdiff < 8 && pcur->getData()->x + xdiff >= 0) && (pcur->getData()->y + ydiff < 8 && pcur->getData()->y + ydiff >= 0) && board[pcur->getData()->x + xdiff][pcur->getData()->y + ydiff]->getPieceSide() != this->getPieceSide())) {
			int goal_Diffx = (pcur->getData()->x + xdiff) - curPos.x;
			int goal_Diffy = (pcur->getData()->y + ydiff) - curPos.y;
			if (!canJump) {
				float slope = 0;
				bool colision = false;
				int dist;
				std::string market = "";
				if (goal_Diffx == 0) {
					dist = goal_Diffy;
					market = "vertical";
				}
				else if(goal_Diffy == 0) {
					dist = goal_Diffx;
					market = "horizontal";
				}
				else {
					dist = round(sqrt((goal_Diffx * goal_Diffx) + (goal_Diffy * goal_Diffy)));
					market = "diag";
				}
				

				for (int i = 0; i < abs(dist); i++) {
					int curptx = curPos.x;
					int curpty = curPos.y;
					int xsn = i;
					int ysn = i;
					if (goal_Diffx < 0) {
						xsn = -xsn;
					}
					if (goal_Diffy < 0) {
						ysn = -ysn;
					}
					if (market == "diag") {
						curptx = xsn + curPos.x;
						curpty = ysn + curPos.y;
					}
					else if (market == "horizontal") {
						curptx = xsn + curPos.x;
					}
					else if (market == "vertical") {
						curpty = ysn + curPos.y;
					}
					

					if (!(curptx >= 8 || curpty >= 8) && !(curptx < 0 || curpty < 0)) {

						if (!((curptx == (pcur->getData()->x + xdiff) && curpty == (pcur->getData()->y + ydiff)) || (curptx == curPos.x && curpty == curPos.y))) {
							if (!board[curptx][curpty]->is_Blank()) {
								colision = true;
							}
						}
					}
					i = abs(i);

				}
				if (!colision) {
					okMove->insertFront(Cordinate(pcur->getData()->x + xdiff, pcur->getData()->y + ydiff));
				}
			}
			else {
				okMove->insertFront(Cordinate(pcur->getData()->x + xdiff, pcur->getData()->y + ydiff));
			}

			//okMove->insertFront(Cordinate(pcur->getData()->x + xdiff, pcur->getData()->y + ydiff));
		}
		pcur = pcur->getNextNode();
	}
	//delete(this->AvalibleMovement);
	this->AvalibleMovement = okMove;
	return okMove;
}

std::string Pieces::getIdentifer() {
	return Identifer;
}

void Pieces::getMovement(char movement_graph[15][15]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			movement_graph[i][j] = this->movement[i][j];
		}
	}
}
void Pieces::genMoveList() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (movement[j][i] == 'I') {
				MoveListBase = new Cordinate(i, j);
			}
			else if (movement[j][i] == 'X') {
				MoveList->insertFront(Cordinate(i, j));
			}
		}
	}
}
std::string Pieces::specialFunction(Board* curboard, std::string marker) {
	return "";
}

std::string Pieces::getPieceSide() {
	return PieceSide;
}
void Pieces::setPieceSide(std::string side) {
	PieceSide = side;
}
void Pieces::setCurPos(Cordinate pos) {
	this->curPos = pos;
}
Cordinate Pieces::getCurPos() {
	return curPos;
}
List<Cordinate>* Pieces::getAvalibleMovement() {
	return AvalibleMovement;
}
List<Cordinate>* Pieces::getMoveList() {
	return MoveList;
}