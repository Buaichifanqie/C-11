//#include <iostream>
//#include<functional>
//using namespace std;
//
//class Test
//{
//public:
//    void output(int x,int y)
//    {
//        //auto x1=[]{return m_number; };   // error
//        auto x2=[=]{return m_number+x+y;};  //ok
//        auto x3 = [&] {return m_number + x + y; };             // ok
//        auto x4 = [this] {return m_number; };                  // ok
//        //auto x5 = [this] {return m_number + x + y; };          // error
//        auto x6 = [this, x, y] {return m_number + x + y; };    // ok
//        auto x7 = [this] {return m_number++; };                // ok
//    }
//
//    int m_number=100;
//};
//
//int main()
//{
//    int a = 10, b = 20;
//   // auto f1 = [] {return a; };              // error
//    auto f2 = [&] {return a++; };             // ok
//    auto f3 = [=] {return a; };              // ok
//    //auto f4 = [=] {return a++; };              // error
//    //auto f5 = [a] {return a + b; };         // error
//    auto f6 = [a, &b] {return a + (b++); };    // ok
//    auto f7 = [=, &b] {return a + (b++); };   // ok
//
//    return 0;
//}


//// 完整的lambda表达式定义
//auto f = [](int a) -> int
//{
//    return a+10;
//};
//
//// 忽略返回值的lambda表达式定义
//auto f = [](int a)
//{
//    return a+10;
//};

//// ok，可以自动推导出返回值类型
//auto f = [](int i)
//{
//    return i;
//}
//
//// error，不能推导出返回值类型
//auto f1 = []()
//{
//    return {1, 2};	// 基于列表初始化推导返回值，错误
//}

//int a = 0;
//auto f1 = [=] {return a++; };              // error, 按值捕获外部变量, a是只读的
//auto f2 = [=]()mutable {return a++; };     // ok
#include<iostream>
#include <functional>

using namespace std;
int main()
{
    //包装可调用函数
    std::function<int(int)> f1=[](int a)
    {
        return a;
    };
    //绑定可调用函数
    std::function<int(int)> f2=bind([](int a) ->int
    {
        return a;
    },placeholders::_1);
    // 函数调用
    cout << f1(100) << endl;
    cout << f2(200) << endl;
    return 0;
}

//using func_ptr = int(*)(int);
//// 没有捕获任何外部变量的匿名函数
//func_ptr f = [](int a)
//{
//    return a;
//};
//// 函数调用
//f(1314);