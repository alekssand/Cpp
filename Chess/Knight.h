#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(string colour);
	~Knight();
	virtual bool checkMoveLegality(int newX, int newY, int prevY, int prevX) ;
};

#endif
