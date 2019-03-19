/*
HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity.
If the amount spent by a client on a particular day is greater than or equal to 2x the client's median spending for a trailing number of days, they send the client a notification about potential fraud.
The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.
Given the number of trailing days d and a client's total daily expenditures for a period of n days, find and print the number of times the client will receive a notification over all n days.
*/

//Include the header files required by this program
#include "pch.h" //Remove if you are not using visual studio 2017
#include <iostream> //for input output streams

//Create a class for fradulant notifications
class FraudNotification
{
private:
	int m_totaldays, m_trailingdays;
	int *m_transactions = new int[m_totaldays] {};
public:
	FraudNotification(const int &totaldays, const int &trailingdays) : m_totaldays(totaldays), m_trailingdays(trailingdays) {}

	//get the total expenditure of the user
	void getExpenditure()
	{
		std::cout << "Please enter the expenditure seperated by spaces: ";
		for (int count = 0; count < m_totaldays; ++count)
			std::cin >> m_transactions[count];
	}

	//get the total number of notifications
	int notifications()
	{
		int notifications{};
		for (int startindex = 0; startindex < m_trailingdays - 1; ++startindex)
		{
			int median{}, sum{};
			int *sortedblock = new int[m_trailingdays];
			for (int currentindex = startindex, count = 0; currentindex < m_trailingdays, count < m_trailingdays; ++currentindex, ++count)
				sortedblock[count] = m_transactions[currentindex];

			median = getmedian(sortedblock, m_trailingdays);

			if (m_transactions[startindex + m_trailingdays] > median * 2)
				notifications++;

			delete[] sortedblock;
		}
		return notifications;
	}

	//get median of subarray/ any array
	int getmedian(int *userarray, const int &size)
	{
		int median{};
		for (int startindex = 0; startindex < size - 1; ++startindex)
		{
			int smallestindex{};
			for (int currentindex = startindex; currentindex < size; ++currentindex)
				if (userarray[currentindex] < userarray[smallestindex])
					smallestindex = currentindex;
			if (smallestindex != startindex)
				std::swap(userarray[startindex], userarray[smallestindex]);
		}

		if (size % 2 == 0)
			return median = (userarray[size / 2] + userarray[(size / 2) - 1]) / 2;
		else
			return median = userarray[size / 2];
	}

	//delete the constructor and array requested from heap memory cleanup
	~FraudNotification()
	{
		delete[] m_transactions;
	}
};


//Main function
int main()
{
	//get inputs from the user
	int totaldays{}, trailingdays{}, totalnotifications{};
	std::cout << "Please enter the number of days of transaction data, and the number of trailing days of data seperated by spaces: ";
	std::cin >> totaldays >> trailingdays;

	FraudNotification hackerLandNB(totaldays, trailingdays);
	hackerLandNB.getExpenditure();

	//get total notifications and print the output
	totalnotifications = hackerLandNB.notifications();

	std::cout << "There are total of " << totalnotifications << " of fraudulant actitvity notifications int the last " << totaldays << " days.";

	return 0;

}