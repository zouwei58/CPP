#include <iostream>
using namespace std;

//int main()
//{
//	//权限的放大和缩小规则: 适用于引用和指针间
//	//权限放大 const不能给非const,const只能给const
//	const int a = 1;
//	//int& b = a;  
//	const int& b = a;
//
//	//权限缩小 非const可以给const,也可以给非const
//	int c = 0;
//	const int& d = c;
//	int& e = c;
//
//	//指针
//	int m = 0;
//	int n = 1;
//	const int* p1 = &m;
//	//int* p2 = p1;   //不能，属于权限的放大
//
//	int* p3 = &n;
//	const int* p4 = &n; //可以，始于权限的缩小
//
//
//	//赋值语句，操作空间不同，不存在权限问题
//	const int x = 10;
//	int y = x;
//
//	int z = 20;
//	const int r = z;
//
//	return 0;
//}


//// 1.引用做参数
//// a.输出型参数
//// b.提高效率
//// C语言里
//void swap_c(int* p1, int* p2)
//{
//	int tmp;
//	tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//// c++里,这个是引用传递，相当于直接操作a和b,
//// 和swap(int r1,int r2)不一样，
//// swap(int r1,int r2)是值传递，会把a和b的值拷贝一份给r1和r2，
//// 交换的是拷贝，和原来的a,b没有关系，函数结束后r1和r2销毁，a,b没变
//// 但是引用传递，操作r1相当于直接操作a，操作r2同理，本质就是交换a和b,
//// 函数结束后，只是别名被销毁，但是a和b的值已经被修改了
//void swap_cpp(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	swap_c(&a, &b);
//	swap_cpp(a, b);
//	return 0;
//} 

//// 2.引用做返回值
//
//
////(一)传值返回
////传值一般都会产生一个拷贝
//int count1()
//{
//	static int n = 0;
//	n++;
//	return n;  //返回一个临时变量,返回的是n的拷贝，int tmp = n ;
//	//会产生一个空间
//}
//
////(二)传引用返回
////传引用不产生拷贝
//int& count2()
//{
//	//static修饰的是他的生命周期
//	static int n = 0;
//	n++;
//	return n;  //相当于也是返回一个临时变量(其实不是，只是一个别名)，但是类型是int&,int& tmp = n;
//    //不会产生空间
//}
//
//int main()
//{
//	//int& r1 = count1();  
//	//编译不通过，因为tmp这个临时变量具有常性，由一个只读变成现在的可读可写，扩大了权限
//	const int& r1 = count1();
//	int& r2 = count2();
//	return 0;
//}

//int Add1(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	const int& ret = Add1(1, 2);
//	Add1(3, 4); //会通过别名修改ret的值
//	cout << "Add1(1, 2) is :" << ret << endl;
//	return 0;
//}

////这种用法是不安全的
//int& Add2(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add2(1, 2);
//	Add2(3, 4); //会通过别名修改ret的值
//	cout << "Add2(1, 2) is :" << ret << endl;  //ret 随机值，已经销毁了
//	return 0;
//}
//
////总结:一个函数要使用引用返回，
//// 返回变量出了这个函数的作用域还存在，
//// 就可以使用引用返回，否则就不安全 
//// 全局变量，静态变量等就可以使用引用返回

//int& Add2(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add2(1, 2);
//	Add2(3, 4); 
//	cout << "Add2(1, 2) is :" << ret << endl;  
//	return 0;
//}

/*
* 函数使用引用返回的好处是什么呢? 
-> 少创建拷贝一个临时对象，提高效率
*/

////引用和指针
///*
//* 1.在语法概念上，b就是a的别名(不开空间)
//*/
//int main()
//{
//	int a = 10;
//	int& b = a;
//
//
//	int* p = &a;
//
//	return 0;
//}
//
///*
//* 引用和指针的不同点:
//* 1.引用概念上定义一个变量的别名，指针存储一个变量的地址(注意:是概念上)
//* 2.引用在定义时必须初始化，指针没有要求。
//* 3.引用在初始化时引用了一个实体后，就不能引用其他实体，而指针可以在任何时候指向任何一个同类型的实体
//* 4.没有NULL引用，但是由NULL指针
//* 5.在sizeof中含义不同:引用结果为引用类型大小，但指针始终是地址空间所占字节个数(32位平台下占四个字节)
//* 6.引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小
//* 7.有多级指针，但是没有多级引用
//* 8.访问实体方式不同，指针需要显示解引用，引用编译器自己处理
//* 9.引用比指针使用起来相对安全
//*/
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//inline void Swap(int& x1, int& x2)
//{
//	int tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
////频繁调用Swap，调用函数需要建立栈帧的，是有消耗的
////如何解决: 1.C语言使用宏函数 2.c++使用内联函数(空间换时间)
//
//
////一般内联适用于小函数，小于2  0行。
////其次递归，或者比较长的都不适宜内联
////
//int mian()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a,b);  //内联函数在调用的地方直接就展开了，内联函数没有地址，比建议声明和定义分离，分离会导致链接错误
//	return 0;
//}

//面试题
/*
* 宏的优缺点?
* 优点:
* 1、提高代码复用性
* 2、提高性能
* 缺点:
* 1、不方便宏调试(因为预编译阶段进行了替换)
* 2、导致代码可读性差，可维护性差，容易误用
* 3、没有类型安全的检查
* c++哪些技术可以代替宏?
* 1、常量定义 换用const
* 2、短小函数定义 换用内联函数
* 
*   #define N 10  --> const int N = 10;
*   宏函数 -> inline函数替代
*/ 

//int main()
//{
//	int a = 0;
//	auto b = a;  //b的类型是根据a的类型推导出是int
//	int& c = a;
//
//	auto& d = a;
//	auto* e = &a;
//	auto f = &a;
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	cout << typeid(f).name() << endl;
//
// }

//void TestFor(int array[])
//{
//	for (auto& e : array)   //编译不通过，因为数组通过传参之后就退化成指针了
//		cout << e << endl;
//}

//int main()
//{
//	int array[] = { 1,2,3,4,5 };
//	int array_size = sizeof(array) / sizeof(array[0]);
//	//要求将是这个数组中的值乘2倍，再打印一遍
//
//	//c语言中的做法
//	for (int i = 0;i < array_size;i++)
//	{
//		array[i] *= 2;
//	}
//	for (int i = 0;i < array_size;i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//
//	//C++11 -> 范围for -> 写起来比较简洁
//	for (auto& e : array)  //for(auto e : array); 这个是将值拷贝到e，改变的是e，但是array并没有改变
//	{
//		e *= 2;
//	}
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void fun(int n)
//{
//	cout << "整型" << endl;
//}
//
//void fun(int* p)
//{
//	cout << "整型指针" << endl;
//}
//
//int main()
//{
//	//C语言
//	int* p1 = NULL;
//
//	//C++
//	int* p2 = nullptr;
//
//	fun(0);
//	fun(NULL);  //预处理后fun(0)
//	fun(nullptr); //fun((void*)0);
//	return 0;
//}

//面向过程/面向对象

//类里面可以定义: 1、成员变量 2、成员方法
//class  Person 
//{ 
//	void Print()
//	{
//
//	}
//
//	char _name[10];
//	int _age;
//	//....
//};

//C++中class和struct都可以来定义类，class默认访问限定符是私有的，struct默认访问限定符是公有的
//struct Student
class Student 
{
public:
	void ShowInfo()
	{ 
		cout << _name << endl;
		cout << _age << endl;
		cout << _stuid << endl;
	}
	int GetAge()
	{
		return _age;
	}
private:    //一般情况下成员变量都是比较隐私的，都会定义成私有或者保护
	string _name;
	int _age;
	int _stuid;
	// ...
};

int main()
{
	Student s1;
	s1.ShowInfo();

}

//class默认是私有的，struct默认是共有的




