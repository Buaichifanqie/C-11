//#include <iostream>
//#include <thread>
//#include <future>
//using namespace std;
//
//int main()
//{
//    promise<int> pr;
//    thread t1([](promise<int> &p) {
//        p.set_value(100);
//        this_thread::sleep_for(chrono::seconds(3));
//        cout << "睡醒了...." << endl;
//    }, ref(pr));
//
//    future<int> f = pr.get_future();
//    int value = f.get();
//    cout << "value: " << value << endl;
//
//    t1.join();
//    return 0;
//}
////运行结果：
//value: 100
//睡醒了....

//#include <iostream>
//#include <thread>
//#include <future>
//using namespace std;
//
//int main()
//{
//    promise<int> pr;
//    thread t1([](promise<int> &p) {
//        p.set_value_at_thread_exit(100);
//        this_thread::sleep_for(chrono::seconds(3));
//        cout << "睡醒了...." << endl;
//    }, ref(pr));
//
//    future<int> f = pr.get_future();
//    int value = f.get();
//    cout << "value: " << value << endl;
//
//    t1.join();
//    return 0;
//}
//睡醒了....
//value: 100

//#include<iostream>
//#include<thread>
//#include<future>
//using namespace std;
//
//int main()
//{
//    packaged_task<int(int)>task([](int x){
//        return x+=100;
//    });
//    thread t1(ref(task),100);
//    future<int> f = task.get_future();
//    int value = f.get();
//    cout << "value: " << value << endl;
//    t1.join();
//    return 0;
//}
//value: 200
//#include <iostream>
//#include <thread>
//#include <future>
//using namespace std;
//
//int main()
//{
//    cout << "主线程ID: " << this_thread::get_id() << endl;
//    // 调用函数直接创建线程执行任务
//    future<int> f = async([](int x) {
//        cout << "子线程ID: " << this_thread::get_id() << endl;
//        this_thread::sleep_for(chrono::seconds(5));
//        return x += 100;
//    }, 100);
//
//    future_status status;
//    do {
//        status = f.wait_for(chrono::seconds(1));
//        if (status == future_status::deferred)
//        {
//            cout << "线程还没有执行..." << endl;
//            f.wait();
//        }
//        else if (status == future_status::ready)
//        {
//            cout << "子线程返回值: " << f.get() << endl;
//        }
//        else if (status == future_status::timeout)
//        {
//            cout << "任务还未执行完毕, 继续等待..." << endl;
//        }
//    } while (status != future_status::ready);
//
//    return 0;
//}
////运行结果：
//主线程ID: 0xa00000010
//子线程ID: 0xa00022a60
//任务还未执行完毕, 继续等待...
//任务还未执行完毕, 继续等待...
//任务还未执行完毕, 继续等待...
//任务还未执行完毕, 继续等待...
//子线程返回值: 200



//#include <iostream>
//#include <thread>
//#include <future>
//using namespace std;
//
//int main()
//{
//    cout << "主线程ID: " << this_thread::get_id() << endl;
//    // 调用函数直接创建线程执行任务
//    future<int> f = async(launch::deferred, [](int x) {
//        cout << "子线程ID: " << this_thread::get_id() << endl;
//        return x += 100;
//    }, 100);
//
//    this_thread::sleep_for(chrono::seconds(5));
//    cout << f.get();
//
//    return 0;
//}
//
////运行结果：
//主线程ID: 24760
//主线程开始休眠5秒...
//子线程ID: 24760
//200