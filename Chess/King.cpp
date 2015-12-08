#include "King.h"


King::King(string colour)
	:Piece(colour)
{
}


King::~King()
{
}

bool King::checkMoveLegality(int newX, int newY, int prevX, int prevY)
{
	bool okToMove = false; 

//	if (newY ++ == prevY || newY -- == prevY)
//	{
//		if (newX ++  == prevX || newX -- == prevX)
//		{
//			okToMove = true;
//		}
//		if (newX == prevX)
//		{
//			okToMove = true;
//		}
//	}
//	if (newX++ == prevX || newX-- == prevX)
//	{
//		if (newY == prevY)
//		{
//			okToMove = true;
//		}
//	}

    int X = newX - prevX;
    int Y = newY - prevY;
    if (((X >= -1) && (X <= 1)) && ((Y >= -1) && (Y <= 1)))
    {
        okToMove = true;
    }

		return okToMove; 
}
