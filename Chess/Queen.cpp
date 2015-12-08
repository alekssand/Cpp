#include "Queen.h"


Queen::Queen(string colour)
	:Piece(colour)
{
}


Queen::~Queen()
{
}

bool Queen::checkMoveLegality(int newX, int newY, int prevX, int prevY)
{
	 bool okToMove = false;

     for (int i = 0; i < 8 || okToMove == true; i++)
     {
         if (newY + (1 * i) == prevY || newY - (1 * i) == prevY)
         {
             if (newX + (1 * i) == prevX || newX - (1 * i) == prevX)
             {
                 okToMove = true;
             }
         }
     }

     if (newX > prevX && newY == prevY)
	 {

			 okToMove = true;

	 }

     if (newX < prevX && newY == prevY)
     {

             okToMove = true;

     }


     if (newY < prevY && newX == prevX)
	 {

			 okToMove = true;

	 }

     if (newY >prevY && newX == prevX)
     {

             okToMove = true;

     }


	 return okToMove; 
}
