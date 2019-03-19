/*
TicTacToe Game for any dimention
*/

#include "pch.h"
#include <iostream>
#include <string>

class TicTacToe
{
private:
	int m_boardsize;
	char **m_boardarray = new char*[m_boardsize];
	std::string m_username1, m_username2;
	bool winner{};

	void initialize()
	{
		for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
			for (int colcount = 0; colcount < m_boardsize; ++colcount)
				m_boardarray[rowcount][colcount] = '_';
	}


	void fillBoard(const char &playertoken)
	{
		int row{}, column{};
		bool checkinput{};

		while (checkinput == false)
		{
			std::cout << "Please enter the Row and Column you want to insert your token seperated by spaces: ";
			std::cin >> row >> column;

			if (row > m_boardsize || column > m_boardsize)
				std::cout << "Oops the cell entered does not exist. Please try again.\n";
			else if (m_boardarray[row - 1][column - 1] != '_')
				std::cout << "Oops this cell is already full. Please try again.\n";
			else
			{
				m_boardarray[row - 1][column - 1] = playertoken;
				checkinput = true;
			}
		}
	}

	void checkDraw()
	{
		for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
			for (int colcount = 0; colcount < m_boardsize; ++colcount)
			{
				if (m_boardarray[colcount][rowcount] == '_')
					return;
			}
		winner = true;
		std::cout << "This Game is a tie.\n";
	}

	void checkWinner()
	{
		checkDraw();

		int usercount1{}, usercount2{};
		for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
		{
			usercount1 = usercount2 = 0;
			for (int colcount = 0; colcount < m_boardsize; ++colcount)
				getPattern(rowcount, colcount, usercount1, usercount2);
		}

		for (int colcount = 0; colcount < m_boardsize; ++colcount)
		{
			usercount1 = usercount2 = 0;
			for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
				getPattern(rowcount, colcount, usercount1, usercount2);
		}

		usercount1 = usercount2 = 0;

		for (int rowcount = 0, colcount = 0; rowcount < m_boardsize, colcount < m_boardsize; ++rowcount, ++colcount)
			getPattern(rowcount, colcount, usercount1, usercount2);

		usercount1 = usercount2 = 0;

		for (int rowcount = 0, colcount = m_boardsize - 1; rowcount < m_boardsize, colcount >= 0; ++rowcount, --colcount)
			getPattern(rowcount, colcount, usercount1, usercount2);
	}

	void getPattern(const int &row, const int &column, int &count1, int &count2)
	{
		if (m_boardarray[row][column] == 'X')
		{
			count1++;
			if (count1 == m_boardsize)
			{
				std::cout << "Congragulations!!! " << m_username1 << " is the WINNER! \n";
				winner = true;
			}
		}
		if (m_boardarray[row][column] == 'O')
		{
			count2++;
			if (count2 == m_boardsize)
			{
				std::cout << "Congragulations!!! " << m_username2 << " is the WINNER! \n";
				winner = true;
			}
		}
		if (count1 > 0 && count2 > 0)
			return;
	}

public:
	TicTacToe(const int &size, const std::string &user1, const std::string &user2) : m_boardsize(size), m_username1(user1), m_username2(user2)
	{
		for (int count = 0; count < m_boardsize; ++count)
			m_boardarray[count] = new char[m_boardsize];

		for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
			for (int colcount = 0; colcount < m_boardsize; ++colcount)
				m_boardarray[rowcount][colcount] = '_';
	}

	void startGame()
	{
		std::cout << "Starting TIC TAC TOE of Size " << m_boardsize << " \n";
		printBoard();
		int playerturn{};
		bool playerselect{};
		while (playerselect == false)
		{
			std::cout << "Player Select - Select (1) for " << m_username1 << " or Select (2) for " << m_username2 << " : ";
			std::cin >> playerturn;
			if (playerturn == 1 || playerturn == 2)
				playerselect = true;
			else
				std::cout << "Incorrect selection. Please try again.\n";
		}
		while (winner == false)
		{
			if (playerturn == 1 && winner == false)
			{
				std::cout << m_username1 << "'s turn\n";
				fillBoard('X');
				printBoard();
				checkWinner();
				playerturn++;
			}
			if (playerturn == 2 && winner == false)
			{
				std::cout << m_username2 << "'s turn\n";
				fillBoard('O');
				printBoard();
				checkWinner();
				playerturn--;
			}
		}
	}

	void printBoard()
	{
		for (int rowcount = 0; rowcount < m_boardsize; ++rowcount)
		{
			for (int colcount = 0; colcount < m_boardsize; colcount++)
				std::cout << m_boardarray[rowcount][colcount] << " ";
			std::cout << "\n";
		}
		std::cout << "\n";
	}

	void restart()
	{
		winner = false;
		initialize();
		startGame();
	}

	~TicTacToe()
	{

		for (int count = 0; count < m_boardsize; ++count)
			delete[] m_boardarray[count];
		delete[] m_boardarray;
	}
};

int main()
{
	int gamesize{};
	std::cout << "Please input the size of the boardgame: ";
	std::cin >> gamesize;

	std::string username1, username2;
	std::cout << "Please enter the name of Player 1: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> username1;
	std::cout << "You have been assinged 'X' tokens.\n";
	std::cout << "Please enter the name of Player 2: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> username2;
	std::cout << "You have been assinged 'O' tokens.\n";

	TicTacToe newGame(gamesize, username1, username2);
	newGame.startGame();

	std::string restart;
	std::cout << " Do you want to restart the game ? Press (Y) for yes and (N) for no: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> restart;

	if (restart == "Y")
		newGame.restart();
	else
		std::cout << "Thank you for playing TIC TAC TOE !";

	return 0;
}
