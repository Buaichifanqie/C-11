//#include <iostream>
//#include<chrono>
//using namespace std;
//int main()
//{
//    // 定义一个 1 小时的时间间隔
//    chrono::hours h(1);
//    // 定义一个 1 分钟的时间间隔
//    chrono::minutes m(1);
//    // 定义一个 1 秒的时间间隔
//    chrono::seconds s(1);
//    // 定义一个 3 毫秒的时间间隔
//    chrono::milliseconds ms{3};
//    // 定义一个 2 毫秒的时间间隔
//    chrono::milliseconds ms1(2);
//    // 定义一个 3 微秒的时间间隔
//    chrono::microseconds us{3};
//    // 定义一个 3000 秒的时间间隔，单位为整数
//    chrono::duration<int, ratio<1000>> ks(3);
//    // chrono::duration<int, ratio<1000>> d3(3.5);  // error
//    // 定义一个 6.6 秒的时间间隔，单位为 double
//    chrono::duration<double> dd(6.6);
//    // 使用小数表示时钟周期的次数
//    chrono::duration<double, std::ratio<1, 30>> hz(3.5);
//}

//#include<iostream>
//#include<chrono>
//int main()
//{
//    std::chrono::milliseconds ms(9); // 9 毫秒
//    std::chrono::microseconds us=2*ms;  //18000 微秒
//    //时间间隔周期为1/30秒
//    std::chrono::duration<double,std::ratio<1,30>> hz(3.5);
//    std::cout <<  "3 ms duration has " << ms.count() << " ticks\n"
//              <<  "6000 us duration has " << us.count() << " ticks\n"
//              <<  "3.5 hz duration has " << hz.count() << " ticks\n";
//}
////运行结果
//3 ms duration has 9 ticks
//6000 us duration has 18000 ticks
//3.5 hz duration has 3.5 ticks

//#include<iostream>
//#include<chrono>
//using namespace std;
//int main()
//{
//    chrono::minutes t1(10);
//    chrono::seconds t2(60);
//    chrono::seconds t3=t1-t2;
//    cout<<t3.count()<<"second"<<endl;
//}
////运行结果:
//540second


//#include<iostream>
//#include<chrono>
//using namespace std;
//int main()
//{
//    chrono::duration<double,ratio<9,7>> d1(3);
//    chrono::duration<double,ratio<6,5>> d2(1);
//    //d1和d2统一之后的时钟周期
//    chrono::duration<double,ratio<30,35>> d3=d1+d2;
//    chrono::duration<double,ratio<3,35>> d4=d1-d2;
//}
////对于分子6,、9最大公约数为3，对于分母7、5最小公倍数为35，因此推导出的时钟周期为ratio<3,35>
//

//#include<iostream>
//#include<chrono>
//using namespace std;
//using namespace std::chrono;
//int main()
//{
//    //新纪元1970-01-01
//    system_clock::time_point epoch;
//
//    duration<int,ratio<60*60*24>> day(1);
//    //1970-01-01+1天
//    system_clock::time_point ppt(day);
//
//    using dday= duration<int,ratio<60*60*24>>;
//    //1970-01-01+10天
//    system_clock::time_point t(dday(10));
//
//    //系统当前时间
//    system_clock::time_point today=system_clock::now();
//    //转换time_t时间类型
//    time_t tm=system_clock::to_time_t(today);
//    cout<<"今天的日期是:"<<ctime(&tm)<<endl;
//
//    time_t tm1=system_clock::to_time_t(today+day);
//    cout<<"明天的日期是:"<<ctime(&tm1)<<endl;
//
//    time_t tm2=system_clock::to_time_t(epoch);
//    cout<<"新纪元的日期是:"<<ctime(&tm2)<<endl;
//
//    time_t tm3=system_clock::to_time_t(ppt);
//    cout<<"1970-01-02的日期是:"<<ctime(&tm3)<<endl;
//
//    time_t tm4=system_clock::to_time_t(t);
//    cout<<"1970-01-11的日期是:"<<ctime(&tm4)<<endl;
//}
////运行结果:
//今天的日期是:Thu Jan  2 22:33:05 2025
//
//明天的日期是:Fri Jan  3 22:33:05 2025
//
//新纪元的日期是:Thu Jan  1 08:00:00 1970
//
//1970-01-02的日期是:Fri Jan  2 08:00:00 1970
//

//#include<iostream>
//#include<chrono>
//using namespace std;
//using namespace std::chrono;
//int main()
//{
//    //获取开始时间点
//    steady_clock::time_point start=steady_clock::now();
//    //执行业务流程
//    cout<<"print 1000 stars...."<<endl;
//    for(int i=0;i<1000;i++)
//    {
//        cout<<"*";
//    }
//    cout<<endl;
//    //获取结束时间点
//    steady_clock::time_point last=steady_clock::now();
//    //计算耗时
//    auto dt=last-start;
//    //输出耗时
//    cout<<"time span:"<<dt.count()<<"seconds"<<endl;
//    return 0;
//}
//运行结果:
//print 1000 stars....
//time span:2737600seconds

//#include<iostream>
//#include<chrono>
//using namespace std;
//using namespace std::chrono;
//void f()
//{
//    cout << "print 1000 stars ...." << endl;
//    for (int i = 0; i < 1000; ++i)
//    {
//        cout << "*";
//    }
//    cout << endl;
//}
//int main()
//{
//    auto t1=steady_clock::now();
//    f();
//    auto t2=steady_clock::now();
//    // 整数时长：时钟周期纳秒转毫秒，要求 duration_cast
//    auto int_ms = duration_cast<chrono::milliseconds>(t2 - t1);
//    // 小数时长：不要求 duration_cast
//    duration<double, ratio<1, 1000>> fp_ms = t2 - t1;
//
//    cout << "f() took " << fp_ms.count() << " ms, "
//         << "or " << int_ms.count() << " whole milliseconds\n";
//
//}
////运行结果:
////print 1000 stars....
////f() took 2.4266 ms, or 2 whole milliseconds

#include <chrono>
#include <iostream>
using namespace std;

// 使用 std::chrono::high_resolution_clock 定义一个名为 Clock 的类型别名
using Clock = chrono::high_resolution_clock;
// 使用 std::chrono::milliseconds 定义一个名为 Ms 的类型别名
using Ms = chrono::milliseconds;
// 使用 std::chrono::seconds 定义一个名为 Sec 的类型别名
using Sec = chrono::seconds;
// 定义一个模板类型别名 TimePoint，它表示一个时间点，其时钟类型为 Clock，时间间隔类型为 Duration
template<class Duration>
using TimePoint = chrono::time_point<Clock, Duration>;

void print_ms(const TimePoint<Ms>& time_point)
{
    std::cout << time_point.time_since_epoch().count() << " ms\n";
}

int main()
{
    TimePoint<Sec> time_point_sec(Sec(6));
    // 无精度损失, 可以进行隐式类型转换
    TimePoint<Ms> time_point_ms(time_point_sec);
    print_ms(time_point_ms);    // 6000 ms

    time_point_ms = TimePoint<Ms>(Ms(6789));
    // error，会损失精度，不允许进行隐式的类型转换
    //TimePoint<Sec> sec(time_point_ms);

    // 显示类型转换,会损失精度。6789 truncated to 6000
    time_point_sec = std::chrono::time_point_cast<Sec>(time_point_ms);
    print_ms(time_point_sec); // 6000 ms
}

