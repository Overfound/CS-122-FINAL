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
#include "Player.hpp"
#include "Test.hpp"

void pieceMoveTest() {
	Queen* queen = new Queen("white");
	Board* game = new Board();

	game->placePiece(Cordinate(4, 4), queen);
	game->placePiece(Cordinate(4, 5), new Pawn("black"));
	game->placePiece(Cordinate(4, 3), new Pawn("black"));
	game->placePiece(Cordinate(5, 4), new Pawn("black"));
	game->placePiece(Cordinate(3, 3), new Pawn("black"));
	//game->placePiece(Cordinate(5, 5), new Pawn("black"));
	//game->placePiece(Cordinate(3, 5), new Pawn("black"));
	//game->placePiece(Cordinate(5, 3), new Pawn("black"));
	game->placePiece(Cordinate(1, 4), new Pawn("black"));
	//TESTING


	Pieces* board[8][8];
	game->getBoard(board);

	std::cout << board[4][4]->getIdentifer() << std::endl;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|" << board[j][i]->getIdentifer();
		}
		std::cout << "\n" << "---------------------------" << std::endl;
	}

	List<Cordinate>* arr = queen->canMoveTo(game);
	queen->specialFunction(game, "move");

	char testboard[8][8] = { {'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'}, {'-','-','-','-','-','-','-','-'} };
	testboard[queen->getCurPos().x][queen->getCurPos().y] = 'Y';


	Node<Cordinate>* pcur = queen->getAvalibleMovement()->getHeadNode();
	while (pcur != nullptr) {
		std::cout << pcur->getData()->x << "," << pcur->getData()->y << std::endl;
		testboard[pcur->getData()->x][pcur->getData()->y] = 'O';
		pcur = pcur->getNextNode();
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|" << testboard[j][i];
		}
		std::cout << "\n" << "---------------------------" << std::endl;
	}
}
void TextGameTest() {
	//Create Game:

	//create players
	Player white;
	Player black;

	//create a sample game board manualy (hopefully would be made with board creator)
	std::string gameset[8][8] = { {"white,rook","white,bishop","white,knight","white,king","white,rook","white,knight","white,bishop","white,rook"},
		{"white,pawn","white,pawn","white,rook","black,queen","white,queen","white,bishop","white,pawn","white,pawn"},
		{" "},
		{" "} ,
		{" "} ,
		{" "},
		{"black,pawn","black,pawn","black,pawn","black,pawn","black,pawn","black,pawn","black,pawn","black,pawn" },
		{"black,rook","black,bishop","black,knight","black,king","black,rook","black,knight","black,bishop","black,rook"}
		 };
	//set the board
	Board* game = new Board();
	game->createBoard(gameset);
	Pieces* board[8][8];
	game->getBoard(board);
	
	//print board
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|" << board[j][i]->getIdentifer();
		}
		std::cout << "\n" << "---------------------------" << std::endl;
	}
	std::cout << "\n \n \n \n \n \n";

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|" << board[j][i]->getPieceSide();
		}
		std::cout << "\n" << "---------------------------" << std::endl;
	}

	//generate inital moves and add each piece to player
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[j][i]->getPieceSide() == "white") {
				white.getPieces()->insertFront(*board[j][i]);
			}
			else if (board[j][i]->getPieceSide() == "balck") {
				black.getPieces()->insertFront(*board[j][i]);
			}
			board[j][i]->canMoveTo(game);
			board[j][i]->specialFunction(game,"");
		}
	}

	bool gamerun = true;
	bool playerturn = true;
	//game loop
	while (gamerun) {
		if (playerturn) {
			//get updated board
			game->getBoard(board);
			//print Board
			printBoard(game);

			//generate moves and do first time special checks
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					board[j][i]->canMoveTo(game);
					std::string marker = board[j][i]->specialFunction(game, "genmove");
					if (marker == "incheck" && board[j][i]->getPieceSide() == "white") {
						//notify player they are in check and have to move king or risk loosing
						std::cout << "You are in check move king or you might fail" << std::endl;
					}
				}
			}
			
		
			//promnt user on what piece they want to pick
			std::string x;
			std::string y;
			bool avalible = true;
			while (avalible) {
				std::cout << "What piece do you want to move (x,y)" << std::endl;
				std::string input;
				std::cin >> input;
				std::stringstream ss(input);
				std::getline(ss, x, ',');
				std::getline(ss, y, ',');
				Cordinate piece(stoi(x), stoi(y));
				if (board[piece.x][piece.y]->getPieceSide() == "white") {
					avalible = false;
				}
				else {
					std::cout << "You Can Not Pick A Piece Not On Your Side" << std::endl;
				}
			}
			Cordinate selected(stoi(x), stoi(y));

			//take user input and display possible movent options
			bool quit = false;
			std::cout << "   0     1     2     3     4     5     6     7\n";
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					quit = false;
					Node<Cordinate>* pcur = board[stoi(x)][stoi(y)]->getAvalibleMovement()->getHeadNode();
					while (pcur != nullptr) {
						if (pcur->getData()->x == j && pcur->getData()->y == i) {
							std::cout << "|0000000";
							quit = true;
						}
						pcur = pcur->getNextNode();
					}
					if (!quit) {
						std::cout << "|" << board[j][i]->getIdentifer();
					}
					
				}
				std::cout << "|" << i << "\n" << "-------------------------------------------" << std::endl;
			}

			//promt user if they want to move that piece if so where
			std::cout << "Do you want to move this piece y/n" << std::endl;
			std::string read;
			std::cin >> read;
			if (read == "y") {
				avalible = true;
				std::string x;
				std::string y;
				while (avalible) {
					std::cout << "Where do you want to move to)" << std::endl;
					std::string input;
					std::cin >> input;
					std::stringstream ss(input);
					std::getline(ss, x, ',');
					std::getline(ss, y, ',');
					Cordinate piece(stoi(x), stoi(y));

					//checking if thats an avalible piece
					int count = 0;
					Node<Cordinate>* pcur = board[selected.x][selected.y]->getAvalibleMovement()->getHeadNode();
					while (pcur != nullptr) {
						if (pcur->getData()->x == piece.x && pcur->getData()->y == piece.y) {
							count++;
						}
						pcur = pcur->getNextNode();
					}
					if (count > 0) {
						avalible = false;
					}
					else {
						std::cout << "Pick an avalible location" << std::endl;
					}
				}


				//move piece
				std::string moveval = "";
				Pieces* temp = game->MovePiece(selected, Cordinate(stoi(x), stoi(y)));
				moveval = board[selected.x][selected.y]->specialFunction(game,"move");
				if (!temp->is_Blank()) {
					black.getPieces()->insertFront(*temp);
				}
				if (temp->getIdentifer() == "king") {
					gamerun = false;
					std::cout << "GAME OVER" << std::endl;
				}
				if (moveval == "SWAP") {
					game->placePiece(Cordinate(stoi(x), stoi(y)), new Queen("white"));
				}

				playerturn = false;
				printBoard(game);
			}

		}
		else {
		//get updated board
		game->getBoard(board);
		//print Board
		printBoard(game);

		//generate moves and do first time special checks
		for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					board[j][i]->canMoveTo(game);
					std::string marker = board[j][i]->specialFunction(game, "genmove");
					if (marker == "incheck" && board[j][i]->getPieceSide() == "black") {
						//notify player they are in check and have to move king or risk loosing
						std::cout << "You are in check move king or you might fail" << std::endl;
					}
				}
			}

		//promnt user on what piece they want to pick
		std::string x;
		std::string y;
		bool avalible = true;
		while (avalible) {
			std::cout << "What piece do you want to move (x,y)" << std::endl;
			std::string input;
			std::cin >> input;
			std::stringstream ss(input);
			std::getline(ss, x, ',');
			std::getline(ss, y, ',');
			Cordinate piece(stoi(x), stoi(y));
			if (board[piece.x][piece.y]->getPieceSide() == "black") {
				avalible = false;
			}
			else {
				std::cout << "You Can Not Pick A Piece Not On Your Side" << std::endl;
			}
		}
		Cordinate selected(stoi(x), stoi(y));

		//take user input and display possible movent options
		bool quit = false;
		std::cout << "   0     1     2     3     4     5     6     7\n";
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				quit = false;
				Node<Cordinate>* pcur = board[stoi(x)][stoi(y)]->getAvalibleMovement()->getHeadNode();
				while (pcur != nullptr) {
					if (pcur->getData()->x == j && pcur->getData()->y == i) {
						std::cout << "|0000000";
						quit = true;
					}
					pcur = pcur->getNextNode();
				}
				if (!quit) {
					std::cout << "|" << board[j][i]->getIdentifer();
				}

			}
			std::cout << "|" << i << "\n" << "-------------------------------------------" << std::endl;
		}

		//promt user if they want to move that piece if so where
		std::cout << "Do you want to move this piece y/n" << std::endl;
		std::string read;
		std::cin >> read;
		if (read == "y") {
			avalible = true;
			std::string x;
			std::string y;
			while (avalible) {
				std::cout << "Where do you want to move to)" << std::endl;
				std::string input;
				std::cin >> input;
				std::stringstream ss(input);
				std::getline(ss, x, ',');
				std::getline(ss, y, ',');
				Cordinate piece(stoi(x), stoi(y));

				//checking if thats an avalible piece
				int count = 0;
				Node<Cordinate>* pcur = board[selected.x][selected.y]->getAvalibleMovement()->getHeadNode();
				while (pcur != nullptr) {
					if (pcur->getData()->x == piece.x && pcur->getData()->y == piece.y) {
						count++;
					}
					pcur = pcur->getNextNode();
				}
				if (count > 0) {
					avalible = false;
				}
				else {
					std::cout << "Pick an avalible location" << std::endl;
				}
			}


			//move piece
			std::string moveval = "";
			Pieces* temp = game->MovePiece(selected, Cordinate(stoi(x), stoi(y)));
			moveval = board[selected.x][selected.y]->specialFunction(game, "move");
			if (!temp->is_Blank()) {
				white.getPieces()->insertFront(*temp);
			}
			if (temp->getIdentifer() == "king") {
				gamerun = false;
				std::cout << "GAME OVER" << std::endl;
			}
			if (moveval == "SWAP") {
				game->placePiece(selected, new Queen("white"));
			}

			playerturn = true;
			printBoard(game);
		}

		}
	}
}
void printBoard(Board* inpu) {
	Pieces* board[8][8];
	inpu->getBoard(board);
	std::cout << "   0     1     2     3     4     5     6     7\n";
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cout << "|" << board[j][i]->getIdentifer();
		}
		std::cout << "|" <<  i << "\n" << "-------------------------------------------" << std::endl;
	}
}

//Piece Blocking Curr
//bool colision = false;
//if (goal_Diffx == 0) {
//	for (int i = 1; i < std::abs(goal_Diffx); i++) {
//		if (goal_Diffy < 0) {
//			if (!board[curPos.x][curPos.y - i]->is_Blank()) {
//				colision = true;
//			}
//		}
//		else if (goal_Diffy > 0) {
//			if (!board[curPos.x][curPos.y + i]->is_Blank()) {
//				colision = true;
//			}
//		}
//	}
//}
//if (goal_Diffy == 0) {
//	for (int i = 1; i < std::abs(goal_Diffy); i++) {
//		if (goal_Diffx < 0) {
//			if (!board[curPos.x - i][curPos.y]->is_Blank()) {
//				colision = true;
//			}
//		}
//		else if (goal_Diffx > 0) {
//			if (!board[curPos.x + i][curPos.y]->is_Blank()) {
//				colision = true;
//			}
//		}
//	}
//}
//if (abs(goal_Diffx) == abs(goal_Diffy)) {
//	for (int i = 1; i < std::abs(goal_Diffy); i++) {
//		int xinc = 0;
//		int yinc = 0;
//		if (goal_Diffx < 0) {
//			xinc = -i;
//		}
//		else if (goal_Diffx > 0) {
//			xinc = i;
//		}
//		if (goal_Diffy < 0) {
//			yinc = -i;
//		}
//		else if (goal_Diffy > 0) {
//			yinc = i;
//		}
//		if (!board[curPos.x + xinc][curPos.y + yinc]->is_Blank()) {
//			colision = true;
//		}
//	}
//}
//if (!colision) {
//	okMove->insertFront(Cordinate(pcur->getData()->x + xdiff, pcur->getData()->y + ydiff));
//}