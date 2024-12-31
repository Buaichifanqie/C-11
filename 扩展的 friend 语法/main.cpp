//#include <iostream>
//using namespace std;
////类声明
//class Tom;
////定义别名
//using Honry=Tom;
////定义两个测试类
//class Jack{
//    //声明友元类
//    //friend class Tom;//C++98标准语法
//    friend Tom;   //C++11标准语法
//    string name="jack"; //默认私有成员
//    void print()
//    {
//        cout<<"my name is ="<<name<<endl;
//    }
//};
//
//class Lucy{
//protected:
//    //声明友元类
//    //friend class Tom;//C++98标准语法
//    friend Honry;   //C++11标准语法
//    string name="lucy";
//    void print()
//    {
//        cout<<"my name is ="<<name<<endl;
//    }
//};
//
//class Tom{
//public:
//    void print(){
//        //通过类成员对象访问其私有成员
//        cout<<"invoke Jock private member:"<<jObj.name<<endl;
//        cout<<"invoke Jack private function:"<<endl;
//        jObj.print();
//        //通过类成员对象访问其保护成员
//        cout<<"invoke Lucy protected member:"<<lObj.name<<endl;
//        cout<<"invoke Lucy protected function:"<<endl;
//        lObj.print();
//    }
//private:
//    string name="tom";
//    Jack jObj;
//    Lucy lObj;
//};
//
//int main()
//{
//    Tom t;
//    t.print();
//    return 0;
//}
//运行结果
//invoke Jock private member:jack
//invoke Jack private function:
//my name is =jack
//invoke Lucy protected member:lucy
//invoke Lucy protected function:
//my name is =lucy

//#include<iostream>
//using namespace std;
//
//class Tom;
//
//template<typename T>
//class Person{
//    friend T;
//};
//
//int main()
//{
//    Person<Tom>p;
//    Person<int>pp;
//    return 0;
//}
//

//假设有一个矩形类，一个圆形类，我们在对其进行了一系列的操作之后，
// 需要验证一下矩形的宽度和高度、圆形的半径是否满足要求，
// 并且要求这个校验操作要在另一个类中完成。
//template<typename T>
//class Rectangle{
//public:
//    friend T;
//    Rectangle(int w,int h):width(w),height(h){}
//private:
//    int width;
//    int height;
//};
//
//template<typename T>
//class Circle{
//public:
//    friend T;
//    Circle(int r):radius(r){}
//private:
//    int radius;
//};
////校验类
//class Verify{
//public:
//    void verifyRectangle(int w,int h,Rectangle<Verify> &r)
//    {
//        if(r.width>=w && r.height>=h)
//        {
//            cout<<"矩形的宽和高都满足要求!"<<endl;
//        }
//        else
//        {
//            cout<<"矩形的宽和高不满足要求!"<<endl;
//        }
//    }
//    void verifyCircle(int r, Circle<Verify> &c)
//    {
//        if (r >= c.radius)
//        {
//            cout << "圆形的半径满足条件!" << endl;
//        }
//        else
//        {
//            cout << "圆形的半径不满足条件!" << endl;
//        }
//    }
//};
//
//int main()
//{
//    Verify v;
//    Circle<Verify> circle(30);
//    Rectangle<Verify> rect(90, 100);
//    v.verifyCircle(70, circle);
//    v.verifyRectangle(100, 100, rect);
//    return 0;
//}
//运行结果
//圆形的半径满足条件!
//矩形的宽和高不满足要求!


#include <iostream>
using namespace std;

template<typename T>
class Rectangle{
public:
    Rectangle(int w, int h):width(w),height(h){}
    int getWidth() const
    {
        return width;
    }
    int getHeight() const {
        return height;
    }
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
private:
    int width;
    int height;
};

template<typename T>
class Circle{
public:
    Circle(int r):radius(r){}
    int getRadius() const { return radius; }
    void setRadius(int r) { radius = r; }
private:
    int radius;
};

class Verify{
public:
    void verifyRectangle(int w, int h, Rectangle<Verify>& r)
    {
        if (r.getWidth() >= w && r.getHeight() >= h)
        {
            cout << "矩形的宽和高都满足要求!" << endl;
        }
        else
        {
            cout << "矩形的宽和高不满足要求!" << endl;
        }
    }

    void verifyCircle(int r, Circle<Verify>& c)
    {
        if (r >= c.getRadius())
        {
            cout << "圆形的半径满足条件!" << endl;
        }
        else
        {
            cout << "圆形的半径不满足条件!" << endl;
        }
    }
};

int main()
{
    Verify v;
    Circle<Verify> circle(30);
    Rectangle<Verify> rect(90, 100);
    v.verifyCircle(70, circle);
    v.verifyRectangle(100, 100, rect);
    return 0;
}

