#pragma once
#include<Windows.h>
#include"Block_Class.h"
#include"i_Piece.h"
#include"L_Piece.h"
#include"s_Piece.h"
#include"Square.h"
#include"T_Piece.h"
#pragma once
#include<Windows.h>
#include<iostream>
#include<time.h>

using namespace std;

class Tetris{
private:
	Board b;
	int score = 0;

public:
	// GameLoop:
	void startGame();
	void gameLoop();
};

