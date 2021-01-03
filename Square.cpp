#include "Square.h"
#include"Board.h"
using namespace std;

Square::Square() {
	xPos = 0;
	yPos = 0;

	piece = new string[4];
	piece[0] = char(137);
	piece[1] = char(137);
	piece[2] = char(137);
	piece[3] = char(137);

	countForRotation = 0;
}

void Square::shiftPieceToBoard(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;

	b.board[x][y] = piece[0];
	b.board[x][y + 1] = piece[1];
	b.board[x + 1][y] = piece[2];
	b.board[x + 1][y + 1] = piece[3];
}
//Piece is shifted to the board :)

// Bool functions :L
bool Square::canItMoveLeft(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	//[] [] 
	//[] []
	if (countForRotation == 0) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y - 1] == " ")
			)
			check = true;
		else return false;
	}
	return check;
}
bool Square::canItMoveRight(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	//[] [] 
	//[] []
	if (countForRotation == 0) {
		if ((b.board[x + 0][y + 2] == " ") &&
			(b.board[x + 1][y + 2] == " ")
			)
			check = true;
		else return false;
	}
	return check;
}
bool Square::canItMoveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	bool check = true;
	if (countForRotation == 0) {
		if (b.board[x + 2][y + 0] == " "
			&&
			b.board[x + 2][y + 1] == " "
			) {
			check = true;
		}
		else return false;
	}
	
	return check;
}
bool Square::lastRowPerPohanchGyaHa(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if ((x + 1) == (b.fieldR - 1))
			return true;

		else return false;
	}
	
}

// Movement functions :-

// MoveLeft function
void Square::moveLeft(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y - 1] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 1] = " ";
			b.board[x + 1][y + 1] = " ";

			yPos--;	//updating the yPosition ('_')
			b.draw();
		}

	}
	

}
// MoveRight function
void Square::moveRight(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x][y+2] = char(137);
			b.board[x + 1][y + 2] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y + 0] = " ";

			yPos++; //updating the yPosition ('_')

			b.draw();
		}

	}
	

}
// MoveDown function 
void Square::moveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;

	if (lastRowPerPohanchGyaHa(b)) {
		return;
	}
	else {
		if (countForRotation == 0 && canItMoveDown(b)) {
			
			b.board[x + 2][y] = char(137);
			b.board[x + 2][y + 1] = char(137);

			b.board[x][y] = " ";
			b.board[x][y + 1] = " ";
			
			//b.draw();
			xPos++;
			system("cls");
			b.draw();
		}
	}
}

// Movement :-

void Square::move(string ch, Board& b) {

	if (ch == "d") {
		moveRight(b);
	}
	// left movement
	if (ch == "a") {
		moveLeft(b);
	}
	else if (ch == "s") {
		rotation(b);
	}
	else
		moveDown(b);

}

// No Rotations :!
bool Square::canItRotate(Board& b) {
	
	return false;
	// Done
	//-------------------------------
}
void Square::rotation(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (!(canItRotate(b))) {
		return;
	}

}

//----------------------------------------------------------\\
//                    COMPLETED                              \\
// -----------------------------------------------------------\\
