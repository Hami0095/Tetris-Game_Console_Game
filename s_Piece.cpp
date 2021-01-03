#include "s_Piece.h"


s_Piece::s_Piece() {
	piece = new string [4];
	piece[0] = char(137);
	piece[1] = char(137);
	piece[2] = char(137);
	piece[3] = char(137);

	countForRotation = 0;
}

void s_Piece::shiftPieceToBoard(Board &b) {
	int x = xPos + 1;
	int y = yPos + 1;
	b.board[x + 0][y + 0] = piece[0];
	b.board[x][y + 1] = piece[1];
	b.board[x+1][y+1] = piece[2];
	b.board[x+1][y+2] = piece[3];

}

// BOOL FUNCTION______________________________________
bool s_Piece::canItMoveLeft(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	//[]+
	//[]+
	//[]+
	//[]+
	if (countForRotation == 0) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y + 0] == " ") 
			)
			check = true;
		else return false;
	}
	//[]++++
	else if (countForRotation == 1) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y - 1] == " ")&&
			(b.board[x + 2][y - 0] == " ")
			)
			check = true;
		else return false;
	}
	return check;
}
bool s_Piece::canItMoveRight(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if ((b.board[x + 0][y + 2] == " ") &&
			(b.board[x + 1][y + 3] == " ")
			)
			check = true;
		else return false;
	}
	//++++[]
	else if (countForRotation == 1) {
		if ((b.board[x + 0][y + 1] == " ")&&
			(b.board[x + 1][y + 2] == " ")&&
			(b.board[x + 2][y + 2] == " ")
			)
			check = true;
		else return false;
	}
	return check;
}
bool s_Piece::canItMoveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	bool check = true;
	if (countForRotation == 0) {
		if ((b.board[x + 1][y + 0] == " ") &&
			(b.board[x + 2][y + 2] == " ") && 
			(b.board[x + 2][y + 1] == " ")
			) 
		{
			check = true;
		}
		else return false;
	}
	if (countForRotation == 1) {
		if ((b.board[x + 2][y + 0] == " ") &&
			(b.board[x + 3][y + 1] == " ") 
			) 
		{
			check = true;
		}
		else return false;
	}


	return check;
}
bool s_Piece::lastRowPerPohanchGyaHa(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if ((x + 1) == (b.fieldR - 1))
			return true;

		else return false;
	}
	if (countForRotation == 1) {
		if ((x + 2) == (b.fieldR - 1))
			return true;

		else return false;
	}
	return false;
}

// MOVEMENT FUNCTIONS_________________________________
// MoveRight function
void s_Piece::moveRight(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 2] = char(137);
			b.board[x + 1][y + 3] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y + 1] = " ";

			yPos++; //updating the yPosition ('_')

			b.draw();
		}

	}
	if (countForRotation == 1) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 1] = char(137);
			b.board[x + 1][y + 2] = char(137);
			b.board[x + 2][y + 2] = char(137);

			// clean peechy walla gand:)

			b.board[x][y] = " ";
			b.board[x + 1][y] = " ";
			b.board[x + 2][y + 1] = " ";

			yPos++; //updating the yPosition ('_')

			b.draw();
		}
	}
}
// MoveLeft function
void s_Piece::moveLeft(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y + 0] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 1] = " ";
			b.board[x + 1][y + 2] = " ";


			yPos--;	//updating the yPosition ('_')
			b.draw();
		}

	}
	if (countForRotation == 1) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y - 1] = char(137);
			b.board[x + 2][y - 0] = char(137);
			// clean peechy walla gand:)

			b.board[x][y] = " ";
			b.board[x + 1][y + 1] = " ";
			b.board[x + 2][y + 1] = " ";

			yPos--;	//updating the yPosition ('_')

			b.draw();
		}

	}

}
// MoveDown function 
void s_Piece::moveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;

	if (lastRowPerPohanchGyaHa(b)) {
		return;
	}
	else {
		if (countForRotation == 0 && canItMoveDown(b)) {
			
			// naii jaga per placements kro :¬
			b.board[x + 1][y + 0] = char(137);
			b.board[x + 2][y + 1] = char(137);
			b.board[x + 2][y + 2] = char(137);
			
			//pichla gand saaf kroo:¬
			b.board[x][y] = " ";
			b.board[x + 0][y + 1] = " ";
			b.board[x + 1][y + 2] = " ";

			xPos++; // xPos ko update krdia
			system("cls");
			b.draw();
		    	//b.draw();
			
		}
		if (countForRotation == 1 && canItMoveDown(b)) {
			
			b.board[x + 2][y + 0] = char(137);
			b.board[x + 3][y + 1] = char(137);
			
			// cleaning pichla gand :¬
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y + 1] = " ";

			xPos++;
			//b.draw();
			system("cls");
			b.draw();
		}
	}
}

// Movement :-
void s_Piece::move(string ch, Board& b) {

	if (ch == "d") {
		moveRight(b);
	}
	// left movement
	else if (ch == "a") {
		moveLeft(b);
	}
	else if (ch == "s") {
		rotation(b);
	}
	else {
		moveDown(b);
	}
}

bool s_Piece::canItRotate(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (b.board[x + 1][y + 0] != " " ||
			b.board[x + 2][y + 1] != " "
			)
			return false;
		else return true;
	}
	if (countForRotation == 1) {
		if (b.board[x + 0][y + 1] != " " ||
			b.board[x + 1][y + 2] != " "
			)
			return false;
		else return true;
	}

	// Done
	//-------------------------------
}
void s_Piece::rotation(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0 && (canItRotate(b))) {
		b.board[x + 1][y + 0] = char(137);
		b.board[x + 2][y + 1] = char(137);
		
		// cleaning pichla gand:¬
		b.board[x + 0][y + 1] = " ";
		b.board[x + 1][y + 2] = " ";
		
		countForRotation = 1;
		b.draw();
	}
	else if (countForRotation == 1 && (canItRotate(b))) {

		b.board[x + 0][y + 1] = char(137);
		b.board[x + 1][y + 2] = char(137);
		
		// cleaning pichla gand:¬
		b.board[x + 1][y + 0] = " ";
		b.board[x + 2][y + 1] = " ";

		countForRotation = 0;
		b.draw();
	}
}
//----------------------------------------------------------\\
//                    COMPLETED                              \\
// -----------------------------------------------------------\\



