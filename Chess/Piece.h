#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>

using namespace std;

class Piece
{
private: 
	string colour; 
public:
	Piece(string colour = "none");
	virtual ~Piece();
	bool moveLegality(int newX, int newY, int prevX, int prevY);
	virtual bool checkMoveLegality(int newX, int newY, int prevX, int prevY) = 0;
	string getColour()const;
	void setColour(string colour); 
};
#endif

