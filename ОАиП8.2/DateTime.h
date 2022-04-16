
#pragma once
#include <string>

class DateTime
{
private:
	static const int MIN_DAY;
	static const int MAX_DAYS[];
	static const int MIN_MONTH;
	static const int MAX_MONTH;
	static const int MIN_YEAR;
	static const int MAX_YEAR;
	static const int MIN_HOUR;
	static const int MAX_HOUR;
	static const int MIN_MINUTE;
	static const int MAX_MINUTE;
	static const int MIN_SECOND;
	static const int MAX_SECOND;

	static const std::string INPUT_OUT_OF_RANGE_MEASSGE;

	int m_day;
	int m_month;
	int m_year;
	int m_hour;
	int m_minute;
	int m_second;

	static int ScanComponent(const std::string& message);

public:
	DateTime(int day, int month, int year, int hour, int minute, int second);

	DateTime();

	int GetDay();

	int GetMonth();

	int GetYear();

	int GetHour();

	int GetMinute();

	int GetSecond();

	bool IsGreaterThan(DateTime& other);

	std::string ToString();

	void Print();

	static DateTime Scan();

	static DateTime Scan(const std::string& header);
};
