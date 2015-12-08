#include "Piece.h"


Piece::Piece(string colour)
{
	this->colour = colour; 
	

}


Piece::~Piece()
{
}

string Piece::getColour()const
{
	return this->colour;
}

void Piece::setColour(string colour)
{
	this->colour = colour; 
}

bool Piece::moveLegality(int newX, int newY, int prevX, int prevY)
{
	return checkMoveLegality(newX,  newY,  prevX,  prevY);
}