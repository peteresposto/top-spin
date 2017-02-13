#pragma once
#include "CircularDoublyLinkedList.h"
#include <iostream>
#ifndef TOPSPIN_HPP
#define TOPSPIN_HPP
using namespace std;

class TopSpinADT
{
public:
	//shifts the pieces 1 to the left
	virtual void shiftLeft() = 0;
	//shifts the pieces 1 to the right
	virtual void shiftRight() = 0;
	//reverses the pieces in the spin mechanism, IE if the 4 in the mechanism are
	//1,4,3,6 we will have 6,3,4,1
	virtual void spin() = 0;
	//checks to see if the puzzle is solved that is to say the pieces are in numerical order 1-20
	virtual bool isSolved() = 0;
};

class TopSpin : public TopSpinADT
{
private:
	CDLinkedList <int> ::Iterator startOfSpinner;
	CDLinkedList <int> ::Iterator endOfSpinner;

public:
	CDLinkedList<int> numList;
	unsigned int spinSize;
	unsigned int boardSize;
	TopSpin(unsigned int sizeOfBoard = 20, unsigned int sizeOfSpinner = 4);
	void shiftLeft();
	void shiftLeft(unsigned int s);
	void randomize(unsigned int m);
	void shiftRight();
	void spin();
	bool isSolved();

	friend ostream& operator<< (ostream& os, const TopSpin &ts);
};

#endif