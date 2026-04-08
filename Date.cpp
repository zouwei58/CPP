/*#include <iostream>
#include "Date.h"
using namespace std;

int Date::GetMonthDay(int year, int month) const
{
	static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	return MonthDay[month];
}

Date::Date(int year, int month, int day) {
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "illegal date" << endl;
		_year = 0;
		_month = 1;
		_day = 1;
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

bool Date::operator==(const Date& d) const
{
	return (_year == d._year && _month == d._month && _day == d._day);
}

bool Date::operator>(const Date& d) const
{
	return (_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}

bool  Date::operator>=(const Date& d) const
{
	return (*this == d) || (*this > d);
}

bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date Date::operator+=(int day)
{
	if (day < 0)
	{
		return (*this -= -day);
	}

	_day = _day + day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day = _day - GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day = _day - day;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day = _day + GetMonthDay(_year, _month);
	}
	return *this;
}

Date& Date::operator++()
{
	(*this) += 1;
	return *this;
}

Date Date::operator++(int)  
{
	Date tmp(*this);
	*this += 1;
	return tmp; 
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this); 
	*this -= 1;
	return tmp; 
}

int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date min = *this;
	Date max = d;
	int day = 0;
	if (*this > d)
	{
		min = d;
		max = *this;
		flag = -1;
	}
	while (min < max)
	{
		min++;
		++day;
	}
	return day * flag;
}

Date::~Date() {};

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

void Fun(const Date& d3, const Date& d4)
{
	cout << d3 - d4 << endl;
	cout << (d3 > d4) << endl;
}

//int main()
//{
//	Date d1(2026, 4, 6);
//	Date d2(23, 4, 6);
//	Fun(d1,d2);
//	cout << d2 - d1 << endl;
//	return 0;
//}



/*class Date {
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
	//函数体内赋值
		_year = year;
		_month = month;
		_day = day;
	}

	Date(int year = 0, int month = 1, int day = 1)
	    :_year(year)
		,_month(month)
		,_day(day)
		{
		  //初始化列表
		}


private:
	int _year;
	int _month;
	int _day;
};*/
