////互斥锁版本
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <atomic>
//#include <functional>
//using namespace std;
//
//struct Counter
//{
//    void increment()
//    {
//        for (int i = 0; i < 10; ++i)
//        {
//            lock_guard<mutex> locker(m_mutex);
//            m_value++;
//            cout << "increment number: " << m_value
//                 << ", theadID: " << this_thread::get_id() << endl;
//            this_thread::sleep_for(chrono::milliseconds(100));
//        }
//    }
//
//    void decrement()
//    {
//        for (int i = 0; i < 10; ++i)
//        {
//            lock_guard<mutex> locker(m_mutex);
//            m_value--;
//            cout << "decrement number: " << m_value
//                 << ", theadID: " << this_thread::get_id() << endl;
//            this_thread::sleep_for(chrono::milliseconds(100));
//        }
//    }
//
//    int m_value = 0;
//    mutex m_mutex;
//};
//
//int main()
//{
//    Counter c;
//    auto increment = bind(&Counter::increment, &c);
//    auto decrement = bind(&Counter::decrement, &c);
//    thread t1(increment);
//    thread t2(decrement);
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}

//原子变量版本
#include<iostream>
#include<thread>
#include<functional>
#include<atomic>
using namespace std;

struct Counter
{
    void increment()
    {
        for(int i=0;i<10;i++)
        {
            m_value++;
            cout<<"increment number: "<<m_value
                <<", theadID: "<<this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void decrement()
    {
        for(int i=0;i<10;i++)
        {
            m_value--;
            cout<<"decrement number: "<<m_value
                <<", theadID: "<<this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    //atomic<int>==atomic_int
    atomic_int m_value=0;
};

int main()
{
    Counter c;
    auto increment=bind(&Counter::increment,&c);
    auto decrement=bind(&Counter::decrement,&c);
    thread t1(increment);
    thread t2(decrement);
    t1.join();
    t2.join();
    return 0;
}