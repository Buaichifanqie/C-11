//// 管理当前对象的 shared_ptr 实例数量，或若无被管理对象则为 0。
//long use_count() const noexcept;

//// shared_ptr<T> 类模板中，提供了多种实用的构造函数, 语法格式如下:
//std::shared_ptr<T> 智能指针名字(创建堆内存);

//#include<iostream>
//using namespace std;
//#include<memory>

//int main()
//{
//    // 使用智能指针管理一块 int 型的堆内存
//    shared_ptr<int>ptr1(new int(520));
//    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
//    // 使用智能指针管理一块字符数组对应的堆内存
//    shared_ptr<char>ptr2(new char[12]);
//    cout << "ptr2管理的内存引用计数: " << ptr2.use_count()<<endl;
//    // 创建智能指针对象, 不管理任何内存
//    shared_ptr<int>ptr3;
//    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
//    // 创建智能指针对象, 初始化为空
//    shared_ptr<int>ptr4(nullptr);
//    cout<<"ptr4管理的内存引用计数:"<<ptr4.use_count()<<endl;
//    return 0;
//}
//测试代码输出的结果如下:
//ptr1管理的内存引用计数: 1
//ptr2管理的内存引用计数: 1
//ptr3管理的内存引用计数: 0
//ptr4管理的内存引用计数:0



//int *p = new int;
//shared_ptr<int> p1(p);
//shared_ptr<int> p2(p);		// error, 编译不会报错, 运行会出错

//#include<iostream>
//using namespace std;
//#include<memory>
//
//int main()
//{
//    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
//    shared_ptr<int> ptr1(new int(520));
//    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
//    //调用拷贝构造函数
//    shared_ptr<int> ptr2(ptr1);
//    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
//    shared_ptr<int> ptr3=ptr1;
//    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
//    //调用移动构造
//    shared_ptr<int>ptr4(std::move(ptr1));
//    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
//    std::shared_ptr<int> ptr5 = std::move(ptr2);
//    cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;
//    return 0;
//}
////运输结果：
//ptr1管理的内存引用计数: 1
//ptr2管理的内存引用计数: 2
//ptr3管理的内存引用计数: 3
//ptr4管理的内存引用计数: 3
//ptr5管理的内存引用计数: 3


//template< class T, class... Args >
//shared_ptr<T> make_shared( Args&&... args );


//#include<iostream>
//#include<string>
//#include<memory>
//using namespace std;
//
//class Test
//{
//public:
//    Test()
//    {
//        cout << "construct Test..." << endl;
//    }
//    Test(int x)
//    {
//        cout<<"construct Test,x="<<x<<endl;
//    }
//    Test(string str)
//    {
//        cout<<"construct Test,str="<<str<<endl;
//    }
//    ~Test()
//    {
//        cout<<"destruct Test..."<<endl;
//    }
//};
//int main()
//{
//    //使用智能指针管理一块int型的堆内存，内部引用计数为1
//    shared_ptr<int>ptr1=make_shared<int>(520);
//    cout<<"ptr1管理的内存引用计数："<<ptr1.use_count()<<endl;
//
//    shared_ptr<Test>ptr2=make_shared<Test>();
//    cout<<"ptr2管理的内存引用计数："<<ptr2.use_count()<<endl;
//
//    shared_ptr<Test>ptr3=make_shared<Test>(520);
//    cout<<"ptr3管理的内存引用计数："<<ptr3.use_count()<<endl;
//
//    shared_ptr<Test>ptr4=make_shared<Test>("我要玩奥奇传说！");
//    cout<<"ptr4管理的内存引用计数："<<ptr4.use_count()<<endl;
//    return 0;
//}
////运行结果：
//ptr1管理的内存引用计数：1
//construct Test...
//ptr2管理的内存引用计数：1
//construct Test,x=520
//ptr3管理的内存引用计数：1
//construct Test,str=我要玩奥奇传说！
//ptr4管理的内存引用计数：1
//destruct Test...
//destruct Test...
//destruct Test...

//void reset() noexcept;
//
//template< class Y >
//void reset( Y* ptr );
//
//template< class Y, class Deleter >
//void reset( Y* ptr, Deleter d );
//
//template< class Y, class Deleter, class Alloc >
//void reset( Y* ptr, Deleter d, Alloc alloc );

//#include <iostream>
//#include <string>
//#include <memory>
//using namespace std;
//
//int main()
//{
//    // 使用智能指针管理一块 int 型的堆内存, 内部引用计数为 1
//    shared_ptr<int> ptr1 = make_shared<int>(520);
//    shared_ptr<int> ptr2 = ptr1;
//    shared_ptr<int> ptr3 = ptr1;
//    shared_ptr<int> ptr4 = ptr1;
//    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
//    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
//    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
//    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
//
//    ptr4.reset();
//    cout << "ptr1管理的内存引用计数: " << ptr1.use_count() << endl;
//    cout << "ptr2管理的内存引用计数: " << ptr2.use_count() << endl;
//    cout << "ptr3管理的内存引用计数: " << ptr3.use_count() << endl;
//    cout << "ptr4管理的内存引用计数: " << ptr4.use_count() << endl;
//
//    shared_ptr<int> ptr5;
//    ptr5.reset(new int(250));
//    cout << "ptr5管理的内存引用计数: " << ptr5.use_count() << endl;
//
//    return 0;
//}
////运行结果
//ptr1管理的内存引用计数: 4
//ptr2管理的内存引用计数: 4
//ptr3管理的内存引用计数: 4
//ptr4管理的内存引用计数: 4
//ptr1管理的内存引用计数: 3
//ptr2管理的内存引用计数: 3
//ptr3管理的内存引用计数: 3
//ptr4管理的内存引用计数: 0
//ptr5管理的内存引用计数: 1

//T* get() const noexcept;

//#include<iostream>
//#include<string>
//#include<memory>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//    int len=128;
//    shared_ptr<char>ptr(new char[len]);
//    //得到指针的原始地址
//    char* add=ptr.get();
//    memset(add,0,len);
//    strcpy(add,"我要玩奥奇传说！");
//    cout<<"string:"<<add<<endl;
//
//    shared_ptr<int> p(new int);
//    *p=100;
//    cout<<*p.get()<<" "<<*p<<endl;
//    return 0;
//}
////运行结果
//string:我要玩奥奇传说！
//100 100

//#include<iostream>
//#include<memory>
//using namespace std;
//
////自定义删除函数，释放int型内存
//void deleteIntPtr(int* p)
//{
//    delete p;
//    cout<<"int 型内存被释放了...";
//}

//int main()
//{
//    shared_ptr<int> ptr(new int(250), deleteIntPtr);
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//int main()
//{
//    shared_ptr<int> ptr(new int(250),[](int* p)
//    {
//        delete p;
//    });
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> ptr(new int[10],[](int* p)
//    {
//       delete[]p;
//    });
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//
//int main()
//{
//    shared_ptr<int> ptr(new int[10],default_delete<int[]>());
//    return 0;
//}

//#include<iostream>
//#include<memory>
//using namespace std;
//// 定义一个模板函数，用于创建共享智能指针指向一个动态数组
//template<typename T>
//shared_ptr<T> make_share_array(size_t size)
//{
//    // 返回一个共享智能指针，指向动态分配的数组
//    // 使用default_delete<T[]>指定释放数组内存的方式
//    return shared_ptr<T>(new T[size], default_delete<T[]>());
//}
//int main()
//{
//    // 创建一个共享智能指针，指向大小为10的整型数组
//    shared_ptr<int> ptr1 = make_share_array<int>(10);
//    // 输出ptr1的引用计数，应该是1，因为只有ptr1持有该数组
//    cout << ptr1.use_count() << endl;
//    // 创建一个共享智能指针，指向大小为128的字符型数组
//    shared_ptr<char> ptr2 = make_share_array<char>(128);
//    // 输出ptr2的引用计数，应该是1，因为只有ptr2持有该数组
//    cout << ptr2.use_count() << endl;
//    return 0;
//}
////运行结果
//1
//1