//#include <iostream>
//using namespace std;
//
////声明和定义的区别? 声明是一种承诺，承诺要干嘛，但是还没做，定义就是把这个事落地了
//
//
////如何定义成一个类
////封装
//// 1. 将数据和方法定义到一起 。
//// 2. 把想给你看到的数据给你看，不想给你看的封装起来  -->  访问限定符
//class Stack
//{
//	//类的定义有两种
//	//1.成员函数
//	//(一)在类里面定义
//public:
//	void Push(int x)
//	{
//		//...
//	}
//	//void Push(int x);
//	void Pop();  //(二)在类里面声明，在类外面定义
//	bool Empty();  //这里是声明
//	//...
//	//2.成员变量
//private:
//	int* _a;
//	int _size;
//	int _capacity;  //这里是声明
//};
//
////在类外面定义
//void Stack::Pop()  //得指定Pop是属于Stack这个类的
//{
//	//...
//}
//
////1.C语言中struct是用来定义结构体的
////2.C++中,兼容C的struct定义结构体的用法，但是同时struct也可以用来定义类
////3.c++中使用class和struct定义类的区别? ->  默认的访问限定符
//struct ListNode_C
//{
//	int _val;
//	struct ListNode_C* _next;
//	struct ListNode_C* _prev;
//};
//
//struct ListNode_CPP
//{
//	int _val;
//	ListNode_CPP* next;  //兼容C的用法
//	ListNode_CPP* prev;  //C++当成类的用法 
//
//	//还可以函数 -> 成员函数
//	ListNode_CPP* CreatNode(int val);
//};
//
////类中既有成员函数，又有成员变量
//class A1
//{
//public:
//	void f1();
//private:
//	int _a;
//	char _ch;
//};
//
////类中只有成员函数
//class A2
//{
//public:
//	void f2();
//};
//
////类中什么也没有 -- 空类
//class A3
//{
//};
//
//
//int main()
//{
//	//类实例化出对象
//	Stack s1;
//	Stack s2;
//	Stack s3;
//	s1.Push(1); 
//	s2.Push(2);
//	s3.Push(3);
//	//对象只存储成员变量，不存储成员函数，思考一下为什么?
//	//一个类实例化出N个对像，每个对象的成员变量都可以存储不同的值，但是调用的函数是同一个
//	//如果每个对象都放成员函数，而这些成员函数却是一样的。浪费空间
//
//	//如何计算一个类实例化出的对象的大小?计算成员变量之和，并且考虑内存对齐规则
//	//什么是内存对齐?
//	/*
//	* 结构体内存对齐规则
//	* 一、规则一：首成员偏移量为零
//	* 二、规则二：其他成员的对齐规则
//	* 除了第一个成员之外，其他所有成员在内存中存放时，起始地址必须是对齐数的整数倍。
//	* 对齐数 = min(编译器默认对齐数, 成员自身大小)
//	* 三、规则三：结构体总大小为最大对齐数的倍数
//	* 最大对齐数 = max(所有成员的对齐数)
//	* 结构体总大小 = 最大对齐数的倍数
//	* 四、规则四：嵌套结构体的对齐规则
//	* 1.嵌套的结构体本身要对齐到其内部最大对齐数的整数倍地址处
//	* 2.外层结构体的总大小必须是所有成员中最大对齐数（包括嵌套结构体内部的最大对齐数）的整数倍
//	* 
//	* 面试问题:
//	* 
//	* 问题一：结构体怎么对齐？为什么要进行内存对齐？
//	* 内存对齐的规则就是上面介绍的四个规则。进行内存对齐的主要原因有两个方面：
//	* 平台移植性：不同硬件平台对内存对齐的要求不同，未对齐的访问可能导致程序崩溃或产生不可预期的行为
//	* 硬件读取性能：现代处理器访问对齐的内存更加高效，CPU可以一次性读取多个字节，而不需要分多次访问
//	* 
//	* 
//	* 问题二：如何让结构体按照指定的对齐参数进行对齐？
//	* 可以使用预处理指令 #pragma pack(n) 来指定对齐参数，其中n可以是1、2、4、8等值。当设置为1时，结构体不会有任何填充。
//	* pragma pack(push, 1)
//    *   等价于：
//    *   1. 将当前对齐参数（通常是8）保存到栈中
//    *   2. 设置新的对齐参数为 1
//	* pragma pack(pop)
//    *   等价于：
//        从栈中弹出之前保存的对齐参数，恢复原来的设置
//    * 问题三：如何知道结构体中某个成员相对于结构体起始位置的偏移量？
//	* 可以使用标准库宏 offsetof 来获取成员偏移量：
//	* #include <stddef.h>
//	* struct Example {
//	*      char  a;
//	*      int   b;
//	*      char  c;
//	* };
//	* printf("offsetof(a) = %zu\n", offsetof(struct Example, a));  // 0
//	* printf("offsetof(b) = %zu\n", offsetof(struct Example, b));  // 4
//	* printf("offsetof(c) = %zu\n", offsetof(struct Example, c));  // 8
//	* 
//	* 问题四：什么是大小端？如何测试？
//	* 小端模式（Little Endian）
//	* 低位字节存放在低地址，高位字节存放在高地址
//	* 大端模式（Big Endian）
//	* 高位字节存放在低地址，低位字节存放在高地址
//	* 高位字节：0x12
//    * 次高位：0x34
//    * 次低位：0x56
//    * 低位字节：0x78
//	#include <stdio.h>
//
//    int main() {
//        int a = 0x12345678;    // ① 定义一个整数，值为 0x12345678
//        char *p = (char *)&a;  // ② 将整数地址强制转换为 char* 指针
//    
//        if (*p == 0x78) {      // ③ 读取指针 p 指向的字节（即最低地址的字节）
//            printf("小端模式\n");
//         } else if (*p == 0x12) {
//               printf("大端模式\n");
//           }
//     return 0;
//}
//	*/
//	//没有成员变量的类的大小是1，面试题: 为什么是1呢，而不是0?
//	//开一个字节不是为了存数据，而是为了占位，表示对象存在
//
//    cout << sizeof(s1) << endl;
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//
//	return 0;
//
//	
//}

//实例化 -> 就是用自己定义的类型定义出对象
//1、内置类型，基本类型 int/char/double(关键字)
//2、自定义类型，class/struct

//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//this是谁调用这个成员函数，this就指向谁
//	void Init(int year, int month, int day)   //void Init(Date* this,int year, int month, int day)
//	{
//
//		/* this->_year = year;
//		   this->_month = month;
//		   this->_day = day;*/
//
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()  //void Print(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//		//cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////1. this指针存在哪里？也就是存在进程空间的那个区域 -> 存在在栈上的，因为他是一个形参
//int main()
//{
//	Date d1;
//	d1.Init(2026, 3, 29);  //d1.Init(&d1,2026, 3, 29);
//	d1.Print();  //d1.Print(&d1);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//    void PrintA()  //传过来this是个空，this->_a
//    {
//        cout << _a << endl;  //this->a
//    }
//    void Print()
//    {
//        cout << "Print()" << endl;  //传过来this是个空,不会有任何问题
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = NULL;
//    p->PrintA();  // 这一行程序编译运行结果是？  A、编译报错  B、运行崩溃  C、正常运行  B
//    //p->Print();// 这一行程序编译运行结果是？  A、编译报错  B、运行崩溃  C、正常运行  C
//    //这里并没有解引用，因为我要调用PrintA()和Print()并不用去指针指向的这个对象里面去找，而是去公共代码段找
//    //
//    return 0;
//}
//
////p->Print()和p.Print()
///*
//变量是结构体本身p.Print()
//变量是结构体指针p->Print()
//p->Print()  等价于  (*p).Print()
//->就是*+.的简写
//*/

//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//构造函数 -> 在对象构造时调用函数，这个函数完成初始化工作
///*	函数名与类名相同
//	无返回值
//	对象实例化时编译器自动调用对应的构造函数
//	构造函数可以重载
//*/
//	Date(int year,int month,int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	//void Init(int year, int month, int day)   
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Print()  
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//实例化时，自动调用
//	Date d1(2026,3,28);
//	d1.Print();
//
//	Date d2;  //Date d2();不能加括号，加了括号编译器就不认识了(遇到不要纠结，记住就好)
//	d2.Print();
//
//
//	return 0;
//}


//5. 如果类中没有显式定义构造函数，
// 则C++编译器会自动生成一个无参的默认构造函数，
// 一旦用户显式定义编译器将不再生成。
//#include <iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	//我们没有显式定义构造函数们，这里编译器生成默认的无参的构造函数
//	//默认生成无参构造函数(语法坑:双标狗)
//	//1、针对内置类型(int\char...)w1的成员变量没有做处理
//	//2、针对自定义类型的成员变量，调用它的构造函数初始化
//	
//	//一旦用户显式定义编译器将不再生成。
//	//Date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Print()  
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
// //自定义类型
//    Time _t;
//};
//
//int main()
//{
//	Date d1;  //调用编译器生成的默认构造函数
//	d1.Print();
//
//	//Date d2(2020，3，8);
//	//d1.Print();
//
//
//	return 0;
//}

#include <iostream>
using namespace std;

//class Date
//{
//public:
///*	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	/*无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。
//	注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为
//	是默认构造函数。*/
//
//	//更好的方式 -> 全缺省
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//一旦用户显式定义编译器将不再生成。
//	void Print()  
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;  //调用编译器生成的默认构造函数 -> 1、自己实现无参的构造函数 2、自己实现的全缺省构造函数 3、我们不写，编译器自动生成的构造函数
//	//特点:不用传参数
//	d1.Print();
//
//	Date d2(2026,3,29);
//	d2.Print();
//
//
//	return 0;
//}


class Stack {
public:
	Stack(int n = 10) {
		_a = (int*)malloc(sizeof(int)*n);
		cout << "malloc:" << _a << endl;
		_size = 0;
		_capacity = n;
	}
	~Stack()
	{
		if (_a)
		{
			free(_a);
			cout << "free:" << _a << endl;
			_a = nullptr;
			_size = _capacity = 0;
		}
	}
private:
	int* _a;
	int _size;
	int _capacity;
};

class Date {
public:

	Date(int year = 0, int month = 1, int day = 1)
	{
		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

    void Print()  
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
	

int main()
{
	//析构:在对象生命周期到了之后自动调用。完成对象里面资源清理工作，不是完成d1和d2销毁
	Date d1;
	Date d2;

	Stack s1;
	Stack s2;



	return 0;
}