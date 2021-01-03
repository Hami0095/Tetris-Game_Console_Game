#include "T_Piece.h"

T_Piece::T_Piece() {
	piece = new string[4];
	piece[0] = char(137);
	piece[1] = char(137);
	piece[2] = char(137);
	piece[3] = char(137);

	countForRotation = 0;
}

void T_Piece::shiftPieceToBoard(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	b.board[x + 0][y + 0] = piece[0];
	b.board[x + 1][y + 0] = piece[1];
	b.board[x + 1][y + 1] = piece[2];
	b.board[x + 2][y + 0] = piece[3];
	
}

// BOOL FUNCTION______________________________________
bool T_Piece::canItMoveLeft(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	//[]+
	//[]+
	//[]+
	// count 0 :
	if (countForRotation == 0) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y - 1] == " ") &&
			(b.board[x + 2][y - 1] == " ")
			)
			check = true;
		else return false;
	}
	//[]++++
	// count 1 :
	else if (countForRotation == 1) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y - 0] == " ")
			)
			check = true;
		else return false;
	}
	// count 2 :
	else if (countForRotation == 2) {
		if ((b.board[x + 0][y - 1] == " ") &&
			(b.board[x + 1][y - 2] == " ") &&
			(b.board[x + 2][y - 1] == " ")
			)
			check = true;
		else return false;
	}
	// count 3 : 
	else if (countForRotation == 3) {
		if ((b.board[x + 0][y - 2] == " ") &&
			(b.board[x - 1][y - 1] == " ")
			)
			check = true;
		else return false;
	}


	return check;
}
bool T_Piece::canItMoveRight(Board& b) {
	bool check = true;
	int x = xPos + 1;
	int y = yPos + 1;
	// count 0 :
	if (countForRotation == 0) {
		if ((b.board[x + 0][y + 1] == " ") &&
			(b.board[x + 1][y + 2] == " ") &&
			(b.board[x + 2][y + 1] == " ")
			)
			check = true;
		else return false;
	}
	//++++[]
	// count 1 :
	else if (countForRotation == 1) {
		if ((b.board[x + 0][y + 3] == " ") &&
			(b.board[x + 1][y + 2] == " ")
			)
			check = true;
		else return false;
	}
	// count 2 : 
	else if (countForRotation == 2) {
		if ((b.board[x + 0][y + 1] == " ") &&
			(b.board[x + 1][y + 1] == " ") &&
			(b.board[x + 2][y + 1] == " ")
			)
			check = true;
		else return false;
	}
	// count 3 : 
	else if (countForRotation == 3) {
		if ((b.board[x + 0][y + 2] == " ") &&
			(b.board[x - 1][y + 1] == " ")
			)
			check = true;
		else return false;
	}

	return check;
}
bool T_Piece::canItMoveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	bool check = true;
	// count 0 : 
	if (countForRotation == 0) {
		if ((b.board[x + 3][y + 0] == " ") &&
			(b.board[x + 2][y + 1] == " ")
			)
		{
			check = true;
		}
		else return false;
	}
	// count 1 :
	else if (countForRotation == 1) {
		if ((b.board[x + 1][y + 0] == " ") &&
			(b.board[x + 2][y + 1] == " ") &&
			(b.board[x + 1][y + 2] == " ")
			)
		{
			check = true;
		}
		else return false;
	}
	// count 2 :
	else if (countForRotation == 2) {
		if ((b.board[x + 3][y + 0] == " ") &&
			(b.board[x + 2][y - 1] == " ")
			)
		{
			check = true;
		}
		else return false;
	}
	// count 3 :
	else if (countForRotation == 3) {
		if ((b.board[x + 1][y + 0] == " ") &&
			(b.board[x + 1][y - 1] == " ") &&
			(b.board[x + 1][y + 1] == " ")
			)
		{
			check = true;
		}
		else return false;
	}

	return check;
}
bool T_Piece::lastRowPerPohanchGyaHa(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	// count 0 :
	if (countForRotation == 0) {
		if ((x + 2) == (b.fieldR - 1))
			return true;

		else return false;
	}
	// count 1 :
	else if (countForRotation == 1) {
		if ((x + 1) == (b.fieldR - 1))
			return true;

		else return false;
	}
	// count 2 :
	else if (countForRotation == 2) {
		if ((x + 3) == (b.fieldR - 1))
			return true;

		else return false;
	}
	// count 3 :
	else if (countForRotation == 3) {
		if ((x + 0) == (b.fieldR - 1))
			return true;

		else return false;
	}
}

// MOVEMENT FUNCTIONS_________________________________
// MoveLeft function
void T_Piece::moveLeft(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	
	// count 0 :
	if (countForRotation == 0) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y - 1] = char(137);
			b.board[x + 2][y - 1] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y + 1] = " ";
			b.board[x + 2][y + 0] = " ";


			yPos--;	//updating the yPosition ('_')
			b.draw();
		}

	}
	// count 1 :
	else if (countForRotation == 1) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y - 0] = char(137);
			
			// clean peechy walla gand:)

			b.board[x + 0][y + 2] = " ";
			b.board[x + 1][y + 1] = " ";

			yPos--;	//updating the yPosition ('_')

			b.draw();
		}
	}
	// count 2
	else if (countForRotation == 2) {
		if (!canItMoveLeft(b))
			return;
		else {

			b.board[x + 0][y - 1] = char(137);
			b.board[x + 1][y - 2] = char(137);
			b.board[x + 2][y - 1] = char(137);
			// clean peechy walla gand:)

			b.board[x][y] = " ";
			b.board[x + 1][y] = " ";
			b.board[x + 2][y] = " ";

			yPos--;	//updating the yPosition ('_')

			b.draw();
		}
	}
	// count 3 :
	else if (countForRotation == 3) {
		if (!canItMoveLeft(b))
			return;
		else {
			b.board[x + 0][y - 2] = char(137);
			b.board[x - 1][y - 1] = char(137);

			// clean peechy walla gand:)

			b.board[x + 0][y - 1] = " ";
			b.board[x + 0][y + 1] = " ";

			yPos--;	//updating the yPosition ('_')

			b.draw();
		}
	}

}
// MoveRight function
void T_Piece::moveRight(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 1] = char(137);
			b.board[x + 1][y + 2] = char(137);
			b.board[x + 2][y + 1] = char(137);

			// clean peechy walla gand:)
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y + 0] = " ";
			b.board[x + 2][y + 0] = " ";
			
			yPos++; //updating the yPosition ('_')

			b.draw();
		}

	}
	// count 1 :
	else if (countForRotation == 1) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 3] = char(137);
			b.board[x + 1][y + 2] = char(137);

			// clean peechy walla gand:)

			b.board[x][y] = " "; 
			b.board[x + 1][y + 1] = " ";
		
			yPos++; //updating the yPosition ('_')

			b.draw();
		}
	}
	// count 2 :
	else if (countForRotation == 2) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 1] = char(137);
			b.board[x + 1][y + 1] = char(137);
			b.board[x + 2][y + 1] = char(137);

			// clean peechy walla gand:)

			b.board[x][y] = " ";
			b.board[x + 1][y - 1] = " ";
			b.board[x + 2][y + 0] = " ";

			yPos++; //updating the yPosition ('_')

			b.draw();
		}
	}
	// count 3 :
	else if (countForRotation == 3) {
		if (!canItMoveRight(b))
			return;
		else {
			b.board[x + 0][y + 2] = char(137);
			b.board[x - 1][y + 1] = char(137);

			// clean peechy walla gand:)

			b.board[x - 1][y + 0] = " ";
			b.board[x + 0][y - 1] = " ";
			
			yPos++; //updating the yPosition ('_')

			b.draw();
		}
	}
}
// MoveDown function 
void T_Piece::moveDown(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;

	if (lastRowPerPohanchGyaHa(b)) {
		return;
	}
	else {
		if (countForRotation == 0 && canItMoveDown(b)) {

			// naii jaga per placements kro :¬
			b.board[x + 3][y + 0] = char(137);
			b.board[x + 2][y + 1] = char(137);

			//pichla gand saaf kroo:¬
			b.board[x][y] = " ";
			b.board[x + 1][y + 1] = " ";

			xPos++; // xPos ko update krdia
			system("cls");
			b.draw();

		}
		// count 1 :
		else if (countForRotation == 1 && canItMoveDown(b)) {

			b.board[x + 1][y + 0] = char(137);
			b.board[x + 2][y + 1] = char(137);
			b.board[x + 1][y + 2] = char(137);

			// cleaning pichla gand :¬
			b.board[x + 0][y + 0] = " ";
			b.board[x + 0][y + 1] = " ";
			b.board[x + 0][y + 2] = " ";
			
			xPos++;
			system("cls");
			b.draw();
		}
		// count 2 :
		else if (countForRotation == 2 && canItMoveDown(b)) {

			b.board[x + 3][y + 0] = char(137);
			b.board[x + 2][y - 1] = char(137);

			// cleaning pichla gand :¬
			b.board[x + 0][y + 0] = " ";
			b.board[x + 1][y - 1] = " ";

			xPos++;
			b.draw();
		}
		// count 3 :
		else if (countForRotation == 3 && canItMoveDown(b)) {

			b.board[x + 1][y + 0] = char(137);
			b.board[x + 1][y - 1] = char(137);
			b.board[x + 1][y + 1] = char(137);

			// cleaning pichla gand :¬
			b.board[x + 0][y - 1] = " ";
			b.board[x + 0][y + 1] = " ";
			b.board[x - 1][y + 0] = " ";

			xPos++;
			b.draw();
		}
		
	}
}
// =============================================================

// Movement :-
void T_Piece::move(string ch, Board& b) {

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
	// what if other key is pressed ? 
	else
		moveDown(b);

}

// Rotation :-

bool T_Piece::canItRotate(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0) {
		if (b.board[x + 0][y + 1] != " " ||
			b.board[x+ 0][y + 2] != " "
		)
			return false;
		else return true;
	}
	else if (countForRotation == 1) {
		if (b.board[x + 1][y] != " " ||
			b.board[x + 2][y] != " " ||
			b.board[x + 1][y - 1] != " "
			)
			return false;
		else return true;
	}
	else if (countForRotation == 2) {
		if (b.board[x - 1][y] != " " ||
			b.board[x + 0][y - 1] != " " ||
			b.board[x + 0][y + 1] != " "
			)
			return false;
		else return true;
	}
	else if (countForRotation == 3) {
		if (b.board[x + 1][y] != " " ||
			b.board[x + 2][y] != " " ||
			b.board[x + 1][y + 1] != " "
			)
			return false;
		else return true;
	}
	// Done
	//-------------------------------
}
void T_Piece::rotation(Board& b) {
	int x = xPos + 1;
	int y = yPos + 1;
	if (countForRotation == 0 && (canItRotate(b))) {
		b.board[x][y + 1] = char(137);
		b.board[x][y + 2] = char(137);
		b.board[x + 1][y + 1] = char(137);

		// cleaning pichla gand:¬
		b.board[x + 1][y] = " ";
		b.board[x + 2][y] = " ";
		
		countForRotation = 1;
		b.draw();
	}
	else if (countForRotation == 1 && (canItRotate(b))) {

		b.board[x + 1][y] = char(137);
		b.board[x + 2][y] = char(137);
		b.board[x + 1][y - 1] = char(137);

		// cleaning pichla gand:¬
		b.board[x][y + 1] = " ";
		b.board[x][y + 2] = " ";
		b.board[x + 1][y + 1] = " ";

		countForRotation = 2;
		b.draw();
	}
	else if (countForRotation == 2 && (canItRotate(b))) {
		b.board[x][y + 1] = char(137);
		b.board[x][y - 1] = char(137);
		b.board[x - 1][y] = char(137);

		// cleaning pichla gand:¬
		b.board[x + 1][y] = " ";
		b.board[x + 2][y] = " ";
		b.board[x + 1][y - 1] = " ";

		countForRotation = 3;
		b.draw();
	}
	else if (countForRotation == 3 && (canItRotate(b))) {
		b.board[x + 1][y] = char(137);
		b.board[x + 2][y] = char(137);
		b.board[x + 1][y + 1] = char(137);

		// cleaning pichla gand:¬
		b.board[x][y + 1] = " ";
		b.board[x][y - 1] = " ";
		b.board[x - 1][y] = " ";

		countForRotation = 0;
		b.draw();
	}

}
//----------------------------------------------------------\\
//                    COMPLETED                              \\
// -----------------------------------------------------------\\
