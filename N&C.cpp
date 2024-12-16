#include <stdio.h>
#include <tchar.h>
#include <string>
#include <conio.h>
#include <iostream>

using namespace std;

//Functions/Forward Declarations
void DisplayGrid();
void DisplayInput();
void FillSquare(int row, int col);
void CheckInput();
void CheckStatus();
void Init();

//Global Variables

const int ROWS = 3;			//constant variable - number of rows
const int COLS = 3;			//constant variable - number of columns
char grid[ROWS][COLS];		//grid for noughts & crosses game
int filledSquares = 0;		//variable that holds integer amount of squares filled
char input = ' ';			//variable to hold users input
char currentPlayer = 1;		//variable to hold current players number

int main()
{
	//Init method to be called to clear grid, and set player to 1
	Init();

	//do while loop (execute at least once before it checks condition to exit console) - and contains 'game loop'
	do
	{
		//clear console display and show message
		system("cls");
		cout << "Welcome to Noughts and Crosses!" << endl;
		DisplayGrid();		//displays grid
		DisplayInput();		//displays input options
		CheckInput();		//checks players input
		CheckStatus();		//checks if win or draw

	} while (toupper(input) != 'F'); // condition that checks that the player hasn't quit by typing F //
}

//function that displays grid to user
void DisplayGrid()
{
	//displays the grid with values provided below
	cout << grid[0][0] << "!" << grid[0][1] << "!" << grid[0][2] << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
	cout << endl;
}

//displays input options and current player to the user
void DisplayInput()
{
	//displays current player's game, and then a grid of input keys
	cout << "Player " << currentPlayer << " it's your go!" << endl;
	cout << "Enter the key as shown below to correspond with the grid!" << endl;
	cout << endl;
	cout << "Q" << "|" << "W" << "|" << "E" << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << "A" << "|" << "S" << "|" << "D" << endl;
	cout << "-" << "|" << "-" << "|" << "-" << endl;
	cout << "Z" << "|" << "X" << "|" << "C" << endl;
}

//takes in the row and column of the square to fill
void FillSquare(int row, int col)
{
	//if the selected square is NOT empty
	if (grid[row][col] != ' ')
	{
		//give message to player and call CheckInput again to retry
		//recursion between functions that causes memory issues if player consitently selects taken squares.
		cout << "That square is filled, please try again" << endl;
		CheckInput();
	}
	else
	{
		//otherwise - fill the selected square with the right letter
		//X is for player 1, and 0 for player 2
		if (currentPlayer == 1)
			grid[row][col] = 'X';
		else
			grid[row][col] = 'O';

		//increment the filledSquares var as we've filled one
		filledSquares++;
	}
}

//Checks the user input character, and attempts to fill in a square
static void CheckInput()
{
	//gets the characters that has been put into input variable (entered as a char)
	cin >> input;

	//check input is actually a 'char'
	if (cin.fail())
	{
		//more recursion that could cause issues
		cout << "Invalid character, try again!" << endl;
		CheckInput();
	}

	//converts the 'char' inputted to upper case
	input = toupper(input);

	//check the input character
	//maps the input keys in regards to the grid reference
	//calling the FillSquare function
	switch (input)
	{
	case 'Q': FillSquare(0, 0); break;	//top-left
	case 'W': FillSquare(0, 1); break;	//top-centre
	case 'E': FillSquare(0, 2); break;	//top-right
	case 'A': FillSquare(1, 0); break;	//middle-left
	case 'S': FillSquare(1, 1); break;	//middle-centre
	case 'D': FillSquare(1, 2); break;	//middle-right
	case 'Z': FillSquare(2, 0); break;	//bottom-left
	case 'X': FillSquare(2, 1); break;	//bottom-centre
	case 'C': FillSquare(2, 2); break;	//bottom-right
		//if not any of the above...
	default:
	{
		//more recursion that could cause issues
		cout << "Invalid character, try again!" << endl;
		CheckInput();
	}
	break;
	}
}

//function checks for a winning combination in the grid, or a draw
static void CheckStatus()
{
	//character to check (small variable name for if statement)
	//initialise to X, but change to 0 if currently player 2
	char xo = 'X';
	if (currentPlayer == 2)
		xo = 'O';

	//flag for if we are still in play mode
	//to set to false if there is a win or draw 
	bool inPlay = true;

	//checks for winning combinaton based on last player's char entered
	//xo will be X or 0
	if (
		//row matches
		grid[0][0] == xo && grid[0][1] == xo && grid[0][2] == xo ||
		grid[1][0] == xo && grid[1][1] == xo && grid[1][2] == xo ||
		grid[2][0] == xo && grid[2][1] == xo && grid[2][2] == xo ||

		//column matches
		grid[0][0] == xo && grid[1][0] == xo && grid[2][0] == xo ||
		grid[0][1] == xo && grid[1][1] == xo && grid[2][1] == xo ||
		grid[0][2] == xo && grid[1][2] == xo && grid[2][2] == xo ||

		//diagonal matches
		grid[0][0] == xo && grid[1][1] == xo && grid[2][2] == xo ||
		grid[0][2] == xo && grid[1][1] == xo && grid[2][0] == xo

		)
	{
		//when there's a win, display which player and unset flag
		cout << "Player " << currentPlayer << " wins!" << endl;
		inPlay = false;

	}
	else if (filledSquares == ROWS * COLS)
	{
		//if the filledSquares is the same as the grid length (9)
		//it's a draw (all sqaures are filled), so show cout message in console and unset flag
		cout << "It's a draw" << endl;
		inPlay = false;
	}

	//if we are not in play (a win/draw)
	if (!inPlay)
	{
		//display the complete grid
		DisplayGrid();
		//clear the grid and set to player 1
		Init();
		//message to user in console.
		//if F key is pressed, then it will terminate the while condition in Main and close application
		cout << "Play again? Any key. F to quit." << endl;
		cin >> input;
	}
	else
	{
		//If not, still in play so switch player
		if (currentPlayer == 1)
			currentPlayer = 2;
		else currentPlayer = 1;
	}
}

//function to set update grid with spaced chars
// sets up player 1, ready for a new game
static void Init()
{
	currentPlayer = 1;
	filledSquares = 0;

	//nested loop through all rows and columns
	//to set each square in the grid to a spaced char
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
			grid[row][col] = ' ';
	}
}