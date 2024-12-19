//#include <iostream>
//using namespace std;
//int temp = 110;
//auto *a = &temp;
//auto b = &temp;
//auto &c = temp;
//auto d = temp;
//变量a的数据类型为 int*，因此auto关键字被推导为 int类型
//变量b的数据类型为 int*，因此auto关键字被推导为 int*类型
//变量c的数据类型为 int&，因此auto关键字被推导为 int类型
//变量d的数据类型为 int，因此auto关键字被推导为 int类型

//int tmp = 250;
//const auto a1 = tmp;
//auto a2 = a1;
//const auto &a3 = tmp;
//auto &a4 = a3;

//变量a1的数据类型为 const int，因此auto关键字被推导为 int类型
//变量a2的数据类型为 int，但是a2没有声明为指针或引用因此 const属性被去掉, auto被推导为 int
//变量a3的数据类型为 const int&，a3被声明为引用因此 const属性被保留，auto关键字被推导为 int类型
//变量a4的数据类型为 const int&，a4被声明为引用因此 const属性被保留，auto关键字被推导为 const int类型

//1.2 auto的限制
//auto关键字并不是万能的，在以下这些场景中是不能完成类型推导的：
//不能作为函数参数使用。因为只有在函数调用的时候才会给函数参数传递实参，auto要求必须要给修饰的变量赋值，因此二者矛盾。
//int func(auto a, auto b)	// error
//{
//    cout << "a: " << a <<", b: " << b << endl;
//}
////不能用于类的非静态成员变量的初始化
//class Test
//{
//    auto v1 = 0;                    // error
//    static auto v2 = 0;             // error,类的静态非常量成员不允许在类内部直接初始化
//    static const auto v3 = 10;      // ok
//}
////不能使用auto关键字定义数组
//int func()
//{
//    int array[] = {1,2,3,4,5};  // 定义数组
//    auto t1 = array;            // ok, t1被推导为 int* 类型
//    auto t2[] = array;          // error, auto无法定义数组
//    auto t3[] = {1,2,3,4,5};;   // error, auto无法定义数组
//}
////无法使用auto推导出模板参数
//template <typename T>
//struct Test{}
//
//int func()
//{
//    Test<double> t;
//    Test<auto> t1 = t;           // error, 无法推导出模板类型
//    return 0;
//}


//遍历容器
//#include<string>
//#include <map>
//int main()
//{
//    map<int, string> person;
//    map<int, string>::iterator it = person.begin();
//    for (; it != person.end(); ++it)
//    {
//        // do something
//    }
//    return 0;
//}

//#include <map>
//int main()
//{
//    map<int, string> person;
//    // 代码简化
//    for (auto it = person.begin(); it != person.end(); ++it)
//    {
//        // do something
//    }
//    return 0;
//}

//泛型编程
//#include<iostream>
//using namespace  std;
//#include<string>
//
//class T1
//{
//public:
//    static int get()
//    {
//        return 10;
//    }
//};
//
//class T2
//{
//public:
//    static string get()
//    {
//        return "hello,world";
//    }
//};
//
//template<class A>
//void func(void)
//{
//    auto val=A::get();
//    cout<<"val:"<<val<<endl;
//}
//
//int main()
//{
//    func<T1>();
//    func<T2>();
//}
//在这个例子中定义了泛型函数func，在函数中调用了类A的静态方法 get() ，
//这个函数的返回值是不能确定的，如果不使用auto，就需要再定义一个模板参数，
//并且在外部调用时手动指定get的返回值类型，具体代码如下：
//#include <iostream>
//#include <string>
//using namespace std;
//
//class T1
//{
//public:
//    static int get()
//    {
//        return 0;
//    }
//};
//
//class T2
//{
//public:
//    static string get()
//    {
//        return "hello, world";
//    }
//};
//
//template <class A, typename B>        // 添加了模板参数 B
//void func(void)
//{
//    B val = A::get();
//    cout << "val: " << val << endl;
//}
//
//int main()
//{
//    func<T1, int>();                  // 手动指定返回值类型 -> int
//    func<T2, string>();               // 手动指定返回值类型 -> string
//    return 0;
//}

//int a = 10;
//decltype(a) b = 99;                 // b -> int
//decltype(a+3.14) c = 52.13;         // c -> double
//decltype(a+b*c) d = 520.1314;       // d -> double

//#include<iostream>
//using namespace std;
//#include<string>
//
//class Test
//{
//public:
//    string text;
//    static const int value=110;
//};
//int main()
//{
//    int x=100;
//    const int &y=x;
//    decltype(x)a=x;
//    decltype(y)b=x;
//    decltype(Test::value)c=0;
//
//    Test t;
//    decltype(t.text)d="hello,world";
//    return 0;
//}
//
//变量a被推导为 int类型
//变量b被推导为 const int &类型
//变量c被推导为 const int类型
//变量d被推导为 string类型

//class Test{};
////函数声明
//int func_int();                 // 返回值为 int
//int& func_int_r();              // 返回值为 int&
//int&& func_int_rr();            // 返回值为 int&&
//
//const int func_cint();          // 返回值为 const int
//const int& func_cint_r();       // 返回值为 const int&
//const int&& func_cint_rr();     // 返回值为 const int&&
//
//const Test func_ctest();        // 返回值为 const Test
//
////decltype类型推导
//int n = 100;
//decltype(func_int()) a = 0;
//decltype(func_int_r()) b = n;
//decltype(func_int_rr()) c = 0;
//decltype(func_cint())  d = 0;
//decltype(func_cint_r())  e = n;
//decltype(func_cint_rr()) f = 0;
//decltype(func_ctest()) g = Test();
//
//变量a被推导为 int类型
//变量b被推导为 int&类型
//变量c被推导为 int&&类型
//变量d被推导为 int类型
//变量e被推导为 const int &类型
//变量f被推导为 const int &&类型
//变量g被推导为 const Test类型

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Test
//{
//public:
//    int num;
//};
//
//int main() {
//    const Test obj{0};
//    //带有括号的表达式
//    decltype(obj.num) a = 0;
//    decltype((obj.num)) b = a;
//    //加法表达式
//    int n = 0, m = 0;
//    decltype(n + m) c = 0;
//    decltype(n = n + m) d = n;
//    return 0;
//}
//obj.num 为类的成员访问表达式，符合场景1，因此 a 的类型为int
//obj.num 带有括号，符合场景3，因此b 的类型为 const int&。
//n+m 得到一个右值，符合场景1，因此c的类型为 int
//n=n+m 得到一个左值 n，符合场景3，因此d的类型为 int&

//#include<iostream>
//#include <list>
//using namespace std;
//
//template <class T>
//class Container
//{
//public:
//    void func(T& c)
//    {
//        for (m_it = c.begin(); m_it != c.end(); ++m_it)
//        {
//            cout << *m_it << " ";
//        }
//        cout << endl;
//    }
//private:
//    ??? m_it;  // 这里不能确定迭代器类型
//};
//
//int main()
//{
//    const list<int> lst;
//    Container<const list<int>> obj;
//    obj.func(lst);
//    return 0;
//}


//#include <list>
//#include <iostream>
//using namespace std;
//
//template <class T>
//class Container
//{
//public:
//    void func(T& c)
//    {
//        for (m_it = c.begin(); m_it != c.end(); ++m_it)
//        {
//            cout << *m_it << " ";
//        }
//        cout << endl;
//    }
//private:
//    decltype(T().begin()) m_it;  // 这里不能确定迭代器类型
//};
//
//int main()
//{
//    const list<int> lst{ 1,2,3,4,5,6,7,8,9 };
//    Container<const list<int>> obj;
//    obj.func(lst);
//    return 0;
//}


//#include <iostream>
//using namespace std;
//// R->返回值类型, T->参数1类型, U->参数2类型
//template <typename R, typename T, typename U>
//R add(T t, U u)
//{
//    return t + u;
//}
//
//int main()
//{
//    int x = 520;
//    double y = 13.14;
//    // auto z = add<decltype(x + y), int, double>(x, y);
//    auto z = add<decltype(x + y)>(x, y);	// 简化之后的写法
//    cout << "z: " << z << endl;
//    return 0;
//}
//


//template <typename T, typename U>
//decltype(t+u) add(T t, U u)
//{
//    return t + u;
//}

//// 符号 -> 后边跟随的是函数返回值的类型
//auto func(参数1, 参数2, ...) -> decltype(参数表达式)

//#include <iostream>
//using namespace std;
//
//template <typename T, typename U>
//// 返回类型后置语法
//auto add(T t, U u) -> decltype(t+u)
//{
//    return t + u;
//}
//
//int main()
//{
//    int x = 520;
//    double y = 13.14;
//    // auto z = add<int, double>(x, y);
//    auto z = add(x, y);		// 简化之后的写法
//    cout << "z: " << z << endl;
//    return 0;
//}

#include<iostream>
using namespace  std;

int& test(int &i)
{
    return i;
}

double test(double& d)
{
    d=d+100;
    return d;
}

template<typename T>
//返回类型的后置语法
auto myFunc(T& t)->decltype(test(t))
{
    return test(t);
}

int main()
{
    int x=520;
    double y=13.14;
//    auto z= myFunc<int>(x);
    auto z=myFunc(x);
    cout<<"z:"<<z<<endl;
    // auto z = myFunc<double>(y);
    auto z1 = myFunc(y);            // 简化之后的写法
    cout << "z1: " << z1 << endl;
    return 0;
}

