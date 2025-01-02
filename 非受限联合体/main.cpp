//#include <iostream>
//using namespace std;
//union Test
//{
//    int age;
//    long id;
//    //int& tmp=age; //error
//    static char c;
//    static int print()
//    {
//        cout<<"c value:"<<c<<endl;
//        return 0;
//    }
//};
//char Test::c;
////char Test::c='a';
//int main()
//{
//    Test t;
//    Test t1;
//    t.c='b';
//    t1.c='c';
//    t1.age=666;
//    cout<<"t.c:"<<t.c<<endl;
//    cout<<"t1.c:"<<t1.c<<endl;
//    cout<<"t1.age:"<<t1.age<<endl;
//    cout<<"t1.id:"<<t1.id<<endl;
//    t.print();
//    Test::print();
//    return 0;
//}
//运行结果：
//t.c:c
//t1.c:c
//t1.age:666
//t1.id:34359739034
//c value:c
//c value:c


//#include<iostream>
//using namespace std;
//union Student
//{
//    int id;
//    string name;
//};
//int main()
//{
//    Student s;
//    return 0;;
//}
//warning C4624: “Student”: 已将析构函数隐式定义为“已删除”
//error C2280: “Student::Student(void)”: 尝试引用已删除的函数
//ClassName* ptr = new (定位的内存地址)ClassName;

//#include<iostream>
//using namespace std;
//class Base{
//public:
//    Base(){}
//    ~Base(){}
//    void print()
//    {
//        cout<<"number value:"<<number<<endl;
//    }
//private:
//    int number;
//};
//int main()
//{
//    int n=100;
//    Base* b=new(&n)Base;
//    b->print();
//    return 0;
//}
////运行结果：
//number value:100

#include<iostream>
//#include<string>
//using namespace std;
//class Base
//{
//public:
//    void setTest(string str)
//    {
//        notes=str;
//    }
//    void print()
//    {
//        cout<<"Base notes:"<<notes<<endl;
//    }
//private:
//    string notes;
//};
//union Student
//{
//    Student()
//    {
//        new (&name)string;
//    }
//    ~Student(){}
//    int id;
//    Base tmp;
//    string name;
//};
//int main()
//{
//    Student s;
//    s.name="奥奇传说";
//    s.tmp.setTest("奥奇传说好玩！！！");
//    s.tmp.print();
//    cout<<"Student name:"<<s.name<<endl;
//    return 0;
//}
////运行结果：
//Base notes:奥奇传说好玩！！！
//Student name:奥奇传说好玩！！！
//

//木叶村要进行第99次人口普查，人员的登记方式如下：
//- 学生只需要登记所在学校的编号
//- 本村学生以外的人员需要登记其身份证号码
//- 本村外来人员需要登记户口所在地+联系方式

#include<iostream>
#include<string>
using namespace std;
//外来人口信息
struct Foreigner
{
    Foreigner(string s,string ph):addr(s),phone(ph){}
    string addr;
    string phone;
};
//登记人口信息
class Person
{
public:
    enum class Category : char
    {
        Student,
        Local,
        Foreign
    };
    Person(int num):school_id(num),type(Category::Student){}
    Person(string id):id(id),type(Category::Local){}
    Person(string addr,string phone):foreigner(addr,phone),type(Category::Foreign){}
    ~Person(){}

    void print()
    {
        cout<<"Person category:"<<(int)type<<endl;
        switch(type)
        {
            case Category::Student:
                cout<<"Student school_id:"<<school_id<<endl;
                break;
            case Category::Local:
                cout<<"Local id:"<<id<<endl;
                break;
            case Category::Foreign:
                cout<<"Foreign addr:"<<foreigner.addr<<" phone:"<<foreigner.phone<<endl;
                break;
            default:
                break;
        }
    }
private:
    Category type;
    union
    {
        int school_id;
        Foreigner foreigner;
        string id;
    };
};
int main()
{
    Person p1(232);
    Person p2("12121212121");
    Person p3("奥奇大陆","123456789");
    p1.print();
    p2.print();
    p3.print();
    return 0;
}
//运行结果：
//Person category:0
//Student school_id:232
//Person category:1
//Local id:12121212121
//Person category:2
//Foreign addr:奥奇大陆 phone:123456789