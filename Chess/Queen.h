#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen :public Piece
{
public:
	Queen(string colour);
	~Queen();
	virtual bool checkMoveLegality(int newX, int newY, int prevX, int prevY);
};

#endif