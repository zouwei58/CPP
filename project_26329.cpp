//#include <iostream>
//using namespace std;
//class Stack {
//public:
//	//对象创建时自动调用完成初始化工作
//	Stack(int n = 0)
//		{
//			_a = (int*)malloc(sizeof(int) * n);
//			_size = 0;
//			_capacity = 0;
//		}
//	//对象周期到了以后，完成清理工作
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//	void push();
///// <summary>
/////.....
///// </summary>
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//class Date
//{
//public:
	
/*	Date()
	{
		_year = 0;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/

	//Date(int year = 0, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}

	//~Date() {
	//	cout << "~Date()" << endl;
	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	//内置类型/基本类型 int/char 不会处理
//	//自定义类型 调用他的构造函数初始化
//
//};
//
//
//int main()
//{
//	Date d1;  // 1、我们不写编译器生成  2、全缺省  3、无参数 -> 默认构造函数 ->不传参就可以调用的
//	//Date d2(2026, 3, 29);
//	return 0;
//}

//class Date {
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//
//	 }
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//Date(Date d)
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////bool IsDateEqual(const Date& d1, const Date& d2)
////	{
////		return (d1._year == d2._year && d1._month == d2._month && d1._day == d2._day);
////	}
////运算符重载
//bool operator==(const Date& d1, const Date& d2)
//{
//	return (d1._year == d2._year && d1._month == d2._month && d1._day == d2._day);
//}
//
//
////void func(Date d)
////{
////
////}
//
////
//
////自定义函数是不能用运算符的，要用就得实现函数重载，自定义类型用的时候等价于调用这个重载函数
//int main()
//{
//	Date d1(2026,3,30);
//	Date d2(d1);
//	Date d3 = d1;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//	//如果Date的对象想比较大小
//	//if (IsDateEqual(d1, d2)) {
//	//	printf("d1 = d2 \n");
//	//}
//	//else {
//	//	printf("d1 = d2 \n");
//	//}
//	if (d1 == d2) {         //  编译如何调用--->这里编译会转换成operator==(d1,d2)；所以这里就是一个函数调用
//		printf("d1 = d2 \n");
//	}
//	else {
//		printf("d1 = d2 \n");
//	}
//	//但是我们一般不会这样写，因为这样可读性不好
//	operator==(d1,d2);
//
//	//func(d1);
//	return 0;
//}




//
//#include <iostream>
//#include <string.h>
//using namespace std;
//
//class Date {
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//
//	 }
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//Date(Date d)
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//运算符重载   //---->bool operator(Date* this,const Date& d)
//	bool operator==(const Date& d) const
//	{
//		return (_year == d._year && _month == d._month && _day == d._day);
//		//return (this->_year == d._year && this->_month == d._month && this->_day == d._day);
//	}
//
//	bool operator>(const Date& d)
//	{
//		return (_year == d._year && _month == d._month && _day > d._day)
//			|| (_year == d._year && _month > d._month)
//			|| (_year > d._year);
//	}
//
//	//void Print_Compare(const Date& d,const string& name1,const string& name2 )
//	//{
//	//	if (*this > d) 
//	//	{
//	//		cout << name1 << ">" << name2 << endl;
//	//	}
//	//	else {
//	//		cout << name1 << "<=" << name2 << endl;
//	//	}
// //   }
//
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////自定义函数是不能用运算符的，要用就得实现函数重载，自定义类型用的时候等价于调用这个重载函数
//int main()
//{
//	Date d1(2026,3,30);
//	Date d2(d1);
//	Date d3 = d1;
//	Date d4(2026, 3, 31);
//	Date d5(2024, 4, 1);
//	Date d6(2027, 3, 30);
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//d1 == d2;
//	if (d1 == d2) {         
//		printf("d1 = d2 \n");
//	}
//	else {
//		printf("d1 != d2 \n");
//	}
//	d1.operator==(d2);  //--->编译器转化为d1.operator==(d2)
//
//	if (d1 > d4) {
//		printf("d1 > d4 \n");
//	}
//	else {
//		printf("d1 <= d4 \n");
//	}
//
//	//d1.Print_Compare(d4,"d1","d4");
//	//d1.Print_Compare(d5, "d1", "d5");
//	//d1.Print_Compare(d6, "d1", "d6");
//
//	return 0;
//}


//实现一个完善的日期类
#include <iostream>
#include <string.h>
using namespace std;

class Date {
public:
	//获取当月天数
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return MonthDay[month];
	}

	//构造函数
	Date(int year = 0, int month = 1, int day = 1){
		if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year,month))
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

	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


   //运算符重载
   //==
	bool operator==(const Date& d) const
	{
		return (_year == d._year && _month == d._month && _day == d._day);
	}

	//>
	bool operator>(const Date& d) const
	{
		return (_year > d._year) 
			|| (_year == d._year && _month > d._month) 
			|| (_year == d._year && _month == d._month && _day > d._day);
	}

	//>=
    bool  operator>=(const Date& d) const
	{
		return (*this == d) || (*this > d);
	}

	//<
	bool operator<(const Date& d) const
	{
		return !(*this >= d);
	}

	//<=
	bool operator<=(const Date& d) const
	{
		return !(*this > d);
	}

	//!=
	bool operator!=(const Date& d) const
	{
		return !(*this == d);
	}

	//日期+
	Date operator+(int day) 
	{
		Date ret(*this);
		//Date ret = *this;
		ret._day = ret._day + day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day = ret._day - GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	//日期+=
	Date operator+=(int day)
	{
	
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

	//-
	Date operator-(int day)
	{
		Date ret(*this);
		//Date ret = *this;
		ret._day = ret._day - day;
		while (ret._day < 1)
		{
			ret._month--;
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
			ret._day = ret._day + GetMonthDay(ret._year, ret._month);
		}
		return ret;
	}

	//日期-=
	Date operator-=(int day)
	{
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

	//日期++
	Date operator++()
	{
		_day++;
		if (_day > GetMonthDay(_year, _month))
		{
			_day = 1;
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}

	//日期--
	Date operator--()
	{
		_day--;
		if (_day < 1)
		{
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		return *this;
	}

	//print_campare
	void Print_Compare(const Date& d,const string& name1,const string& name2)
	{
		if (*this < d)
		{
			cout << name1 << "<" << name2 << endl;
		}
		else {
			cout << name1 << ">=" << name2 << endl;
		}
	}

	//析构函数
	~Date()
	{

	}

	void Print() 
	{
			cout << _year << "-" << _month << "-" << _day << endl;
	} 


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2026,3,31);
	d1.Print();
	Date d2(2020, 4, 31);
	d2.Print();
	d1.Print_Compare(d2,"d1","d2");
	Date d4 = d1 + 10;
	Date d5 = d1 + 100;
	d1 += 1000;
	d1.Print();
	Date d6 = d1 - 100;
	d1 -= 1000;
	d4.Print();
	d5.Print();
	d6.Print();
	d1.Print();
	return 0;
}
