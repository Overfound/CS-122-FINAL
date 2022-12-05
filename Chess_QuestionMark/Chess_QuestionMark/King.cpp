#include "King.hpp"
#include "Board.hpp"

std::string King::specialFunction(Board* curboard, std::string marker) {
	std::string returnval = "";
	Pieces* board[8][8];
	curboard->getBoard(board);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[j][i]->getPieceSide() != this->getPieceSide() && !board[j][i]->is_Blank()) {
				Node<Cordinate>* pcur = board[j][i]->getAvalibleMovement()->getHeadNode();
				while (pcur != nullptr) {
					if (pcur->getData() == this->curPos) {
						returnval = "incheck";
					}
					Node<Cordinate>* curSpot = this->getAvalibleMovement()->getHeadNode();
					Node<Cordinate>* prevSpot = nullptr;
					while (curSpot != nullptr) {
						if (curSpot->getData() == pcur->getData()) {
							if (prevSpot == nullptr) {
								this->getAvalibleMovement()->setHeadNode(curSpot->getNextNode());
							}
							else {
								prevSpot->setNextNode(curSpot->getNextNode());
							}
							Node<Cordinate>* fordelte = curSpot;
							curSpot = curSpot->getNextNode();
							delete(fordelte);
						}
						else {
							prevSpot = curSpot;
							curSpot = curSpot->getNextNode();
						}
					}
					pcur = pcur->getNextNode();
				}
			}
		}
	}
	return returnval;
}