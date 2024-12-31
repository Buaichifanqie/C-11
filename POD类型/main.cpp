//// 使用默认的构造函数
//class Test {};
//class Test1
//{
//    Test1();	// 程序猿定义的构造函数, 非默认构造
//};
//class Base
//{
//public:
//    Base() {}
//    virtual void print() {}
//};
//语法: class 派生类名：virtual  继承方式  基类名
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//    Base(){}
//};
//
////子类child,虚基类:Base
//class Child:virtual public Base
//{
//    Child(){}
//};
//
//class Base
//{
//public:
//    Base(){}
//    int a;
//protected:
//    int b;
//private:
//    int c;
//};

//class Base
//{
//public:
//    Base(){};
//    int a;
//    int b;
//    int c;
//};

//struct Base { static int a;};
//struct Child: public Base{
//    int b;
//};          //是POD类型
//struct Base1 { int a;};
//struct Child1: public Base1{
//    static int c;
//}; //是POD类型
//struct Child2:public Base, public Base1 {
//    static int d;
//}; //是POD类型
//struct Child3:public Base1{
//    int d;
//};//不是POD类型
//struct Child4:public Base1, public Child {
//    static int num;
//};//不是POD类型

//struct Parent{};
//struct Child : public Parent
//{
//    Parent p;	// 子类的第一个非静态成员
//    int foo;
//};

//struct Parent{};
//struct Child1 : public Parent
//{
//    int foo;   // 子类的第一个非静态成员
//    Parent p;
//};
//
//#include<iostream>
//using namespace std;
//#include<type_traits>
//class A{
//
//};
//class B{
//    B(){}
//};
//class C:B{
//
//};
//class D{
//    virtual void fn(){
//
//    }
//};
//class E:virtual public A{
//
//};
//int main()
//{
//    cout << std::boolalpha;
//    cout << "is_trivial:" << std::endl;
//    cout << "int: " << is_trivial<int>::value << endl;
//    cout << "A: " << is_trivial<A>::value << endl;
//    cout << "B: " << is_trivial<B>::value << endl;
//    cout << "C: " << is_trivial<C>::value << endl;
//    cout << "D: " << is_trivial<D>::value << endl;
//    cout << "E: " << is_trivial<E>::value << endl;
//    return 0;
//}
////运行结果
//is_trivial:
//int: true
//A: true
//B: false
//C: false
//D: false
//E: false

//// pod.cpp
//#include <iostream>
//#include <type_traits>
//using namespace std;
//
//struct A { };
//struct B : A { int j; };
//struct C
//{
//public:
//    int a;
//private:
//    int c;
//};
//struct D1 {  static int i; };
//struct D2 {  int i; };
//struct E1 { static int i; };
//struct E2 { int i; };
//struct D : public D1, public E1 { int a; };
//struct E : public D1, public E2 { int a; };
//struct F : public D2, public E2 { static int a; };
//struct G : public A
//{
//    int foo;
//    A a;
//};
//struct H : public A
//{
//    A a;
//    int foo;
//};
//
//int main()
//{
//    cout << std::boolalpha;
//    cout << "is_standard_layout:" << std::endl;
//    cout << "A: " << is_standard_layout<A>::value << endl;
//    cout << "B: " << is_standard_layout<B>::value << endl;
//    cout << "C: " << is_standard_layout<C>::value << endl;
//    cout << "D: " << is_standard_layout<D>::value << endl;
//    cout << "D1: " << is_standard_layout<D1>::value << endl;
//    cout << "E: " << is_standard_layout<E>::value << endl;
//    cout << "F: " << is_standard_layout<F>::value << endl;
//    cout << "G: " << is_standard_layout<G>::value << endl;
//    cout << "H: " << is_standard_layout<H>::value << endl;
//    return 0;
//}
////运行结果
//is_standard_layout:
//A: true
//B: true
//C: false
//D: true
//D1: true
//E: false
//F: false
//G: true
//H: false



