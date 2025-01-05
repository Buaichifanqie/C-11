
//#include<iostream>
//#include<thread>
//#include<mutex>
//using namespace std;
//
//once_flag g_flag;
//void do_once(int a,string b)
//{
//    cout<<"name:"<<b<<"  age:"<<a<<endl;
//}
//
//void do_something(int age,string name)
//{
//    static int num=1;
//    call_once(g_flag,do_once,19,"aoqi");
//    cout<<"do_something()function num="<<num++<<endl;
//}
//int main()
//{
//    thread t1(do_something,18,"aoqi1");
//    thread t2(do_something,19,"aoqi2");
//    thread t3(do_something,20,"aoqi3");
//    t1.join();
//    t2.join();
//    t3.join();
//    return 0;
//}
////运行结果：
//name:aoqi  age:19
//do_something()function num=1
//do_something()function num=2
//do_something()function num=3

////编写一个单例模式的类 ——懒汉模式
//#include<iostream>
//#include<thread>
//#include<mutex>
//using namespace std;
//once_flag g_flag;
//
//class Base
//{
//public:
//    Base(const Base& obj)=delete;
//    Base& operator=(const Base& obj)=delete;
//    static Base* getInstance()
//    {
//        call_once(g_flag,[&]
//        {
//            obj=new Base();
//            cout<<"create Base object"<<endl;
//        });
//        return obj;
//    }
//    void setName(string name)
//    {
//        m_name=name;
//    }
//    string getName()
//    {
//        return m_name;
//    }
//private:
//    Base(){}
//    static Base* obj;
//    string m_name;
//};
//Base* Base::obj=nullptr;
//
//void myFunc(string name)
//{
//    Base::getInstance()->setName(name);
//    cout<<"my name is "<<Base::getInstance()->getName()<<endl;
//}
//
//int main()
//{
//    thread t1(myFunc,"aoqi1");
//    thread t2(myFunc,"aoqi2");
//    thread t3(myFunc,"aoqi3");
//    t1.join();
//    t2.join();
//    t3.join();
//}
////运行结果：
//create Base object
//my name is aoqi1
//my name is aoqi2
//my name is aoqi3
