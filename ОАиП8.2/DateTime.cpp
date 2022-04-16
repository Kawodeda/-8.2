
#include "DateTime.h"
#include "StringUtil.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stdexcept>

const int DateTime::MIN_DAY = 1;
const int DateTime::MAX_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int DateTime::MIN_MONTH = 1;
const int DateTime::MAX_MONTH = 12;
const int DateTime::MIN_YEAR = 1;
const int DateTime::MAX_YEAR = 9999;
const int DateTime::MIN_HOUR = 0;
const int DateTime::MAX_HOUR = 23;
const int DateTime::MIN_MINUTE = 0;
const int DateTime::MAX_MINUTE = 59;
const int DateTime::MIN_SECOND = 0;
const int DateTime::MAX_SECOND = 59;

const std::string DateTime::INPUT_OUT_OF_RANGE_MEASSGE = "The input was out of range";

DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
{
	if (month < MIN_MONTH || month > MAX_MONTH
		|| day < MIN_DAY || day > MAX_DAYS[month - 1]
		|| year < MIN_YEAR || year > MAX_YEAR
		|| hour < MIN_HOUR || hour > MAX_HOUR
		|| minute < MIN_MINUTE || minute > MAX_MINUTE
		|| second < MIN_SECOND || second > MAX_SECOND)
	{
		throw std::out_of_range(INPUT_OUT_OF_RANGE_MEASSGE);
	}

	m_day = day;
	m_month = month;
	m_year = year;
	m_hour = hour;
	m_minute = minute;
	m_second = second;
}

DateTime::DateTime() : DateTime(1, 1, 1, 0, 0, 0) {}

int DateTime::GetDay()
{
	return m_day;
}

int DateTime::GetMonth()
{
	return m_month;
}

int DateTime::GetYear()
{
	return m_year;
}

int DateTime::GetHour()
{
	return m_hour;
}

int DateTime::GetMinute()
{
	return m_minute;
}

int DateTime::GetSecond()
{
	return m_second;
}

bool DateTime::IsGreaterThan(DateTime& other)
{
	if (m_year != other.GetYear())
	{
		return m_year > other.GetYear();
	}
	else if (m_month != other.GetMonth())
	{
		return m_month > other.GetMonth();
	}
	else if (m_day != other.GetDay())
	{
		return m_day > other.GetDay();
	}
	else if (m_hour != other.GetHour())
	{
		return m_hour > other.GetHour();
	}
	else if (m_minute != other.GetMinute())
	{
		return m_minute > other.GetMinute();
	}
	else if(m_second != other.GetSecond())
	{
		return m_second > other.GetSecond();
	}
	else
	{
		return false;
	}
}

std::string DateTime::ToString()
{
	const std::string YEAR_TEMPLATE = "0000";
	const std::string MONTH_TEMPLATE = "00";
	const std::string DAY_TEMPLATE = "00";
	const std::string HOUR_TEMPLATE = "00";
	const std::string MINUTE_TEMPLATE = "00";
	const std::string SECOND_TEMPLATE = "00";

	return RightInsert(HOUR_TEMPLATE, m_hour)
		+ ':' + RightInsert(MINUTE_TEMPLATE, m_minute)
		+ ':' + RightInsert(SECOND_TEMPLATE, m_second)
		+ ' ' + RightInsert(DAY_TEMPLATE, m_day)
		+ '.' + RightInsert(MONTH_TEMPLATE, m_month)
		+ '.' + RightInsert(YEAR_TEMPLATE, m_year);
}

void DateTime::Print()
{
	std::cout << this->ToString();
}

int DateTime::ScanComponent(const std::string& message)
{
	std::cout << message;
	int value = 0;
	std::cin >> value;

	return value;
}

DateTime DateTime::Scan(const std::string& header)
{
	std::cout << std::endl << "Enter the date" + header + ':' << std::endl;

	int day = ScanComponent("Day = ");
	int month = ScanComponent("Month = ");
	int year = ScanComponent("Year = ");
	int hour = ScanComponent("Hour = ");
	int minute = ScanComponent("Minute = ");
	int second = ScanComponent("Second = ");

	DateTime result(day, month, year, hour, minute, second);
	return result;
}

DateTime DateTime::Scan()
{
	return DateTime::Scan("");
}
