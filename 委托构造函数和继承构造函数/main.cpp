//#include <iostream>
//using namespace std;
//
//class Test
//{
//public:
//    Test(){};
//    Test(int max)
//    {
//        this->m_max=max>0?max:100;
//    }
//    Test(int max, int min)
//    {
//        this->m_max = max > 0 ? max : 100;              // 冗余代码
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//
//    Test(int max, int min, int mid)
//    {
//        this->m_max = max > 0 ? max : 100;             // 冗余代码
//        this->m_min = min > 0 && min < max ? min : 1;  // 冗余代码
//        this->m_middle = mid < max && mid > min ? mid : 50;
//    }
//
//    int m_min;
//    int m_max;
//    int m_middle;
//};
//
//int main()
//{
//    Test t(90, 30, 60);
//    cout << "min: " << t.m_min << ", middle: "
//         << t.m_middle << ", max: " << t.m_max << endl;
//    return 0;
//}

////委托构造
//#include <iostream>
//using namespace std;
//
//class Test
//{
//public:
//    Test(){};
//    Test(int max)
//    {
//        this->m_max=max>0?max:100;
//    }
//    Test(int max, int min):Test(max)//委托构造
//    {
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//
//    Test(int max, int min, int mid): Test(max,min)
//    {
//        this->m_middle = mid < max && mid > min ? mid : 50;
//    }
//
//    int m_min;
//    int m_max;
//    int m_middle;
//};
//
//int main()
//{
//    Test t(90, 30, 60);
//    cout << "min: " << t.m_min << ", middle: "
//         << t.m_middle << ", max: " << t.m_max << endl;
//    return 0;
//}


//class Test
//{
//public:
//    Test(int max)
//    {
//        this->m_max = max > 0 ? max : 100;
//    }
//
//    Test(int max, int min)
//    {
//        Test(max);	// error, 此处编译器会报错, 提示形参max被重复定义
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//    // 错误, 使用了委托构造函数就不能再次m_max初始化了
//    Test(int max, int min) : Test(max), m_max(max)
//    {
//        this->m_min = min > 0 && min < max ? min : 1;
//    }
//
//    int m_max;
//    int m_min;
//};

////无继承构造函数
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Base
//{
//public:
//    Base(int i):m_i(i){}
//    Base(int i,double j):m_i(i),m_j(j){}
//    Base(int i,double j,string k):m_i(i),m_j(j),m_k(k){}
//
//    int m_i;
//    double m_j;
//    string m_k;
//};
//class Child:public Base{
//public:
//    Child(int i):Base(i){}
//    Child(int i,double j):Base(i,j){}
//    Child(int i,double j,string k):Base(i,j,k){}
//};
//
//int main()
//{
//    Child c(520,13.14,"i love you");
//    cout << "int: " << c.m_i << ", double: "
//         << c.m_j << ", string: " << c.m_k << endl;
//    return 0;
//}

////继承构造函数
//#include <iostream>
//#include <string>
//using namespace std;
//
//class Base
//{
//public:
//    Base(int i) :m_i(i) {}
//    Base(int i, double j) :m_i(i), m_j(j) {}
//    Base(int i, double j, string k) :m_i(i), m_j(j), m_k(k) {}
//
//    int m_i;
//    double m_j;
//    string m_k;
//};
//
//class Child : public Base
//{
//public:
//    using Base::Base;//继承构造函数
//};
//
//int main()
//{
//    Child c1(520, 13.14);
//    cout << "int: " << c1.m_i << ", double: " << c1.m_j << endl;
//    Child c2(520, 13.14, "i love you");
//    cout << "int: " << c2.m_i << ", double: "
//         << c2.m_j << ", string: " << c2.m_k << endl;
//    return 0;
//}

#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
    Base(int i):m_i(i){}
    Base(int i,double j):m_i(i),m_j(j){}
    Base(int i,double j,string k):m_i(i),m_j(j),m_k(k){}

    void func(int i)
    {
        cout<<"base class :i="<<i<<endl;
    }

    void func(int i,string str)
    {
        cout<<"base class i="<<i<<",str="<<str<<endl;
    }

    int m_i;
    double m_j;
    string m_k;
};

class Child:public Base
{
public:
    using Base::Base;
    using Base::func;
    void func()
    {
        cout << "child class: i'am luffy!!!" << endl;
    }
};

int main()
{
    Child c(200);
    c.func();
    c.func(10);
    c.func(19,"aoqi");
    return 0;
}

//子类中的func()函数隐藏了基类中的两个func()
//因此默认情况下通过子类对象只能调用无参的func()，
//在上面的子类代码中添加了using Base::func;之后，
//就可以通过子类对象直接调用父类中被隐藏的带参func()函数了。