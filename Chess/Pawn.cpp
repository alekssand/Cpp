#include "Pawn.h"

Pawn::Pawn(string colour)
	:Piece(colour)
{
	firstMove = true; 
}


Pawn::~Pawn()
{
}

void Pawn::firstMoved()
{
    this->firstMove = false;
}

bool Pawn::checkMoveLegality(int newY, int newX , int prevY, int prevX)
{

	bool okToMove = false; 

	if (prevX == newX)
	{
		if (newY == prevY + 1)
		{
			okToMove = true;
		}
	}

	if (newY == prevY+1 || newY == prevY-1)
	{
		if (newX == prevX || newX==prevX+1|| newX == prevX-1)
		{
			okToMove = true; 			
		}
	}
	
	if (firstMove == true)
	{
		if (newY == prevY + 2 || newY == prevY - 2)
		{

			if (newX == prevX)
			{
				okToMove = true;
			}
		}
	}

	return okToMove;
}
