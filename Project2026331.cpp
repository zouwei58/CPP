#include <iostream>
using namespace std;

//class Stack {
//public:
//	Stack(int n = 0)
//	{
//		_a = (int*)malloc(sizeof(int) * n);
//		_size = 0;
//		_capacity = n;
//	}
//
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity;
//	}
//
//
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
//int main()
//{
//	//cpp
//	Stack st(10);
//	//C
//	//StackInit();
//	// ....
//	//StackDestory();
//	return 0;
//}

//class Date {
//public:
//	//构造函数
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//拷贝构造
//	//Date d2(d1);
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//运算符重载
//	//赋值运算符=
//	//d3 = d1;
//	void operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//
//	//析构函数
//	~Date()
//	{
//
//
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//int main()
//{
//
//	Date d1(2026, 4, 1);
//	Date d2(d1);
//	d1.Print();
//	d2.Print();
//	Date d3 = d1;
//	d3.Print();
//
//
//	return 0;
//}

//拷贝构造和赋值重载是6个默认成员函数之一，我们不实现编译器会帮我们实现一份

//我们不实现时，编译器生成拷贝构造和operator=,会完成按字节的值拷贝(浅拷贝)
//也就是说有些类，我们是不需要去实现拷贝构造和operator=的，因为编译器默认生成就可以用
//比如: Date就是这样




class Stack {
public:
	Stack(int n)
	{
		_a = (int*)malloc(sizeof(int) * n);
		_size = 0;
		_capacity = n;
	}

	~Stack()
	{
		free(_a);
		_size = _capacity = 0;
	}
private:
	int* _a;
	size_t _size;
	size_t _capacity;
};

int main()
{
	Stack st1(10);
	
	/*
	Stack st2 = st1;
	如果加上的话
	st2析构 free(st2._a)
	st2析构 free(st1._a)
	同一块空间释放两次导致崩溃
	*/

	return 0;
}