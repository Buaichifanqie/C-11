
//// 通过构造函数初始化对象
//unique_ptr<int> ptr1(new int(10));
//// error, 不允许将一个unique_ptr赋值给另一个unique_ptr
//unique_ptr<int> ptr2 = ptr1;

#include<iostream>
#include<memory>
using namespace std;

//unique_ptr<int> func()
//{
//    return unique_ptr<int>(new int(520));
//}
//
//int main()
//{
//    //通过构造函数初始化
//    unique_ptr<int> ptr1(new int(10));
//    // 通过转移所有权的方式初始化
//    unique_ptr<int> ptr2=move(ptr1);
//    unique_ptr<int> ptr3=func();
//    return 0;
//}

//int main()
//{
//    unique_ptr<int> ptr1(new int(10));
//    unique_ptr<int> ptr2=move(ptr1);
//
//    ptr1.reset();
//    ptr2.reset(new int(200));
//    return 0;
//}

//int main()
//{
//    unique_ptr<int> ptr1(new int(10));
//    unique_ptr<int> ptr2=move(ptr1);
//
//    ptr2.reset(new int(200));
//    cout<<*ptr2.get()<<endl; // 得到内存地址中存储的实际数值 200
//    return 0;
//}

//shared_ptr<int> ptr1(new int(10), [](int*p) {delete p; });	// ok
////unique_ptr<int> ptr1(new int(10), [](int*p) {delete p; });	// error
//
//int main()
//{
//    using func_ptr = void(*)(int*);
//    unique_ptr<int, func_ptr> ptr1(new int(10), [](int*p) {delete p; });
//
//    return 0;
//}

//int main()
//{
//    using func_ptr=void(*)(int*);
//    unique_ptr<int,func_ptr> ptr1(new int(10),[&](int* p)//error
//    {
//        delete p;
//    });
//    return 0;
//}
#include<functional>
int main()
{
    using func_ptr=void(*)(int*);
    unique_ptr<int,function<void(int*)>> ptr1(new int(10),[&](int* p)
    {
        delete p;
    });
    return 0;
}
