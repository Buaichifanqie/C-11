//// 默认构造函数
//constexpr weak_ptr() noexcept;
//// 拷贝构造
//weak_ptr (const weak_ptr& x) noexcept;
//template <class U> weak_ptr (const weak_ptr<U>& x) noexcept;
//// 通过shared_ptr对象构造
//template <class U> weak_ptr (const shared_ptr<U>& x) noexcept;

//#include<iostream>
//#include<memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> sp(new int);
//
//    weak_ptr<int> wp1;
//    weak_ptr<int> wp2(wp1);
//    weak_ptr<int> wp3(sp);
//    weak_ptr<int> wp4;
//    wp4=sp;
//    weak_ptr<int> wp5;
//    wp5=wp3;
//    return 0;
//}

//// 函数返回所监测的资源的引用计数
//long int use_count() const noexcept;

//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> sp(new int);
//
//    weak_ptr<int> wp1;
//    weak_ptr<int> wp2(wp1);
//    weak_ptr<int> wp3(sp);
//    weak_ptr<int> wp4;
//    wp4 = sp;
//    weak_ptr<int> wp5;
//    wp5 = wp3;
//
//    cout << "use_count: " << endl;
//    cout << "wp1: " << wp1.use_count() << endl;
//    cout << "wp2: " << wp2.use_count() << endl;
//    cout << "wp3: " << wp3.use_count() << endl;
//    cout << "wp4: " << wp4.use_count() << endl;
//    cout << "wp5: " << wp5.use_count() << endl;
//    return 0;
//}
////运行结果
//use_count:
//wp1: 0
//wp2: 0
//wp3: 1
//wp4: 1
//wp5: 1

//#include<iostream>
//#include<memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> shared(new int(10));
//    weak_ptr<int> weak(shared);
//    cout << "1. weak " << (weak.expired() ? "is" : "is not") << " expired" << endl;
//
//    shared.reset();
//    cout << "2. weak " << (weak.expired() ? "is" : "is not") << " expired" << endl;
//
//    return 0;
//}
////运行结果
//1. weak is not expired
//2. weak is expired


//#include<iostream>
//#include<memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int>sp1,sp2;
//    weak_ptr<int> wp;
//
//    sp1=std::make_shared<int>(521);
//    wp=sp1;
//    sp2=wp.lock();
//    cout << "use_count: " << wp.use_count() << endl;
//    sp1.reset();
//    cout << "use_count: " << wp.use_count() << endl;
//
//    sp1 = wp.lock();
//    cout << "use_count: " << wp.use_count() << endl;
//
//    cout << "*sp1: " << *sp1 << endl;
//    cout << "*sp2: " << *sp2 << endl;
//
//    return 0;
//}
//运行结果
//use_count: 2
//use_count: 1
//use_count: 2
//*sp1: 521
//*sp2: 521

//#include <iostream>
//#include <memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> sp(new int(10));
//    weak_ptr<int> wp(sp);
//    cout << "1. wp " << (wp.expired() ? "is" : "is not") << " expired" << endl;
//
//    wp.reset();
//    cout << "2. wp " << (wp.expired() ? "is" : "is not") << " expired" << endl;
//
//    return 0;
//}
////运行结果
//1. wp is not expired
//2. wp is expired


//#include<iostream>
//#include<memory>
//using namespace std;
//
//struct Test
//{
//    shared_ptr<Test> getShardPtr()
//    {
//        return shared_ptr<Test>(this);
//    }
//
//    ~Test()
//    {
//        cout<<"class Test is disstruct..."<<endl;
//    }
//};
//
//int main()
//{
//    shared_ptr<Test> sp1(new Test);
//    cout<<"use_count:"<<sp1.use_count()<<endl;
//    shared_ptr<Test> sp2=sp1->getShardPtr();
//    cout<<"use_count:"<<sp1.use_count()<<endl;
//    return 0;
//}
//执行上面的测试代码，运行中会出现异常，在终端还是能看到对应的日志输出：
//use_count:1
//use_count:1
//class Test is disstruct...
//class Test is disstruct...

//#include <iostream>
//#include <memory>
//using namespace std;
//
//struct Test : public enable_shared_from_this<Test>
//{
//    shared_ptr<Test> getSharedPtr()
//    {
//        return shared_from_this();
//    }
//    ~Test()
//    {
//        cout << "class Test is disstruct ..." << endl;
//    }
//};
//
//int main()
//{
//    shared_ptr<Test> sp1(new Test);
//    cout << "use_count: " << sp1.use_count() << endl;
//    shared_ptr<Test> sp2 = sp1->getSharedPtr();
//    cout << "use_count: " << sp1.use_count() << endl;
//    return 0;
//}
////运行结果
//use_count: 1
//use_count: 2
//class Test is disstruct ...


//#include<iostream>
//#include<memory>
//using namespace std;
//struct TA;
//struct TB;
//
//struct TA
//{
//    shared_ptr<TB> bptr;
//    ~TA()
//    {
//        cout<<"class TA is disstruct..."<<endl;
//    }
//};
//
//struct TB
//{
//    shared_ptr<TA> aptr;
//    ~TB()
//    {
//        cout<<"class TB is disstruct..."<<endl;
//    }
//};
//
//void testPtr()
//{
//    shared_ptr<TA> ap(new TA);
//    shared_ptr<TB> bp(new TB);
//    cout << "TA object use_count: " << ap.use_count() << endl;
//    cout << "TB object use_count: " << bp.use_count() << endl;
//
//    ap->bptr=bp;
//    bp->aptr=ap;
//    cout << "TA object use_count: " << ap.use_count() << endl;
//    cout << "TB object use_count: " << bp.use_count() << endl;
//}
//
//int main()
//{
//    testPtr();
//    return 0;
//}
////运行结果
//TA object use_count: 1
//TB object use_count: 1
//TA object use_count: 2
//TB object use_count: 2

#include <iostream>
#include <memory>
using namespace std;

struct TA;
struct TB;

struct TA
{
    weak_ptr<TB> bptr;
    ~TA()
    {
        cout << "class TA is disstruct ..." << endl;
    }
};

struct TB
{
    shared_ptr<TA> aptr;
    ~TB()
    {
        cout << "class TB is disstruct ..." << endl;
    }
};

void testPtr()
{
    shared_ptr<TA> ap(new TA);
    shared_ptr<TB> bp(new TB);
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;

    ap->bptr = bp;
    bp->aptr = ap;
    cout << "TA object use_count: " << ap.use_count() << endl;
    cout << "TB object use_count: " << bp.use_count() << endl;
}

int main()
{
    testPtr();
    return 0;
}
//运行结果
TA object use_count: 1
TB object use_count: 1
TA object use_count: 2
TB object use_count: 1
class TB is disstruct ...
class TA is disstruct ...



