#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
class Rook :public Piece
{
public:
	Rook(string colour);
	~Rook();
	virtual bool checkMoveLegality(int newX, int newY, int prevX, int prevY);
};
#endif
