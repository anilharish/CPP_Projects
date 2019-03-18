/*
Comparators are used to compare two objects. In this challenge, you'll create a comparator and use it to sort an array. The Player class has two fields:
1. name: a string.
2. score: an integer.
Given an array of  Player objects, write a comparator that sorts them in order of decreasing score. If  or more players have the same score, sort those players alphabetically ascending by name.
To do this, you must create a Checker class that implements the Comparator interface, then write an int compare(Player a, Player b) method implementing the Comparator.compare(T o1, T o2) method.
*/

//Include the header files required by this program
#include "pch.h" //remove if you are using visual studio 2017
#include <iostream> //print input and output stream to the terminal
#include <string> //for std::string
#include <utility> //for std::swap

//create a datastructure for player names and scores 
class PlayerScores
{
public:
	std::string m_name;
	int m_score;

	//constructor to get player names and scores
	PlayerScores()
	{
		std::cout << "Please enter the name of the player: ";
		std::cin >> m_name;
		std::cout << "Please enter the score of the player: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> m_score;
	}

	//function to print thier names and scores
	void printNamesAndScores()
	{
		std::cout << m_name << " " << m_score << "\n";
	}
};

//forward declarations of the function in the program
void sortScores(PlayerScores* namesandscores, const int &totalplayers);
void sortNames(PlayerScores* namesandscores, const int &totalplayers);
void printOutput(PlayerScores* namesandscores, const int &totalplayers);

//main function
int main()
{
	//get total number of players
	int totalplayers{};
	std::cout << "Please enter the total number of players in the team: ";
	std::cin >> totalplayers;
	PlayerScores *baseball = new PlayerScores[totalplayers];//create a dynamic array of baseball players and scores

	//sort names and socres of the baseball players
	sortScores(baseball, totalplayers);
	sortNames(baseball, totalplayers);

	//print the output of the sorted baseball players based on ascending names and decending scores
	printOutput(baseball, totalplayers);

	//delete the dynamic array for baseball
	delete[] baseball;

	return 0;
}

//sort the players based on decending order using selection sort
void sortScores(PlayerScores* namesandscores, const int &totalplayers)
{
	for (int startindex = 0; startindex < totalplayers - 1; ++startindex)
	{
		int biggestindex = startindex;
		for (int currentindex = startindex + 1; currentindex < totalplayers; ++currentindex)
		{
			if (namesandscores[currentindex].m_score > namesandscores[startindex].m_score)
				biggestindex = currentindex;
		}
		if (biggestindex != startindex)
			std::swap(namesandscores[startindex], namesandscores[biggestindex]);
	}
}

//sort the names only if scores are equal using bubble sort
void sortNames(PlayerScores* namesandscores, const int &totalplayers)
{
	for (int startindex = 0; startindex < totalplayers - 1; ++startindex)
		for (int currentindex = 0; currentindex < totalplayers - 1; ++currentindex)
		{
			if (namesandscores[currentindex].m_score == namesandscores[currentindex + 1].m_score)//check if scores are equal first
			{
				std::string name1, name2;
				name1 = namesandscores[currentindex].m_name;
				name2 = namesandscores[currentindex + 1].m_name;

				int smallestname{}; //check for smallest name
				(name1.size() > name2.size()) ? smallestname = name2.size() : smallestname = name1.size();

				bool sortcomplete{};
				int nameindex{};
				while (sortcomplete == false && nameindex <= smallestname) // to check for all letters of their name
				{
					if (name2[nameindex] > name1[nameindex])
						sortcomplete = true;
					if (name2[nameindex] < name1[nameindex])
					{
						std::swap(namesandscores[currentindex], namesandscores[currentindex + 1]);//swap if the char equivalent is less
						sortcomplete = true;
					}
					if (name2[nameindex] == name1[nameindex])
						nameindex++;
				}
			}
		}
}

//Print the output of the sorted class of playersores
void printOutput(PlayerScores* namesandscores, const int &totalplayers)
{
	std::cout << "The sorted player based on names and scores are: \n";
	for (int count = 0; count < totalplayers; ++count)
		namesandscores[count].printNamesAndScores();
}