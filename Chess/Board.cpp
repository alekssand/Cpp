#include "Board.h"
#include "mainwindow.h"

Board::Board()
{ 
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			this->board[row][col] = nullptr;
		}
	}

	//Svarta pjäser
	this->blackKingY = 3; 
	this->blackKingX = 7;

	for (int col = 0; col < 8; col++) 
	{
		this->board[6][col] = new Pawn("Black");
	}
	this->board[7][0] = new Rook("Black");
	this->board[7][1] = new Knight("Black");
	this->board[7][2] = new Bishop("Black");
	this->board[7][3] = new King("Black");
	 
    this->board[7][4] = new Queen("Black");
	this->board[7][5] = new Bishop("Black");
	this->board[7][6] = new Knight("Black");
	this->board[7][7] = new Rook("Black");

	
	//vita pjäser
	this->whiteKingY = 0; 
	this->whiteKingX = 3; 
	for (int col = 0; col < 8; col++)
	{
		this->board[1][col] = new Pawn("White");
	}
	this->board[0][0] = new Rook("White");
	this->board[0][1] = new Knight("White");
	this->board[0][2] = new Bishop("White");
	this->board[0][3] = new King("White");
	
	this->board[0][4] = new Queen("White");
	this->board[0][5] = new Bishop("White");
	this->board[0][6] = new Knight("White");
	this->board[0][7] = new Rook("White");

    this->turn= "White";
    this->blackKingCheck = false;
    this->whiteKingCheck = false;
}

Board::~Board()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			delete this->board[row][col];
		}
	}
}
//int newY, int newX, int prevY, int prevX
//int newY, int newX, int prevY, int prevX
bool Board::isSquareLegal(int newY, int newX, int prevY, int prevX)
{
	bool okToMove = false; 
	pawnPromotion = false; 

	if (newX >= 0 && newX <= 7)
	{
		if (newY >= 0 && newY <= 7)
		{

            Piece *aPiece=dynamic_cast<Piece *>(this->board[newX][newY]);
            if(aPiece != nullptr)
            {
                if(this->turn == "White")
                {
                    if (this->board[newX][newY]->getColour() != "White")
                    {
                        okToMove = true;
                    }
                }
                else if(this->turn == "Black")
                {
                    if (this->board[newX][newY]->getColour() != "Black")
                    {
                        okToMove = true;

                    }
                }

            }
            else
            {
                okToMove = true;

            }
		}
	}

    Pawn *aPawn=dynamic_cast<Pawn *>(this->board[prevX][prevY]);
    if(aPawn!= nullptr)
    {
            if(aPawn->getColour() == "White"&& prevX > newX)
            {
                 okToMove = false;

            }
            else if(aPawn->getColour() == "Black" && prevX < newX)
            {

                    okToMove = false;

            }



    }

    if(this->turn != this->board[prevX][prevY]->getColour())
    {
            okToMove = false;
    }
	


	////promovera bonden
 //   Piece *aPiece = dynamic_cast<Pawn *> (this->board[prevX][prevY]);
	//if(aPiece !=nullptr)
	//{	
	//	//vit kan bara promoveras på ena sidan 
 //       if(this->board[prevX][prevY]->getColour()=="white" && newY>prevY)
	//	{
	//		okToMove = true; 
	//		if(newY > 7)
	//		{
	//			pawnPromotion = true; 
	//		}
	//	}
	//	
	//	//svart kan bara promoveras på ena sidan
 //       if(this->board[prevX][prevY]->getColour()=="Black" && newY<prevY)
	//	{
	//		okToMove = true; 
	//		if(newY < 0)
	//		{
	//			pawnPromotion = true; 
	//		}
	//	}
	//}

	//behöver endast anropas om okToMove är sann
    if(okToMove == true)
    {
        //Tornet kan inte gå över andra pjäser
        Piece *aRook = dynamic_cast<Rook *> (this->board[prevX][prevY]);
        if(aRook !=nullptr)
        {
            okToMove= this->rookMove(newX, newY, prevX, prevY);
        }

        // Kollar så att dam inte går över någon
        Piece *aQueen = dynamic_cast<Queen *> (this->board[prevX][prevY]);
        if(aQueen !=nullptr)
        {
            okToMove = this->queenMove(newY, newX, prevY, prevX);
            if(okToMove == false)
            {
                cout << "haft"<<endl;

            }
        }

        //Gör så att löparen inte kan gå över pjäser
        Piece *aBishop = dynamic_cast<Bishop *> (this->board[prevX][prevY]);
        if(aBishop !=nullptr)
        {
            okToMove = this->bishopMove(newY, newX, prevY, prevX);
        }
    }

	return okToMove; 
}


//Färdig
bool Board::rookMove(int newY, int newX, int prevY, int prevX)
{
	bool okToMove = true; 



    if(newX < prevX)
	{
		for(int i = prevX; i< newX-1 ; i++)
		{
			Piece *aPiece = dynamic_cast<Piece *> (this->board[prevY][i]);
			if(aPiece !=nullptr)
			{
				okToMove=false; 
			}

		}
	}

    if(newX > prevX)
	{
		for (int i = newX; i < prevX - 1 && okToMove == true; i--)
		{
			Piece *aPiece = dynamic_cast<Piece *> (this->board[prevY][i]);
			if(aPiece !=nullptr)
			{
				okToMove=false; 
			}

		}
	}


    if(newY > prevY)
	{
		for(int i = newY; i< prevY-1 ; i--)
		{
			Piece *aPiece = dynamic_cast<Piece *> (this->board[i][prevX]);
			if(aPiece !=nullptr)
			{
				okToMove=false; 
			}

		}
	}


    if(newY < prevY)
	{
		for(int i = newY; i< prevY-1 ; i++)
		{
			Piece *aPiece = dynamic_cast<Piece *> (this->board[i][prevX]);
			if(aPiece !=nullptr)
			{
				okToMove=false; 
			}

		}
	}

	return okToMove; 
}

//Färdig
bool Board::bishopMove(int newY, int newX, int prevY, int prevX)
{
	bool okToMove = true; 

	if(newY >prevY && newX >prevX)
	{
		for (int i = 0; i < 8|| okToMove ==true; i++)
		{
			int y = newY + (1 * i); 
			int x = newX + (1 * i);

			if (y == prevY)
			{
				if (x == prevX)
				{
					if(x != newX && y != newY)
					{
						Piece *aPiece = dynamic_cast<Piece *> (this->board[y][x]);
						if(aPiece !=nullptr)
						{
							okToMove=false; 
						}
					}
				}
			}
		}
	}

	if(newY <prevY && newX <prevX)
	{
		for (int i = 0; i < 8|| okToMove ==true; i++)
		{
			int y = newY - (1 * i);
			int x = newX - (1 * i);
			if (y == prevY)
			{
				if (x == prevX)
				{
					if(x != newX, y != newY)
					{
						Piece *aPiece = dynamic_cast<Piece *> (this->board[y][x]);
						if(aPiece !=nullptr)
						{
							okToMove=false; 
						} 
					}
				}
			}
		}
	}

	if(newY <prevY && newX >prevX)
	{
		for (int i = 0; i < 8|| okToMove ==true; i++)
		{
			int y = newY - (1 * i);
			int x = newX + (1 * i);
			if (y == prevY)
			{
				if (x == prevX)
				{
					if(y != newY && x != prevX)
					{
						Piece *aPiece = dynamic_cast<Piece *> (this->board[y][x]);
						if(aPiece !=nullptr)
						{
							okToMove=false; 
						} 
					}
				}
			}
		}
	}

	if(newY >prevY && newX <prevX)
	{
		for (int i = 0; i < 8|| okToMove ==true; i++)
		{
			int y = newY + (1 * i);
			int x = newX - (1 * i);
			if (y == prevY)
			{
				if (x == prevX)
				{
					if(x != newX, y != prevY)
					{
						Piece *aPiece = dynamic_cast<Piece *> (this->board[y][x]);
						if(aPiece !=nullptr)
						{
							okToMove=false; 
						} 
					}
				}
			}
		}
	}
	return okToMove; 
}

//Färdig
bool Board::queenMove(int newY, int newX, int prevY, int prevX)
{
    bool okToMove = true;

    if(newX < prevX && newY == prevY )
    {
        for(int i = prevX; i>= newX ; i++)
        {

            if(this->board[i][prevY]!=nullptr)
            {
                okToMove=false;
            }
        }
    }

    if(newX > prevX && newY == prevY )
    {
        for(int i = newX; i>= prevX ; i--)
        {
             if(this->board[i][prevY]!=nullptr)
            {
                okToMove=false;
            }

        }
    }
    if(newY < prevY && newX == prevY)
    {
        for(int i = newY; i>= prevY; i--)
        {
            if(this->board[prevX][i]!=nullptr)
            {
                okToMove=false;
            }

        }
    }
    if(newY > prevY && newX == prevY)
    {
        for(int i = newY; i>= prevY ; i++)
        {

            if(this->board[prevX][i]!=nullptr)
            {
                okToMove=false;
            }

        }
    }

			
    if(newY >prevY && newX >prevX)
    {
        for (int i = 0; i > 8|| okToMove ==true; i++)
        {
            int y = newY + (1 * i);
            int x = newX + (1 * i);

            if (y == prevY)
            {
                if (x == prevX)
                {
                    if(x != newX && y != newY)
                    {

                        if(this->board[y][x] != nullptr)
                        {
                            okToMove=false;
                        }
                    }
                }
            }
        }
    }

    if(newY <prevY && newX <prevX)
    {
        for (int i = 0; i < 8|| okToMove ==true; i++)
        {
            int y = newY - (1 * i);
            int x = newX - (1 * i);

                    if (x != newX && y != newY)
                    {
                         if(this->board[y][x] != nullptr)
                        {
                            okToMove=false;
                        }
                    }

        }
    }


	return okToMove; 
}

//kollar schackmatt
void Board::checkMate()
{
    this->whiteCheckMate = false;
    this->blackCheckMate = false;



    for(int i = -1; i <=1; i ++)
    {
        for(int k = -1; k <=1 ; i++)
        {
            Piece * temp =  this->board[this->blackKingX+i][this->blackKingY+k];

            delete this->board[this->blackKingX+i][this->blackKingY+k];
            this->board[this->blackKingX+i][this->blackKingY+k] = this->board[this->blackKingX][this->blackKingY];
            this->board[this->blackKingX][this->blackKingY] = nullptr;
            for(int col = 0; i<8;i++)
            {
                for(int row = 0; i<0; i++)
                {

                     if( this->board[row][col]->moveLegality(this->blackKingX + i, this->blackKingY+ k, row, col) == true && this->isSquareLegal(this->blackKingY + i, this->blackKingX +k, col, row) == true)
                     {
                         blackCheckMate = true;
                     }
                }
             }


        }
    }
}

//kollar om svart står i schack
bool Board::blackCheck(int X, int Y)
{
	bool check = false; 
	for(int row =0; row < 8; row++)
	{
		for(int col=0; col < 8; col++)
		{
            Piece *aPiece = dynamic_cast<Piece *> (this->board[row][col]);
			if(aPiece !=nullptr)
			{
                if (this->board[row][col]->getColour() == "White")
				{
                    if( this->board[row][col]->moveLegality(this->blackKingX + X, this->blackKingY+ Y, row, col) == true && this->isSquareLegal(this->blackKingY + Y, this->blackKingX +X, col, row) == true)
                    {
                        check = true;
                    }
				}
			}
		}
	}
	return check; 
}

//kollar om vit står i schack
bool Board::whiteCheck(int X, int Y)
{
    bool check = false;
    for(int row =0; row < 8; row++)
    {
        for(int col=0; col < 8; col++)
        {
            cout << row << col << endl;
            Piece *aPiece = dynamic_cast<Piece *> (this->board[row][col]);
            if(aPiece !=nullptr)
            {
                if (this->board[row][col]->getColour() == "Black")
                {
                    if( this->board[row][col]->moveLegality(this->whiteKingX+ X, this->whiteKingY+ Y, row, col) == true && this->isSquareLegal(this->whiteKingY + Y, this->whiteKingX + X, col, row) == true)
                    {
                        check = true;
                    }
                }
            }
        }
    }
    return check;
}

 bool Board::isAPiece(int X, int Y)
 {
    bool result = false;

    Piece *aPiece = dynamic_cast < Piece * > (this->board[X][Y]);
    if(aPiece != nullptr )
    {
            result = true;
    }

    return result;
 }


  QString Board::getPiece(int X, int Y)
  {
      QString colour = "";
      QString type = "";


      Piece *aPiece = dynamic_cast < Piece * > (this->board[X][Y]);
      if (aPiece != nullptr)
      {

          if(this->board[X][Y]->getColour() == "White")
          {
              colour = "White";

          }
          else
          {
              colour = "Black";

          }

          Piece *aPawn = dynamic_cast < Pawn * > (this->board[X][Y]);
          if (aPawn != nullptr)
          {
              type = "Pawn " ;
          }
          Piece *aKing = dynamic_cast < King * > (this->board[X][Y]);
          if (aKing != nullptr)
          {
              type = "King " ;
          }
          Piece *aQueen = dynamic_cast < Queen * > (this->board[X][Y]);
          if (aQueen != nullptr)
          {
              type = "Queen " ;
          }
          Piece *aRook = dynamic_cast < Rook * > (this->board[X][Y]);
          if (aRook != nullptr)
          {
              type = "Rook " ;
          }
          Piece *aBishop = dynamic_cast < Bishop * > (this->board[X][Y]);
          if (aBishop != nullptr)
          {
              type = "bishop " ;
          }
          Piece *aKnight = dynamic_cast < Knight * > (this->board[X][Y]);
          if (aKnight != nullptr)
          {
              type = "Knight ";
          }
      }

      return colour + " " + type;
  }

  QString Board::getCheckMate()
  {
      QString mate = "null";

      if(this->blackCheckMate == true)
      {
          mate = "Black";

      }
      else if(this->whiteCheckMate == true)
      {
          mate = "White";
      }

      return mate;

  }

void Board::makeMove(int newX, int newY, int prevX, int prevY)
{


    if (isAPiece(prevX, prevY) == true)
	{

        if (this->board[prevX][prevY]->moveLegality(newX, newY, prevX, prevY) == true)
		{

			if (this->isSquareLegal(newY, newX, prevY, prevX) == true)
			{

				delete this->board[newX][newY];
				this->board[newX][newY] = this->board[prevX][prevY];
                this->board[prevX][prevY] = nullptr;



               if(this->turn == "White")
               {
                   this->turn = "Black";

               }
               else
               {
                   this->turn = "White";
               }

               Pawn *aPawn = dynamic_cast<Pawn *> (this->board[newX][newY]);
               if(aPawn !=nullptr)
               {
                   aPawn->firstMoved();
               }

               King *aKing= dynamic_cast<King*> (this->board[newX][newY]);
               if(aKing  !=nullptr)
               {
                  if(aKing->getColour() == "White")
                  {
                      this->whiteKingX = newX;
                      this->whiteKingY = newY;
                  }
                  else
                  {
                      this->blackKingX = newX;
                      this->blackKingY = newY;
                  }

               }

            }
        }
    }
    if (this->whiteKingCheck == true || this->blackKingCheck == true)
    {
        this->checkMate();
    }

    this->blackCheck(0,0);
   // this->whiteCheck(0,0);


}
