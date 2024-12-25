
//int a = 520;
//int b = 1314;
//a = b;
//
//int value = 520;
//#include<iostream>
//using namespace std;
// int&& value=520;
// class Test
// {
// public:
//     Test()
//     {
//         cout<<"construct: my name is jerry"<<endl;
//     }
//     Test(const Test& a)
//     {
//         cout<<"copy construct: my name is tom"<<endl;
//     }
// };
//
// Test getObj()
// {
//     return Test();
// }
//
// int main()
// {
//     int a1;
//     //int &&a2=a1;  //error使用左值初始化一个右值引用类型是不合法的。
//     //Test& t=getObj();   //error右值不能给普通的左值引用赋值。
//     //Test && t=getObj();中getObj()返回的临时对象被称之为将亡值，t是这个将亡值的右值引用。
//     const Test& t=getObj();//常量左值引用是一个万能引用类型，它可以接受左值、右值、常量左值和常量右值。
// }

//#include<iostream>
//using namespace std;
//class Test {
//public:
//    Test() : m_num(new int(100)) {
//        cout << "construct: my name is jerry" << endl;
//    }
//
//    Test(const Test &a) : m_num(new int(*a.m_num)) {
//        cout << "construct: my name is jerry" << endl;
//    }
//
//    ~Test()
//    {
//        delete m_num;
//    }
//    int* m_num;
//};
//
//Test getObj()
//{
//    Test t;
//    return t;
//}
//int main()
//{
//    Test t=getObj();
//    cout<<"t.m_num:"<<*t.m_num<<endl;
//    return 0;
//}

//测试代码执行的结果为（当时使用的vs版本为2019，
//vs2022已无法看到相同的输出，代码被优化了）:
//construct: my name is jerry
//copy construct: my name is tom
//t.m_num: 100


//#include<iostream>
//using namespace std;
//
//class Test
//{
//public:
//    Test():m_num(new int(100))
//    {
//        cout<<"construct: my name is jerry"<<endl;
//    }
//    Test(const Test& a):m_num(new int(*a.m_num))
//    {
//        cout << "copy construct: my name is tom" << endl;
//    }
//
//    //添加移动构造函数
//    Test(Test&& a):m_num(a.m_num)
//    {
//        a.m_num=nullptr;
//        cout << "move construct: my name is sunny" << endl;
//    }
//
//    ~Test()
//    {
//        delete m_num;
//        cout<<"destruct Test class ..." << endl;
//    }
//    int* m_num;
//};
//
//Test getObj()
//{
//    Test t;
//    return t;
//}
//
//int main()
//{
//    Test t = getObj();
//    cout << "t.m_num: " << *t.m_num << endl;
//    return 0;
//}
//
////
////测试代码执行的结果如下（当时使用的vs版本为2019，vs2022已无法看到相同的输出，代码被优化了）:
////construct: my name is jerry
////move construct: my name is sunny
////destruct Test class ...
////        t.m_num: 100
////destruct Test class ...

#include<iostream>
using namespace std;
template<typename T>
void f(T&& param);

template<typename T>
void f1(const T&& param);

//int main()
//{
//    f(10);
//    int x = 10;
//    f(x);
//    //f1(x);	// error, x是左值
//    f1(10); // ok, 10是右值
//}

//int main()
//{
//    int x = 520, y = 1314;
//    auto&& v1 = x;
//    auto&& v2 = 250;
//    //decltype(x)&& v3 = y;   // error
//    cout << "v1: " << v1 << ", v2: " << v2 << endl;
//    return 0;
//};

//int&& a1 = 5;
//auto&& bb = a1;
//auto&& bb1 = 5;
//
//int a2 = 5;
//int &a3 = a2;
//auto&& cc = a3;
//auto&& cc1 = a2;
//
//const int& s1 = 100;
//const int&& s2 = 100;
//auto&& dd = s1;
//auto&& ee = s2;
//
//const auto&& x = 5;

//第2行：a1为右值引用，推导出的bb为左值引用类型
//第3行：5为右值，推导出的bb1为右值引用类型
//第7行：a3为左值引用，推导出的cc为左值引用类型
//第8行：a2为左值，推导出的cc1为左值引用类型
//第12行：s1为常量左值引用，推导出的dd为常量左值引用类型
//第13行：s2为常量右值引用，推导出的ee为常量左值引用类型
//第15行：x为右值引用，不需要推导，只能通过右值初始化


#include<iostream>
using namespace std;
void printValue(int &i)
{
    cout << "l-value: " << i << endl;
}

void printValue(int &&i)
{
    cout << "r-value: " << i << endl;
}

void forward(int &&k)
{
    printValue(k);
}
int main() {
    int i = 520;
    printValue(i);
    printValue(1314);
    forward(250);
    return 0;
}

//l-value: 520
//r-value: 1314
//l-value: 250
//
