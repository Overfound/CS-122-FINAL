#include "Player.hpp"

Player::Player() {
	RemaningPieces = new List<Pieces>();
	TakenPieces = new List<Pieces>();
}
Player::~Player() {

}

List<Pieces>* Player::getTaken() {
	return TakenPieces;
}
List<Pieces>* Player::getPieces() {
	return RemaningPieces;
}

void Player::setTaken(List<Pieces>* taken) {
	TakenPieces = taken;
}
void Player::setPieces(List<Pieces>* pieces) {
	RemaningPieces = pieces;
}