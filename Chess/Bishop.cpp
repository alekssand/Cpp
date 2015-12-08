#include "Bishop.h"


Bishop::Bishop(string colour)
	:Piece(colour)
{
}


Bishop::~Bishop()
{
}

bool Bishop::checkMoveLegality(int newX, int newY, int prevX, int prevY)
{
	bool okToMove = false; 

	for (int i = 0; i < 8|| okToMove ==true; i++)
	{
		if (newY + (1 * i) == prevY || newY - (1 * i) == prevY)
		{
			if (newX + (1 * i) == prevX || newX - (1 * i) == prevX)
			{
				okToMove = true; 
			}
		}
	}
	return okToMove;
}