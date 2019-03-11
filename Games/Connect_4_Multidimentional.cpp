#include "pch.h" //remove if you are compiling it on g++ in ubuntu
#include <iostream>
#include <string>

//Global variables
static std::string g_username1, g_username2;
static bool g_winner{ false };

//Forward declaration of functions
std::string getName(int usernumber);
char** fillBoard(char **boardarray, const int &rows, const int &columns, const char &peg);
int getColumn(const int &columns);
void printBoard(char **boardarray, const int &rows, const int &columns);
void checkWinner(char **boardarray, const int &rows, const int &columns);


int main()
{
	//Request the user to provide the number of rows and columns for the game
	int rows{}, columns{};
	std::cout << "Please enter the number of rows in the connect 4 game (at least >4 for a winner) : ";
	std::cin >> rows;
	std::cout << "\nPlease enter the number of columns in the connect 4 game (at least >4 for a winner) : ";
	std::cin >> columns;
	std::cout << "\n";

	//Create 2D Dynamic array from the rows and column input and initialize them to zeros
	char **connectboard = new char*[rows] {};
	for (int count = 0; count < rows; ++count)
		connectboard[count] = new char[columns] {};

	//reduce by 1 to account for actual arraysize
	rows -= 1;
	columns -= 1;

	//Request the names of the users playing the game and assign colours for personalization
	g_username1 = getName(1);
	std::cout << "You have been assigned Red (\"R\") pegs \n\n";
	g_username2 = getName(2);
	std::cout << "You have been assigned Yellow (\"Y\") pegs \n\n";
	std::cout << "Starting Connect 4 Game ........\n\n";

	// Toggle users and check for winner
	int playerturn{ 1 };
	while (g_winner == false)
	{
		if (playerturn == 1 && g_winner == false)
		{
			std::cout << g_username1 << "'s turn !\n\n";
			connectboard = fillBoard(connectboard, rows, columns, 'R');
			std::cout << "\n";
			printBoard(connectboard, rows, columns);
			checkWinner(connectboard, rows, columns);
			playerturn++;
		}
		if (playerturn == 2 && g_winner == false)
		{
			std::cout << g_username2 << "'s turn !\n\n";
			connectboard = fillBoard(connectboard, rows, columns, 'Y');
			std::cout << "\n";
			printBoard(connectboard, rows, columns);
			checkWinner(connectboard, rows, columns);
			playerturn--;
		}

		//check if the last row of the game is full and declare a tie
		int fillcount{};
		for (int columncount = 0; columncount <= columns; ++columncount)
			if (connectboard[rows][columncount] != 0)
			{
				fillcount++;
				if (fillcount == columns)
				{
					std::cout << "The Connect 4 game is a TIE.\n";
					g_winner = true;
				}
			}
	}

	//delete the allocated heap for 2D array
	for (int count = 0; count < rows; ++count)
		delete[] connectboard[count];
	delete[] connectboard;
}

// Function to get Username
std::string getName(int usernumber)
{
	std::string username;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Please enter the name of Player " << usernumber << " (without spaces) : ";
	std::cin >> username;
	std::cout << "\n";
	return username;
}

//Function to get column

int getColumn(const int &columns)
{
	while (true) // Loop until user enters a valid input
	{
		int selectcolumn{};
		std::cout << "Please select the column you want to drop the your peg: ";
		std::cin >> selectcolumn;

		if (selectcolumn > 0 && selectcolumn <= columns + 1)
			return selectcolumn - 1;
		else
			std::cout << "Oops, that column does not exist.  Please try again.\n";
	}
}

//Function to fill the board
char** fillBoard(char **boardarray, const int &rows, const int &columns, const char &peg)
{
	while (true)
	{
		int selectcolumn = getColumn(columns);
		for (int rowcount = 0; rowcount <= rows; ++rowcount)
		{
			if (boardarray[rowcount][selectcolumn] == 0)
			{
				boardarray[rowcount][selectcolumn] = peg;
				return boardarray;
			}
			else if (rowcount == rows)
				std::cout << "The column is full. Please select another column to drop your peg.\n";
		}
	}
}

//Print the current status of the Connect 4 Game Board
void printBoard(char **boardarray, const int &rows, const int &columns)
{
	for (int rowcount = rows; rowcount >= 0; --rowcount)
	{
		for (int columncount = 0; columncount <= columns; ++columncount)
			std::cout << boardarray[rowcount][columncount] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

//Check the ConnectBoard to see if there is a winner
void checkWinner(char **boardarray, const int &rows, const int &columns)
{
	//Check for Rows patten and see if there is a winner
	int player1{}, player2{};
	for (int rowcount = 0; rowcount <= rows; ++rowcount)
		for (int columncount = 0; columncount <= columns; ++columncount)
		{
			if (boardarray[rowcount][columncount] == 'R')
			{
				player1++;
				player2 = {};
				if (player1 == 4)
				{
					std::cout << "Congragulations! " << g_username1 << " is the WINNER !";
					g_winner = true;
				}
			}
			else if (boardarray[rowcount][columncount] == 'Y')
			{
				player2++;
				player1 = {};
				if (player2 == 4)
				{
					std::cout << "Congragulations! " << g_username2 << " is the WINNER !";
					g_winner = true;
				}
			}
		}

	//Check for Column Pattern and see if there is a winner
	player1 = 0; //reinitialize to 0;
	player2 = 0; //reinitialize to 0;
	for (int columncount = 0; columncount <= columns; ++columncount)
		for (int rowcount = 0; rowcount <= rows; ++rowcount)
		{
			if (boardarray[rowcount][columncount] == 'R')
			{
				player1++;
				player2 = {};
				if (player1 == 4)
				{
					std::cout << "Congragulations! " << g_username1 << " is the WINNER !";
					g_winner = true;
				}
			}
			else if (boardarray[rowcount][columncount] == 'Y')
			{
				player2++;
				player1 = {};
				if (player2 == 4)
				{
					std::cout << "Congragulations! " << g_username2 << " is the WINNER !";
					g_winner = true;
				}
			}
		}

	//Check for leftbottom to righttop diagonal and see if there is a winner "--> / <---"

	player1 = 0; //reinitialize to 0;
	player2 = 0; //reinitialize to 0;
	for (int rowcount = 0; rowcount <= rows; ++rowcount)
		for (int columncount = 0; columncount <= columns; ++columncount)
		{
			player1 = 0; //reinitialize to 0;
			player2 = 0; //reinitialize to 0;
			for (int rowstart = rowcount, columnstart = columncount; (rowstart < rowcount + 4 && rowstart <= rows) && (columnstart < columncount + 4 && columnstart <= columns); rowstart++, columnstart++)
			{
				if (boardarray[rowstart][columnstart] == 'R')
				{
					player1++;
					player2 = {};
					if (player1 == 4)
					{
						std::cout << "Congragulations! " << g_username1 << " is the WINNER !";
						g_winner = true;
					}
				}
				else if (boardarray[rowstart][columnstart] == 'Y')
				{
					player2++;
					player1 = {};
					if (player2 == 4)
					{
						std::cout << "Congragulations! " << g_username2 << " is the WINNER !";
						g_winner = true;
					}
				}
			}
		}

	//Check for lefttop to rightbottom diagonal and see if there is a winner "--> \ <---"

	player1 = 0; //reinitialize to 0;
	player2 = 0; //reinitialize to 0;
	for (int rowcount = rows; rowcount >= 0; --rowcount)
		for (int columncount = 0; columncount <= columns; ++columncount)
		{
			player1 = 0; //reinitialize to 0;
			player2 = 0; //reinitialize to 0;
			for (int rowstart = rowcount, columnstart = columncount; (rowstart > rowcount - 4 && rowstart >= 0) && (columnstart < columncount + 4 && columnstart <= columns); rowstart--, columnstart++)
			{
				if (boardarray[rowstart][columnstart] == 'R')
				{
					player1++;
					player2 = {};
					if (player1 == 4)
					{
						std::cout << "Congragulations! " << g_username1 << " is the WINNER !";
						g_winner = true;
					}
				}
				else if (boardarray[rowstart][columnstart] == 'Y')
				{
					player2++;
					player1 = {};
					if (player2 == 4)
					{
						std::cout << "Congragulations! " << g_username2 << " is the WINNER !";
						g_winner = true;
					}
				}
			}
		}
}