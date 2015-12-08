#pragma once
#include "Piece.h"
class King:public Piece
{
public:
	King(string colour);
	~King();
	virtual bool checkMoveLegality(int newX, int newY, int prevX, int prevY);
};

