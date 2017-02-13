#pragma once
#include "TopSpin.h"
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <time.h>
#ifndef TOPSPIN_CPP
#define TOPSPIN_CPP
using namespace std;

TopSpin::TopSpin(unsigned int sizeOfBoard, unsigned int sizeOfSpinner)
{
	for (int i = 1; i <= sizeOfBoard; i++)
	{
		numList.addTail(i);
	}
	startOfSpinner = numList.begin();
	endOfSpinner = numList.begin();
	for (int i = 1; i < sizeOfSpinner; i++)
	{
		endOfSpinner++;
	}
	spinSize = sizeOfSpinner;
	boardSize = sizeOfBoard;
}

void TopSpin::shiftRight()
{
	startOfSpinner--;
	endOfSpinner--;
}

void TopSpin::shiftLeft()
{
	startOfSpinner++;
	endOfSpinner++;
}

//shiftLeft function for the randomizer
void TopSpin::shiftLeft(unsigned int s)
{
	for (unsigned int i = 1; i < s; i++)
		shiftLeft();
}

void TopSpin::spin()
{
	CDLinkedList<int>::Iterator it1 = startOfSpinner;
	CDLinkedList<int>::Iterator it2 = endOfSpinner;

	for (int i = 0; i < floor(spinSize / 2); i++) 
	{
		int temp = it1.getValue();
		it1.setValue(it2.getValue());
		it2.setValue(temp);
		it1++;
		it2--;
	}
}

bool TopSpin::isSolved() 
{
	CDLinkedList<int>::Iterator isSolved = startOfSpinner;

	int previousValue = isSolved.getValue();
	if (previousValue == boardSize) 
	{
		previousValue = 0;
	}

	isSolved++;
	while (isSolved != startOfSpinner) 
	{
		//Immediately checks for an error in the list by looking at the previous value and comparing it
		//to the next one and returns false if they're not in order
		if ((previousValue + 1) != isSolved.getValue()) 
		{
			return false;
		}
		//
		if (isSolved.getValue() == boardSize) 
		{
			previousValue = 0;
		}

		else 
		{
			previousValue++;
		}

		isSolved++;
	}
	return true;
}

ostream& operator<< (ostream& os, const TopSpin &ts)
{
	CDLinkedList<int>::Iterator printer = ts.startOfSpinner;
	for (int i = 1; i <= ts.boardSize; i++)
	{
		if (i == 1)
			os << "[ ";
		os << printer.getValue() << " ";
		if (i == ts.spinSize)
			os << "]";
		printer++;
	}
	os << endl;
	return os;
}

//Randomize - enter a number, and that number dictates the amount of times the loop is shifted left 
//a random number of times and then spun
void TopSpin::randomize(unsigned int m)
{
	srand(time(NULL));
	for (int i = 1; i <= m; i++)
	{
		shiftLeft(rand()%20);
		spin();
	}
}

#endif