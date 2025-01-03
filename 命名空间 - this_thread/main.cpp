
//#include <iostream>
//#include <thread>
//using namespace std;
//
//void func()
//{
//    cout << "子线程: " << this_thread::get_id() << endl;
//}
//
//int main()
//{
//    cout << "主线程: " << this_thread::get_id() << endl;
//    thread t(func);
//    t.join();
//}
////运行结果
//主线程: 0xa00000010
//子线程: 0xa00022a00

//#include<iostream>
//#include<thread>
//#include<chrono>
//using namespace std;
//
//void func()
//{
//    for(int i=0;i<5;i++)
//    {
//        this_thread::sleep_for(chrono::seconds(1));
//        cout<<"子线程: "<<this_thread::get_id()<<",i="<<i<<endl;
//    }
//}
//
//int main() {
//    thread t(func);
//    t.join();
//}
////运行结果
//子线程: 0xa000129a0,i=0
//子线程: 0xa000129a0,i=1
//子线程: 0xa000129a0,i=2
//子线程: 0xa000129a0,i=3
//子线程: 0xa000129a0,i=4

//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//
//void func()
//{
//    for (int i = 0; i < 10; ++i)
//    {
//        // 获取当前系统时间点
//        auto now = chrono::system_clock::now();
//        // 时间间隔为2s
//        chrono::seconds sec(2);
//        // 当前时间点之后休眠两秒
//        this_thread::sleep_until(now + sec);
//        cout << "子线程: " << this_thread::get_id() << ", i = " << i << endl;
//    }
//}
//
//int main()
//{
//    thread t(func);
//    t.join();
//}
//#include <iostream>
//#include <thread>
//using namespace std;
//
//void func()
//{
//    for (int i = 0; i < 100000000000; ++i)
//    {
//        cout << "子线程: " << this_thread::get_id() << ", i = " << i << endl;
//        this_thread::yield();
//    }
//}
//
//int main()
//{
//    thread t(func);
//    thread t1(func);
//    t.join();
//    t1.join();
//}

