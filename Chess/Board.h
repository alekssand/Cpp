#ifndef BOARD_H
#define BOARD_H

//#include "GameLogic.h"

#include <QString>


#include "Piece.h"

#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class Board
{
protected: 
	Piece *board[8][8];
	string turn; 
	bool whiteKingCheck; 
	bool blackKingCheck; 
	bool whiteCheckMate; 
	bool blackCheckMate; 
	bool pawnPromotion;
	int whiteKingY; 
	int whiteKingX;
	int blackKingY; 
	int blackKingX; 

public:
	Board();	
	~Board();
	void checkMate(); 
	bool isSquareLegal(int newY, int newX, int prevY, int prevX); 
	void makeMove(int newX, int newY, int prevX, int prevY);
    bool whiteCheck(int X, int Y);
    bool blackCheck(int X, int Y);
	bool queenMove(int newY, int newX, int prevY, int prevX);
	bool bishopMove(int newY, int newX, int prevY, int prevX);
	bool rookMove(int newY, int newX, int prevY, int prevX);
    bool isAPiece(int X, int Y);
    QString getCheckMate();
    QString getPiece(int X, int Y);
};
#endif
