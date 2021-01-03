#ifndef L_PIECE_H
#define L_PIECE_H
#include<iostream>
#include"Block_Class.h"
using namespace std;

class L_Piece :
    public Block
{
private:
	friend class Board;
	
public:
	L_Piece();
	// _____________Completed_____________

	// complete pack for the movement of the piece :)
	void move(string, Board&);
	//_______________

	// MoveRight function
	void moveRight(Board&);
	void moveLeft(Board&);
	void moveDown(Board&);

	// Shifting PieceToBoard
	void shiftPieceToBoard(Board&);
	// ____________COMPLETED_______________________


	// check for movements
	bool canItMoveRight(Board&);
	bool canItMoveLeft(Board&);
	bool canItMoveDown(Board&);
	// ____________ COMPLETED_______

   //Last row per pohanch gya ha?
	bool lastRowPerPohanchGyaHa(Board&);
	// ____________ COMPLETED_______

	//rotation: 
	void rotation(Board&);
	bool canItRotate(Board&);
	// ____________ COMPLETED_______

};

#endif