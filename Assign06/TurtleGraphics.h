// Assignment 6 Solution: TurtleGraphics.h
// Declaration of class TurtleGraphics.
// Member functions are defined in TurtleGraphics.cpp.
// Author: Bob Langelaan 
// Date: Feb 28, 2016

#pragma once
#include <array>

// Define some enum types that will be used in solution

enum class Cmds : unsigned short { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum class Directions : unsigned short { NORTH = 12, EAST = 3, SOUTH = 6, WEST = 9 };

// Const values to clear up magic numbers

const int EAST_DIRECTION = static_cast<int>(Directions::EAST);
const int WEST_DIRECTION = static_cast<int>(Directions::WEST);
const int NORTH_DIRECTION = static_cast<int>(Directions::NORTH);
const int SOUTH_DIRECTION = static_cast<int>(Directions::SOUTH);
const int NORTH_EAST_DIRECTION = 15;
const int MOVES_VALUE = 1;
const int STILL_VALUE = 0;
const int START_INDEX = 1;

// TurtleGraphics class
class TurtleGraphics
{
private:
	const static size_t NROWS = 22;  // Number of rows in floor
	const static size_t NCOLS = 70;  // Number of colums in floor

	const static int STARTING_ROW = 0;    // Row that turtle will start in
	const static int STARTING_COL = 0;    // Column that turtle will start in

	const static Directions STARTING_DIRECTION = Directions::SOUTH; // Direction 
						  // that turtle will be facing at the start

	const static bool STARTING_PEN_POSITION = false; // Pen will be up when 
								// program starts
								// False means pen up, true means pen down

	void turtleMoves(const int &numOfMoves); // Move the turtle along floor

	void displayFloor() const;  // Will display floor on the screen	

	std::array <std::array <bool, NCOLS>, NROWS> m_Floor;   // Floor on which turtle will draw

	int turtleDirection; // Current direction of turtle
	bool penPosition; // Current pen position (false == up)
	int currentRow; // Current row
	int currentColumn; // Current column

public:
	const static int ARRAY_SIZE = 250;

	TurtleGraphics(void); //Ctor will init. floor to all "false" values, 
						  //     as well as initialization of other data members
	void processTurtleMoves(const std::array< int, ARRAY_SIZE> &);  // Will process
					   // the commands contained in array "commands"	
};