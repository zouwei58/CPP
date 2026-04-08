#include <iostream>
using namespace std;


//对象调用const成员函数
//class Date {
//public:
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//	// void Print() ---->  void Print(Date* this)
//	//void Print() const -----> void Print(const Date* this)
//
//	// const Date* p1  ----> *p1  //修饰的指向的内容，const在*前面修饰指针指向的值，后面修饰指针
//	//Date const * p2  ----> *p2
//	//Date* const p3   ----> p3
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//		//不能再修改成员变量了，因为const修饰保护了*this
//		//this->_year = 10;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void f(const Date& d)
//{
//	d.Print();
//}
//
//int main()
//{
//	Date d1(2026, 4, 4);
//	f(d1);
//	d1.Print();
//	return 0;
//}


//成员函数调用const成员函数
class Date {
public:

	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//
	void f1()  //void f1(Date* this)
	{
		f2();  //this->f2(this)   //可以，属于权限缩小
	}

	void f2() const
	{

	}

	void f3()  //void f3(const Date* this)
	{

	}

	void f4() const  //void f4(const Date* this)
	{
		//f3();   //this->f(this)  //不行属于权限放大
	}

	Date* operator&()
	{
		cout << "Date* operator&()" << endl;
		return this;
	}

	const Date* operator&() const
	{
		cout << "const Date* operator&() const" << endl;
		return this;
	}







private:
	int _year;
	int _month;
	int _day;
};



int main()
{
	Date d1;
	Date d2;
	const Date d3;
	cout << &d1 << endl;
	cout << &d1 << endl;
	cout << &d3 << endl;
	return 0;
}