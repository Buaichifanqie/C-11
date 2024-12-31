//#include<iostream>
//using namespace std;

//class Base
//{
//public:
//    Base()=default;
//    Base(const Base& obj)=default;
//    Base(Base&& obj)=default;
//    Base& operator=(const Base& obj)=default;
//    Base& operator=(Base&& obj)=default;
//    ~Base()=default;
//};

// 类定义
//class Base
//{
//public:
//    Base();
//    Base(const Base& obj);
//    Base(Base&& obj);
//    Base& operator= (const Base& obj);
//    Base& operator= (Base&& obj);
//    ~Base();
//};
//// 在类定义之外指定成员函数为默认函数
//Base::Base() = default;
//Base::Base(const Base& obj) = default;
//Base::Base(Base&& obj) = default;
//Base& Base::operator= (const Base& obj) = default;
//Base& Base::operator= (Base&& obj) = default;
//Base::~Base() = default;

//class Base
//{
//public:
//    Base() = default;
//    Base(const Base& obj) = default;
//    Base(Base&& obj) = default;
//    Base& operator= (const Base& obj) = default;
//    Base& operator= (Base&& obj) = default;
//    ~Base() = default;
//
//    // 以下写法全部都是错误的
//    Base(int a = 0) = default;
//    Base(int a, int b) = default;
//    void print() = default;
//    bool operator== (const Base& obj) = default;
//    bool operator>=(const Base& obj) = default;
//};

//class Base
//{
//public:
//    Base()=default;
//    Base(const Base& obj)=delete;
//    Base& operator=(const Base& obj)=delete;
//};
//int main()
//{
//    Base b;
//    //Base tmp1(b)//error
//    //Base tmp=b;//error
//    return 0;
//}

#include<iostream>
using namespace std;

class Base
{
public:
    Base(int num):m_num(num){}
    Base(char c)=delete;
    void print(char c)=delete;
    void print()
    {
        cout<<"num:"<<m_num<<endl;
    }
    void print(int num)
    {
        cout<<"num:"<<num<<endl;
    }
private:
    int m_num;
};
int main()
{
    Base b(97);  //'a'对应的ACSCII值为97
    //Base b1('a');    //error
    b.print();
    b.print(97);
    //b.print('a'); //error
    return 0;
}

