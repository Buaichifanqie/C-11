#include <iostream>
using namespace std;
//void func(const int num)
//{
//    const int count=24;
//    int array[num]; // error，num是一个只读变量，不是常量
//    int array1[count];// ok，count是一个常量
//    int a1 = 520;
//    int a2 = 250;
//    const int& b = a1;
//    //b = a2;                         // error
//    a1 = 1314;
//    cout << "b: " << b << endl;     // 输出结果为1314
//
//}

//const int m = f();  // 不是常量表达式，m的值只有在运行时才会获取。
//const int i=520;    // 是一个常量表达式
//const int j=i+1;    // 是一个常量表达式
//
//constexpr int i=520;    // 是一个常量表达式
//constexpr int j=i+1;    // 是一个常量表达式

//// 此处的constexpr修饰是无效的
//constexpr struct Test
//{
//    int id;
//    int num;
//};

//如果要定义一个结构体/类常量对象，可以这样写：

//struct Text
//{
//    int id;
//    int num;
//};
//
//int main()
//{
//    constexpr Text t{1,2};
//    constexpr int id=t.id;
//    constexpr int num = t.num;
//    //t.num += 100;// error，不能修改常量
//    cout << "id: " << id << ", num: " << num << endl;
//    return 0;
//}

//// error，不是常量表达式函数
//constexpr void func1()
//{
//    int a = 100;
//    cout << "a: " << a << endl;
//}
//
//// error，不是常量表达式函数
//constexpr int func1()
//{
//    int a = 100;
//    return a;
//}

//函数在使用之前，必须有对应的定义语句。
//#include<iostream>
//using namespace std;
//constexpr int func1();
//int main()
//{
//    constexpr int num=func1();//error
//    return 0;
//}
//
//constexpr int func1()
//{
//    constexpr int a=100;
//    return 0;
//}

// error
//constexpr int func1()
//{
//    constexpr int a = 100;
//    constexpr int b = 10;
//    for (int i = 0; i < b; ++i)
//    {
//        cout << "i: " << i << endl;
//    }
//    return a + b;
//}
//
//// ok
//constexpr int func2()
//{
//    using mytype = int;
//    constexpr mytype a = 100;
//    constexpr mytype b = 10;
//    constexpr mytype c = a * b;
//    return c - (a + b);
//}
//因为func1()是一个常量表达式函数，
// 在函数体内部是不允许出现非常量表达式以外的操作，
// 因此函数体内部的for循环是一个非法操作。

//class Test
//{
//public:
//    constexpr int func()
//    {
//        constexpr int var=100;
//        return 5*var;
//    }
//};
//
//int main()
//{
//    Test t;
//    constexpr int num=t.func();
//    cout<<"num:"<<num<<endl;
//    return 0;
//}
//#include<iostream>
//using namespace std;
//struct Person
//{
//    const char* name;
//    int age;
//};
//
////定义函数模板
//template<typename T>
//constexpr T dispaly(T t) {
//    return t;
//}
//
//int main() {
//    struct Person p{"luffy", 19};
//    //普通函数
//    struct Person ret = dispaly(p);
//    cout << "luffy's name: " << ret.name << ", age: " << ret.age << endl;
//
//    //常量表达式函数
//    constexpr int ret1 = dispaly(250);
//    cout << ret1 << endl;
//
//    constexpr struct Person p1{"luffy", 19};
//    constexpr struct Person p2 = dispaly(p1);
//    cout << "luffy's name: " << p2.name << ", age: " << p2.age << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//struct Person {
//    constexpr Person(const char* p, int age) :name(p), age(age)
//    {
//    }
//    const char* name;
//    int age;
//};
//
//int main()
//{
//    constexpr struct Person p1("luffy", 19);
//    cout << "luffy's name: " << p1.name << ", age: " << p1.age << endl;
//    return 0;
//}



