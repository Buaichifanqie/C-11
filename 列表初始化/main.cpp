#include <iostream>
using namespace std;
////数组的初始化
//int array[]={1,3,5,7,9};
//double array1[3]={1.2,3.4,1.4};
//
////对象初始化
//struct Person
//{
//    int id;
//    double salay;
//}zhang3{1,3000};
//
//class Test
//{
//public:
//    Test(int){}
//private:
//    Test(const Test &);
//};
//
//int main()
//{
//    Test t1(520);
//    Test t2=520;
//    Test t3={520};
//    Test t4{520};
//
//    int a1={1314};
//    int a2{1314};
//    int arr1[]={1,2,3,4};
//    int arr2[]{1,2,3,4};
//    return 0;
//}


//int* p=new int{520};
//double b=double{52.1314};
//int* array=new int[3]{1,2,3};

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person{
//public:
//    Person(int id,string name)
//    {
//        cout<<"id:"<<id<<",name:"<<name<<endl;
//    }
//};
//
//Person func()
//{
//    return{8989,"龙岩"};
//}
//int main()
//{
//    Person p=func();
//    return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//struct T1
//{
//    int x;
//    int y;
//}a={123,321};
//
//struct T2
//{
//    int x;
//    int y;
//    T2(int,int):x(10),y(20){}
//}b={123,321};
//
//int main()
//{
//    cout<<"a.x:"<<a.x<<",a.y:"<<a.y<<endl;
//    cout<<"b.x:"<<b.x<<",b.y:"<<b.y<<endl;
//    return 0;
//}
//a.x:123,a.y:321
//b.x:10,b.y:20
#include<iostream>
#include<string>
//int x[]={1,2,3,4,5,6};
//double y[3][3]={
//        {1.23,2.34,3.45},
//        {4.56,5.67,6.78},
//        {7.56,8.67,9.78},
//};
//char carray[]={'a','b','c','d','f','e'};
//std::string sarray[]={"hello","world","nihap","shijie"};

//struct T1
//{
//    int x;
//    long y;
//protected:
//    int z;
//}t{1,233,2};// error, 类中有私有成员, 无法使用初始化列表初始化

//struct T2
//{
//    int x;
//    long y;
//protected:
//    static int z;
//}t{1,23,2};  //error结构体中的静态变量 z 不能使用列表初始化进行初始化，它的初始化遵循静态成员的初始化方式。

//struct T2
//{
//    int x;
//    long y;
//protected:
//    static int z;
//}t{1,200}; //ok
////静态成员初始化
//int T2::z=2;

//#include<iostream>
//#include<string>
//using namespace std;
//struct T2
//{
//    int x;
//    long y;
//protected:
//    static int z;
//}t1{1,100};
////静态成员初始化
//int T2::z=2;
//
//struct T3
//{
//    int x;
//    double y=1.34;
//    int z[3]{1,2,3};
//};
//
//int main()
//{
//    T3 t{520,13.14,{6,7,8}};// error, c++11不支持,从c++14开始就支持了
//    return 0;
//}

//从C++14开始，使用列表初始化也可以初始化在类中使用{}和=初始化过的非静态数据成员。


//#include <iostream>
//#include <string>
//using namespace std;
//
//struct T1
//{
//    int x;
//    double y;
//    // 在构造函数中使用初始化列表初始化类成员
//    T1(int a, double b, int c) : x(a), y(b), z(c){}
//    virtual void print()
//    {
//        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
//    }
//private:
//    int z;
//};
//
//int main()
//{
//    T1 t{ 520, 13.14, 1314 };	// ok, 基于构造函数使用初始化列表初始化类成员
//    t.print();
//    return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//struct T1
//{
//    int x;
//    double y;
//private:
//    int z;
//};
//
//struct T2
//{
//    T1 t1;
//    long x1;
//    double y1;
//};
//
//int main()
//{
//    T2 t2{ {}, 520, 13.14 };
//    return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//void traversal(std::initializer_list<int>a)
//{
//    for(auto it=a.begin();it!=a.end();it++)
//    {
//        cout<<*it<<" ";
//    }
//    cout<<endl;
//}
//
//int main()
//{
//    initializer_list<int>list;
//    cout << "current list size: " << list.size() << endl;
//    traversal(list);
//
//    list={1,2,3,4,5,6,7,8,9,10};
//    cout << "current list size: " << list.size() << endl;
//    traversal(list);
//    cout << endl;
//
//    list = { 1,3,5,7,9 };
//    cout << "current list size: " << list.size() << endl;
//    traversal(list);
//    cout << endl;
//
//    ////////////////////////////////////////////////////
//    ////////////// 直接通过初始化列表传递数据 //////////////
//    ////////////////////////////////////////////////////
//    traversal({ 2, 4, 6, 8, 0 });
//    cout << endl;
//
//    traversal({ 11,12,13,14,15,16 });
//    cout << endl;
//
//}

////运行结果：
//current list size: 0
//
//current list size: 10
//1 2 3 4 5 6 7 8 9 10
//
//current list size: 5
//1 3 5 7 9
//
//2 4 6 8 0
//
//11 12 13 14 15 16


#include<iostream>
using namespace std;
#include<string>
#include<vector>
class Test
{
public:
    Test(std::initializer_list<string> list)
    {
        for(auto it=list.begin();it!=list.end();it++)
        {
            cout<<*it<<" ";
            m_names.push_back(*it);
        }
        cout<<endl;
    }
private:
    vector<string>m_names;
};

int main()
{
    Test t({"aoqi","nihao","longyan"});
    Test t1({"hello","gan","aoli","xiuer"});
    return 0;
}


//输出结果
//aoqi nihao longyan
//hello gan aoli xiuer



