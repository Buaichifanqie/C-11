#include <iostream>
#include<list>

using namespace std;
////使用方法如下：
//class Test
//{
//public:
//    Test(){}
//    //.......
//};
//
//int main()
//{
//    Test t;
//    //Test && v1=t; //error
//    Test && v2=move(t); //ok
//    return 0;
//}
//int main() {
//    list<string> ls;
//    ls.push_back("hello");
//    ls.push_back("world");
//    //......
//    list<string> ls1 = ls;        // 需要拷贝, 效率低
//    list<string> ls2 = move(ls);
// 函数原型
//template <class T> T&& forward (typename remove_reference<T>::type& t) noexcept;
//template <class T> T&& forward (typename remove_reference<T>::type&& t) noexcept;
//
//// 精简之后的样子
//std::forward<T>(t);

//#include<iostream>
//using namespace std;
//
//template<typename T>
//void printValue(T& t)
//{
//    cout<<"l-value"<<t<<endl;
//}
//
//template<typename T>
//void printValue(T&& t)
//{
//    cout<<"r-value"<<t<<endl;
//}
//
//template<typename T>
//void testForward(T&& v)
//{
//    printValue(v);
//    printValue(move(v));
//    printValue(forward<T>(v));
//    cout<<endl;
//}
//int main()
//{
//    testForward(520);
//    int num=1314;
//    testForward(num);
//    testForward(forward<int>(num));
//    testForward(forward<int&>(num));
//    testForward(forward<int&&>(num));
//}
////打印结果
//l-value520
//r-value520
//r-value520
//
//l-value1314
//r-value1314
//l-value1314
//
//l-value1314
//r-value1314
//r-value1314
//
//l-value1314
//r-value1314
//l-value1314
//
//l-value1314
//r-value1314
//r-value1314

