#include <iostream>
#include<string>
using namespace std;
//class Base
//{
//public:
//    virtual void test()
//    {
//        cout<<"Base class..."<<endl;
//    }
//};
//
//
//class Child:public Base{
//public:
//    void test() final
//    {
//        cout<<"child class.."<<endl;
//    }
//};
//class GrandChild:public Child{
//public:
//    //语法错误不允许重写
////    void test()
////    {
////        cout<<"GrandChild class...";
////    }
//};
//
//
//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}

//class Base{
//public:
//    virtual void test() {
//        cout << "Base class...";
//    }
//};
//
//class Child final : public Base{
//public:
//    void test(){
//        cout<<"Child class...";
//    }
//};
//// error, 语法错误
//class GrandChild : public Child
//{
//public:
//};

class Base{
public:
    virtual void test() {
        cout << "Base class..." << endl;
    }
};

class Child:public Base{
public:
    void test() override
    {
        cout<<"Child class...";
    }
};

class GrandChild : public Child
{
public:
    void test() override
    {
        cout << "Child class...";
    }
};

int main()
{
    Base* base=new Base;
    base->test();
    delete base;
    Child* child = new Child();
    child->test();
    delete child;  // 如果使用了new分配内存，最后要记得释放内存，避免内存泄漏
    return 0;
}
