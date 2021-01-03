#include "Tetris.h"


void Tetris::gameLoop() {
	char check = 'y';
	cout << "Welcome To Tetris :: Made by Mohammad Abdur Rehman Cheema" << endl;
	cout << "press any key to start game" << endl;
	cin.get();
	system("cls");

	while (check == 'y') {
		startGame();
		cout << endl << "Do you want to continue game?" << endl;
		cout << "press 'y' to continue";
	}
	


}


void Tetris::startGame() {

	Block* gameAsset = nullptr;    // Block (abstract class) uska pointer 
	// ( PARENT CLASS ) -> iPiece, sPiece, Tpiece, 
	string ch;
	bool gameOver = false;

	while (!b.isGameOver() && !gameOver) { 
		
		// Generating random pieces : 
		
		srand(time(NULL));
		int randomPiecesNum = rand() % 5;  // 0 1 2 3 4
		
		if (randomPiecesNum == 0) {
			gameAsset = new i_Piece;
		}
		else if (randomPiecesNum == 1) {
			gameAsset = new L_Piece;
		}
		else if (randomPiecesNum == 2) {
			gameAsset = new s_Piece;
		}
		else if (randomPiecesNum == 3) {
			gameAsset = new T_Piece;
		}
		else if (randomPiecesNum == 4) {
			gameAsset = new Square;
		}
		// random Pieces ban gay hain

		gameOver = !gameAsset->canItMoveDown(b);
		
		while (gameAsset->canItMoveDown(b)) {
			gameAsset->moveDown(b);
			
			if (GetAsyncKeyState(VK_RIGHT) & 0x27000) {
				// Right KEY press kroo gay tw ye wo handle kry gee
				// Right key Wo zoor sy press krni ha

				gameAsset->move("d", b);

			}
			else if (GetAsyncKeyState(VK_LEFT) & 0x25000) {

				gameAsset->move("a", b);

			}
			else if (GetAsyncKeyState(VK_UP) & 0x26000) {
				// rotation k lye :
				gameAsset->move("s", b);

			}
			else {
				gameAsset->move("v", b);

			}

			Sleep(50);
			//system("cls");
			b.draw();
			
		}	
		
		system("cls");
		b.draw();
		if (!gameAsset->canItMoveDown(b)) {
			score += 25;
		}
		if (b.row_Khaali_Tw_Nai_Karni()) {
			b.baraOperation();
			score += 100;
		}
		delete gameAsset;

	}

	cout << "Score = " << score << endl;
	cout << "Game Ends" << endl;
	
	if (b.isGameOver()) {
		return;
	}
	// Game Over //
}