//#include <iostream>
//#include<vector>
//using namespace std;
//
//template <typename T>
//class Base
//{
//public:
//    void traversal(T& t) {
//        auto it = t.begin();
//        for (; it != t.end(); it++) {
//            cout << *it << " ";
//        }
//        cout << endl;
//    }
//};
//
//int main()
//{
//    vector<int>v{1,2,3,4,5,6,7,8,9,10};
//    Base<vector<int>>b;
//    b.traversal(v);
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//template <typename T=int,T t=520>
//class Test
//{
//public:
//    void print()
//    {
//        cout<<"Current value:"<<t<<endl;
//    }
//};
//
//int main()
//{
//    Test<>t;
//    t.print();
//
//    Test<int,1024>t1;
//    t1.print();
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<typename T=int>// C++98/03不支持这种写法, C++11中支持这种写法
//void func(T t)
//{
//    cout<<"current value:"<<t<<endl;
//}
//int main()
//{
//    func(100);
//    return 0;
//}

#include<iostream>
#include<string>
using namespace std;

//函数定义
template<typename T,typename U=char>
void func(T arg1=100,U arg2=100)
{
    cout<<"arg1:"<<arg1<<",arg2:"<<arg2<<endl;
}

int main()
{
    //模板函数调用
    func('a');
    func(97,'a');
    //func()//编译出错
    return 0;
}


