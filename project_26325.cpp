//#include <iostream>
////using namespace std;  //c++库中所有的东西都是放在std命名空间里面的
//
//int main()
//{
//	//自动识别类型
//	std::cout << "Hello World" << std::endl;
//	int i = 1;
//	double d = 1.1;
//	std::cout << i << " " << d << std::endl;
//	return 0;
//}

//#include <iostream>
////在日常练习中，不在乎与库命名冲突
//using namespace std;  //c++库中所有的东西都是放在std命名空间里面的
//
////int cout = 10; //和库里面就命名冲突
//int main()
//{
//	//自动识别类型
//	cout << "Hello World" << endl;
//	int i = 1;
//	double d = 1.1;
//	cout << i << " " << d << endl;
//	return 0;
//}

//#include <iostream>
////在日常练习中，不在乎与库命名冲突
//using namespace std;  //c++库中所有的东西都是放在std命名空间里面的
//
////int cout = 10; //和库里面就命名冲突
//int main()
//{
//	//自动识别类型
//	cout << "Hello World" << endl;
//	int i = 1;
//	double d = 1.1;
//	cout << i << " " << d << endl;
//	return 0;
//}

//#include <iostream>
////using namespace std;  //c++库中所有的东西都是放在std命名空间里面的
//
//int cout = 10; 
//int main()
//{
//	//自动识别类型
//	std::cout << "Hello World" << std::endl;
//	int i = 1;
//	double d = 1.1;
//	std::cout << i << " " << cout << " " << d << std::endl;
//	return 0;
//}

//#include <iostream>
////常用的库里面一些对象或者类型可以展出来
////工程项目中比较推荐使用这种
//using std::cout;
//using std::endl;
//
//int main()
//{
//	//自动识别类型
//	cout << "Hello World" << endl;
//	int i = 1;
//	double d = 1.1;
//	cout << i << " " << d << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	//自动识别类型
//	cout << "Hello World" << endl;
//	int i;
//	double d;
//	cin >> i >> d;
//	cout << i << " " << d << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//////缺省参数 --> 备胎
////void Func(int a = 0)
////{
////	cout << a << endl;
////}
//
//// 全缺省 
//void Func1(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c= " << c << endl;
//}
//
////半缺省(缺省部分参数)，必须从右向左连续缺省
//void Func2(int a, int b = 20, int c = 30)
//{
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//	cout << "c= " << c << endl;
//}
//
//int main()
//{
///*	Func1();
//	Func1(1);
//	Func1(1,2);
//	Func1(1,2,3);*/
//	//Func2();  //报错，半缺省必须传入缺省参数
//	Func2(1);
//	Func2(1, 2);
//	Func2(1, 2, 3);
//}

////函数重载，函数名相同，参数不同(类型 or 个数 or 顺序)
////返回值没有要求
//#include <iostream>
//using namespace std;
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//double Add(double left, double right)
//{
//	return left + right;
//}
//
//long Add(long left, long right)
//{
//	return left + right;
//}
//
//void Func1(int i, char ch)
//{
//
//}
//void Func1(char ch, int i)
//{
//
//}
//
////只是返回值不同，不能构成重载
////int	Func1()
////{
////
////}
//void Func1()
//{
//}
//
//int main()
//{
//
//	Func1();
//	Func1('a', 1);
//	Func1(1, 'a');
//	return 0;
//}


//重载:面试问题
//1.什么是函数重载?
//在同一个作用域里，可以有函数名相同，参数不相同(类型，个数，顺序)，返回值不要求
//2.c++里面是如何支持函数重载的?c里面为什么不支持?

//程序从源码到可执行文件的完整流程
/*
list.h  list.c test.c
1、预处理  -> 头文件展开/宏替换/条件编译/去除注释
list.i  test.i
2、编译    -> 检查语法、生成汇编代码
list.s  test.s
函数重载(c++里面是如何支持函数重载的?c里面为什么不支持?)
在linux下，gcc的函数修饰后名字不变。而g++的函数修饰后变成(_Z+函数长度+函数名+类型首字母)
3、汇编    ->汇编代码转成二进制的机器码
list.o test.o
4、链接    ->将两个目标文件链接到一起
*/
//引用
#include <iostream>
using namespace std;

//int main()
//{
//	int a = 1;
//	int& ra = a; //ra是a的引用，引用也就是别名，a再取一个名
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	//int& b;     //报错，引用必须在定义时初始化
//	int& c = a;
//	int d = 2;
//	c = d;  //将d的值赋值给c
//	return 0;
//}

//常引用
int main()
{
	const int a = 0;
	//int& b = a; //b的类型是int，编译不通过，原因a是只读，b的类型是int,也就是可读可写。所以相当于权限扩大了，所以报错
	const int& b = a;

	int c = 1;
	int& d = c;
	const int& e = c;  //行不行?可以->c只是可读可写，e变成别名只读
	//总结:引用取别名时，变量访问的权限可以缩写，不能放大

	int i = 0;
	double db = i;   //隐式类型转换，相当于 temp = double(i); double db = temp;  temp是一个临时变量；
	//double& rd = i;  //报错，存在隐式类型转换，这样写相当于试图修改一个临时变量
	//临时变量具有常性
	const double& rd = i;  //这样就可以，只是去读这个临时变量，不修改，而且c++会延长临时变量生命周期，和引用一样长

	//变量之间的赋值没有权限缩小和放大的关系，引用才有
	const int ci = i;
	int x = ci;

	return 0;
}



