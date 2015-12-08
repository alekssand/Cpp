#include "Rook.h"

Rook::Rook(string colour)
	:Piece(colour)
{
}

Rook::~Rook()
{
}

bool Rook::checkMoveLegality(int newX, int newY, int prevX, int prevY)
{
	bool okToMove = false; 
	
	if (newX > prevX || newX < prevX)
	{
		if (newY == prevY)
		{
			okToMove = true; 
		}
	}
	if (newY >prevY || newY < prevY)
	{
		if (newX == prevX)
		{
			okToMove = true; 
		}
	}
	return okToMove; 
}