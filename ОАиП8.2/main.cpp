
#include <iostream>
#include <string>
#include <stdexcept>
#include "DateTime.h"

template<typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

void SortDates(DateTime* dates, size_t numberOfDates)
{
	for (size_t i = 0; i < numberOfDates - 1; ++i)
	{
		bool isSorted = true;

		for (size_t j = 0; j < numberOfDates - i - 1; ++j)
		{
			if (dates[j].IsGreaterThan(dates[j + 1]))
			{
				Swap<DateTime>(dates[j], dates[j + 1]);
				isSorted = false;
			}			
		}

		if (isSorted)
		{
			break;
		}
	}
}

int main()
{
	try
	{
		std::cout << "Enter the number of dates: ";
		size_t numberOfDates = 0;
		std::cin >> numberOfDates;

		DateTime* dates = new DateTime[numberOfDates];
		for (size_t i = 0; i < numberOfDates; ++i)
		{
			dates[i] = DateTime::Scan('#' + std::to_string(i + 1));
			std::cout << "Result: " << dates[i].ToString() << std::endl;
		}

		SortDates(dates, numberOfDates);
		std::cout << std::endl << "Ordered by increasing:" << std::endl;
		for (size_t i = 0; i < numberOfDates; ++i)
		{
			std::cout << std::endl << dates[i].ToString() << std::endl;
		}
	}
	catch(std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		return -1;
	}

	return 0;
}
