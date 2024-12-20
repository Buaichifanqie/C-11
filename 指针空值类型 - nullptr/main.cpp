
//C++ 中将 NULL 定义为字面常量 0，并不能保证在所有场景下都能很好的工作，比如，函数重载时，NULL 和 0 无法区分：
//#include<iostream>
//using namespace std;
//
//void func(char* p)
//{
//    cout<<"void func(char *p)"<<endl;
//}
//void func(int p)
//{
//    cout << "void func(int p)" << endl;
//}
//
//int main()
//{
//    func(NULL);   // 想要调用重载函数 void func(char *p)//报错了
//    func(250);    // 想要调用重载函数 void func(int p)
//
//    return 0;
//}

//测试代码打印的结果为：
//void func(int p)
//void func(int p)

#include <iostream>
using namespace std;

void func(char *p)
{
    cout << "void func(char *p)" << endl;
}

void func(int p)
{
    cout << "void func(int p)" << endl;
}

int main()
{
    func(nullptr);
    func(250);
    return 0;
}
////运行结果：
//void func(char *p)
//void func(int p)
