// Filename: TurtleGraphics.cpp
// Description: Asssignment 06 Excercise 7.23 Member-function definitions 
//				for class TurtleGraphics.
//
// Version: 1.0
// Created: 08/03/17 9:30AM
// Author: Ronnie Manimtim

#include "TurtleGraphics.h"
#include <iostream>
using namespace std;

// Ctor will init.floor to all "false" values,
// as well as initialization of other data members
TurtleGraphics::TurtleGraphics(void)
{
	for (auto &rows : m_Floor)
	{
		for (auto &element : rows)
		{
			element = false;
		} // End for
	} // End for

	turtleDirection = static_cast<int>(STARTING_DIRECTION);
	currentRow = STARTING_ROW;
	currentColumn = STARTING_COL;
	penPosition = STARTING_PEN_POSITION;
} // End ctor

// Will process the commands contained in array "commands"	
void TurtleGraphics::processTurtleMoves(const array<int, ARRAY_SIZE> &cmds)
{
	int cmdNo = STILL_VALUE;
	bool exitFlag = false;

	do {

		switch (static_cast<Cmds>(cmds[cmdNo]))
		{

		case Cmds::PEN_UP:

			penPosition = false;
			break;

		case Cmds::PEN_DWN:

			penPosition = true;
			break;

		case Cmds::TURN_RIGHT:

			turtleDirection += EAST_DIRECTION;

			if (turtleDirection == NORTH_EAST_DIRECTION)
			{
				turtleDirection = EAST_DIRECTION;
			} // End if
			break;

		case Cmds::TURN_LEFT:

			turtleDirection -= EAST_DIRECTION;

			if (turtleDirection == STILL_VALUE)
			{
				turtleDirection = NORTH_DIRECTION;
			} // End if
			break;

		case Cmds::MOVE:

			++cmdNo;
			turtleMoves(cmds[cmdNo]);
			break;

		case Cmds::DISPLAY:

			displayFloor();
			break;

		case Cmds::END_OF_DATA:

			exitFlag = true;
			break;

		default:

			cerr << "\n\nError - invalid command encountered in processTurtleMoves() switch statement.\n\n";
			return;
		} // End switch

		++cmdNo;

	} while (!exitFlag); // End do while
} // End processTurtleMoves

// Moves the turtle along floor
void TurtleGraphics::turtleMoves(const int &numOfMoves)
{

	if (numOfMoves < MOVES_VALUE)
	{
		return;
	} // End if

	int actualNumMoves = numOfMoves;

	switch (turtleDirection)
	{

	case EAST_DIRECTION:

		if ((numOfMoves + currentColumn) > (NCOLS - MOVES_VALUE))
		{
			actualNumMoves = (NCOLS - MOVES_VALUE) - currentColumn;
		} // End if

		if (penPosition)
		{
			for (int index = START_INDEX; index <= actualNumMoves; ++currentColumn, ++index)
			{
				m_Floor[currentRow][currentColumn] = true;
			} // End for
		}
		else
		{
			currentColumn += actualNumMoves;
		} // End if
		break;

	case SOUTH_DIRECTION:

		if ((numOfMoves + currentRow) > (NROWS - MOVES_VALUE))
		{
			actualNumMoves = (NROWS - MOVES_VALUE) - currentRow;
		} // End if

		if (penPosition)
		{
			for (int index = START_INDEX; index <= actualNumMoves; ++currentRow, ++index)
			{
				m_Floor[currentRow][currentColumn] = true;
			} // End for
		}
		else
		{
			currentRow += actualNumMoves;
		} // End if
		break;

	case WEST_DIRECTION:

		if ((currentColumn - numOfMoves) < STILL_VALUE)
		{
			actualNumMoves = currentColumn;
		} // End if

		if (penPosition)
		{
			for (int index = START_INDEX; index <= actualNumMoves; --currentColumn, ++index)
			{
				m_Floor[currentRow][currentColumn] = true;
			} // End for
		}
		else
		{
			currentColumn -= actualNumMoves;
		} // End if
		break;

	case NORTH_DIRECTION:

		if ((currentRow - numOfMoves) < STILL_VALUE)
		{
			actualNumMoves = currentRow;
		} // End if

		if (penPosition)
		{
			for (int index = START_INDEX; index <= actualNumMoves; --currentRow, ++index)
			{
				m_Floor[currentRow][currentColumn] = true;
			} // End for
		}
		else
		{
			currentRow -= actualNumMoves;
		} // End if
		break;

	default:

		cerr << "\n\nErrow - invalid direction in turtleMoves() switch statement.\n\n";
		return;
	} // End switch
} // End turtleMoves

// Will display floor on the screen
void TurtleGraphics::displayFloor() const
{
	for (auto const &rows : m_Floor)
	{
		for (auto const &element : rows)
		{
			if (element)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			} // End if
		} // End for

		cout << endl;
	} // End for

	cout << endl << endl;
} // End displayFloor