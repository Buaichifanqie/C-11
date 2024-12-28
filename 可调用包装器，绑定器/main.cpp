//#include <iostream>
//using namespace std;
//int print(int a,double b)
//{
//    cout<<a<<b<<endl;
//    return 0;
//}
////定义函数指针
//int (*func)(int,double)=&print;

//#include<iostream>
//using namespace std;
//#include<string>
//#include<vector>
//
//struct Test
//{
//    //()重载操作符
//    void operator()(string msg)
//    {
//        cout<<"msg:"<<msg<<endl;
//    }
//};
//
//int main()
//{
//    Test t;
//    t("我要玩奥奇传说！！！");//仿函数
//    return 0;
//}


//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//using func_ptr=void(*)(int,string);
//struct Test
//{
//    static void print(int a,string b)
//    {
//        cout<<"name:"<<b<<",age:"<<a<<endl;
//    }
//    //将类对象转换为函数指针
//    operator func_ptr()
//    {
//        return print;
//    }
//};
//int main()
//{
//    Test t;
//    //对象转换为函数指针，并调用
//    t(19,"aoqi");
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//struct Test
//{
//    void print(int a,string b)
//    {
//        cout << "name: " << b << ", age: " << a << endl;
//    }
//    int m_num;
//};
//
//int main()
//{
//    //定义类成员函数指针指向类成员函数
//    void(Test::*func_ptr)(int,string)=&Test::print;
//    //类成员指针指向类成员变量
//    int Test::*obj_ptr=&Test::m_num;
//
//    Test t;
//    //通过类成员函数指针调用类成员函数
//    (t.*func_ptr)(19,"luff");
//    // 通过类成员指针初始化类成员变量
//    t.*obj_ptr=1;
//    cout<<"number is:"<<t.m_num<<endl;
//    return 0;
//}

//#include <functional>
//std::function<返回值类型(参数类型列表)> diy_name = 可调用对象;

//#include<iostream>
//using namespace std;
//#include<functional>
//int add(int a,int b)
//{
//    cout<<a<<"+"<<b<<"="<<a+b<<endl;
//    return a+b;
//}
//
//class T1
//{
//public:
//    static int sub(int a,int b)
//    {
//        cout<<a<<"-"<<b<<"="<<a-b<<endl;
//        return a-b;
//    }
//};
//
//class T2
//{
//public:
//    int operator()(int a,int b)
//    {
//        cout<<a<<"*"<<b<<"="<<a*b<<endl;
//        return a*b;
//    }
//};
//
//int main()
//{
//    //绑定一个普通函数
//    function<int(int,int)> f1=add;
//    //绑定一个静态成员函数
//    function<int(int,int)> f2=T1::sub;
//    //绑定一个仿函数
//    T2 t;
//    function<int(int,int)> f3=t;
//    //函数调用
//    f1(9,3);
//    f2(9,3);
//    f3(9,3);
//    return 0;
//}
////运行结果
//9+3=12
//9-3=6
//9*3=27
//#include<iostream>
//using namespace std;
//#include<functional>
//
//class A {
//public:
//    //构造函数参数是一个包装器对象
//    A(const function<void()> &f) : callback(f) {
//
//    }
//
//    void notify()
//    {
//        callback();//通过构造函数得到的函数指针
//    }
//private:
//    function<void()>callback;
//};
//
//class B
//{
//public:
//    void operator()()
//    {
//        cout<<"我要玩奥奇传说！！！"<<endl;
//    }
//};
//
//int main()
//{
//    B b;
//    A a(b);//仿函数通过包装器对象进行包装
//    a.notify();
//}
////运行结果
////我要玩奥奇传说！！！

//绑定器函数使用语法格式如下：
//// 绑定非类成员函数/变量
//auto f = std::bind(可调用对象地址, 绑定的参数/占位符);
//// 绑定类成员函/变量
//auto f = std::bind(类函数/成员地址, 类实例对象地址, 绑定的参数/占位符);
//

//#include<iostream>
//#include<functional>
//using namespace std;
//
//void callFunc(int x,const function<void(int)>& f)
//{
//    if(x%2==0)
//    {
//        f(x);
//    }
//}
//
//void output(int x)
//{
//    cout<<x<<" ";
//}
//void output_add(int x)
//{
//    cout<<x+10<<" ";
//}
//int main()
//{
//    //使用绑定器绑定可调用对象和参数
//    auto f1=bind(output,placeholders::_1);
//    for(int i=0;i<10;i++)
//    {
//        callFunc(i,f1);
//    }
//    cout<<endl;
//
//    auto f2=bind(output_add,placeholders::_1);
//    for(int i=0;i<10;i++)
//    {
//        callFunc(i,f2);
//    }
//    cout<<endl;
//    return 0;
//}
////运行结果：
//0 2 4 6 8
//10 12 14 16 18

//#include<iostream>
//#include<functional>
//using namespace std;
//void output(int x,int y)
//{
//    cout<<x<<" "<<y<<endl;
//}
//int main()
//{
//    //使用绑定器绑定可调用对象和参数，并调用得到的仿函数
//    bind(output,1,2)();
//    bind(output,placeholders::_1,2)(10);
//    bind(output,2,placeholders::_1)(10);
//    // error, 调用时没有第二个参数
//    // bind(output, 2, placeholders::_2)(10);
//    // 调用时第一个参数10被吞掉了，没有被使用
//    bind(output, 2, placeholders::_2)(10, 20);
//    bind(output, placeholders::_1, placeholders::_2)(10, 20);
//    bind(output, placeholders::_2, placeholders::_1)(10, 20);
//}
//
//1  2		// bind(output, 1, 2)();
//10 2		// bind(output, placeholders::_1, 2)(10);
//2 10		// bind(output, 2, placeholders::_1)(10);
//2 20		// bind(output, 2, placeholders::_2)(10, 20);
//10 20		// bind(output, placeholders::_1, placeholders::_2)(10, 20);
//20 10		// bind(output, placeholders::_2, placeholders::_1)(10, 20);

//#include<iostream>
//using namespace std;
//#include<functional>
//class Test {
//public:
//    void output(int x, int y)
//    {
//        cout<<"x:"<<x<<",y:"<<y<<endl;
//    }
//    int m_number=100;
//};
//
//int main()
//{
//    Test t;
//    //绑定类成员函数
//    function<void(int,int)>f1=
//            bind(&Test::output,&t,placeholders::_1,placeholders::_2);
//    //绑定类成员变量（公共）
//    function<int&(void)>f2=bind(&Test::m_number,&t);
//    //调用
//    f1(520,1314);
//    f2()=1234;
//    cout<<"t.m_number:"<<t.m_number<<endl;
//    return 0;
//}
////输出结果
//x:520,y:1314
//t.m_number:1234




