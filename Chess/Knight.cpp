#include "Knight.h"

Knight::Knight(string colour)
	:Piece(colour)
{
}


Knight::~Knight()
{
}

bool Knight::checkMoveLegality(int newX, int newY, int prevY, int prevX) 
{
	bool okToMove=false; 

    if ((prevY == newY + 1) || (prevY == newY - 1))
    {
        if ((prevX == newX + 2) || (prevX== newX - 2))
        {
             okToMove = true;
         }
    }
    if ((prevY == newY + 2) || (prevY == newY - 2))
    {
        if ((prevX == newX + 1) || (prevX == newX - 1))
        {
            okToMove = true;
        }
    }

	return okToMove; 
}
