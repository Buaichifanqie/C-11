//#include <iostream>
//#include <thread>
//#include<chrono>
//using namespace std;
//
//void func(int num,string str)
//{
//    for(int i=0;i<5;i++)
//    {
//        cout<<"子线程：i="<<i<<"num:"<<num<<"str:"<<str<<endl;
//    }
//}
//
//void func1()
//{
//    for (int i = 0; i < 10; ++i)
//    {
//        cout << "子线程: i = " << i << endl;
//    }
//}
//
//int main()
//{
//    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
//    thread t(func, 520, "i love you");
//    thread t1(func1);
//    cout << "线程t 的线程ID: " << t.get_id() << endl;
//    cout << "线程t1的线程ID: " << t1.get_id() << endl;
//}
////运行结果
//主线程的线程ID: 0xa00000010
//子线程：i=0num:520str:i love you
//        子线程：i=1num:520str:i love you
//        子线程：i=2num:520str:i love you
//        子线程：i=3num:520str:i love you
//        子线程：i=4num:520str:i love you
//        线程t 的线程ID: 0xa000229d0
//线程t1的线程ID: 0xa00022af0
//子线程: i = 0
//子线程: i = 1
//子线程: i = 2
//子线程: i = 3
//子线程: i = 4
//子线程: i = 5
//子线程: i = 6
//子线程: i = 7
//子线程: i = 8
//子线程: i = 9

//int main()
//{
//    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
//    thread t(func, 520, "i love you");
//    thread t1(func1);
//    cout << "线程t 的线程ID: " << t.get_id() << endl;
//    cout << "线程t1的线程ID: " << t1.get_id() << endl;
//    t.join();
//    t1.join();
//}

//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//
//void download1()
//{
//    // 模拟下载, 总共耗时500ms，阻塞线程500ms
//    this_thread::sleep_for(chrono::milliseconds(500));
//    cout << "子线程1: " << this_thread::get_id() << ", 找到历史正文...." << endl;
//}
//
//void download2()
//{
//    // 模拟下载, 总共耗时300ms，阻塞线程300ms
//    this_thread::sleep_for(chrono::milliseconds(300));
//    cout << "子线程2: " << this_thread::get_id() << ", 找到历史正文...." << endl;
//}
//
//void doSomething()
//{
//    cout << "集齐历史正文, 呼叫罗宾...." << endl;
//    cout << "历史正文解析中...." << endl;
//    cout << "起航，前往拉夫德尔...." << endl;
//    cout << "找到OnePiece, 成为海贼王, 哈哈哈!!!" << endl;
//    cout << "若干年后，草帽全员卒...." << endl;
//    cout << "大海贼时代再次被开启...." << endl;
//}
//
//int main()
//{
//    thread t1(download1);
//    thread t2(download2);
//    // 阻塞主线程，等待所有子线程任务执行完毕再继续向下执行
//    t1.join();
//    t2.join();
//    doSomething();
//}

//int main()
//{
//    cout << "主线程的线程ID: " << this_thread::get_id() << endl;
//    thread t(func, 520, "i love you");
//    thread t1(func1);
//    cout << "线程t 的线程ID: " << t.get_id() << endl;
//    cout << "线程t1的线程ID: " << t1.get_id() << endl;
//    t.detach();
//    t1.detach();
//    // 让主线程休眠, 等待子线程执行完毕
//    this_thread::sleep_for(chrono::seconds(5));
//}

//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//
//void foo()
//{
//    this_thread::sleep_for(std::chrono::seconds(1));
//}
//
//int main()
//{
//    thread t;
//    cout << "before starting, joinable: " << t.joinable() << endl;
//
//    t = thread(foo);
//    cout << "after starting, joinable: " << t.joinable() << endl;
//
//    t.join();
//    cout << "after joining, joinable: " << t.joinable() << endl;
//
//    thread t1(foo);
//    cout << "after starting, joinable: " << t1.joinable() << endl;
//    t1.detach();
//    cout << "after detaching, joinable: " << t1.joinable() << endl;
//}
////运行结果
//before starting, joinable: 0
//after starting, joinable: 1
//after joining, joinable: 0
//after starting, joinable: 1
//after detaching, joinable: 0


//#include <iostream>
//#include <thread>
//using namespace std;
//
//int main()
//{
//    int num = thread::hardware_concurrency();
//    cout << "CPU number: " << num << endl;
//}

#include<iostream>
#include<thread>
using namespace std;
#include<functional>
class Base
{
public:
    void func(string name,int num)
    {
        cout<<"名字:"<<name<<"数字:"<<num<<endl;
    }

    static void func1()
    {
        cout<<"我要玩奥奇传说"<<endl;
    }
};

void func2()
{
    cout<<"你好！"<<endl;
}

int main()
{
    thread t(func2);
    //传递静态成员函数
    thread t1(&Base::func1);
    //传递非静态成员函数
    //需要实例化对象
    Base b;
    //可以传实例也可以传地址
    thread t2(&Base::func,&b,"张三",10);
    thread t3(&Base::func,b,"李四",20);
    //还可以用可调用对象绑定器绑定
    thread t4(bind(&Base::func,&b,"王五",30));//绑定得到的是仿函数
    thread t5(bind(&Base::func,b,"王六",30));//绑定得到的是仿函数
    t.join();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
//运行结果
//你好！我要玩奥奇传说名字:名字:名字:名字:
//
//张三李四王五王六数字:数字:数字:数字:10203030
//很乱很正常
