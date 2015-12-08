#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece
{
private: 
	bool firstMove; 

public:
	Pawn(string colour);
	~Pawn();
    void firstMoved();
	bool checkMoveLegality(int newX, int newY, int prevX, int prevY);
};
#endif
