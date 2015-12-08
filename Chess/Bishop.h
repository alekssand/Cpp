#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop:public Piece
{
public:
	Bishop(string colour);
	~Bishop();
	virtual bool checkMoveLegality(int newX, int newY, int prevX, int prevY);
};

#endif