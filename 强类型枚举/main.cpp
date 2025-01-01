//#include <iostream>
////匿名枚举
//enum{
//    Red,
//    Green,
//    Blue
//};
////有名枚举
//enum Colors{
//    Red,
//    Green,
//    Blue
//};
//enum China {Shanghai, Dongjing, Beijing, Nanjing};
//enum Japan {Dongjing, Daban, Hengbin, Fudao};
//error C2365: “Dongjing”: 重定义；以前的定义是“枚举数”

////强枚举类型
//enum class Colors{
//    Red,
//    Green,
//    Blue
//};
//
//enum class Colors :char { Red, Green, Blue };
//#include<iostream>
//using namespace std;
//enum class China {Shanghai, Dongjing, Beijing, Nanjing};
//enum class Japan :char {Dongjing, Daban, Hengbin, Fudao};
//int main()
//{
//    //int m=Shanghai;   //error C2440: “初始化”: 无法从“China”转换为“int”
//    //int n=China::Shanghai; //error
//    if((int)China::Beijing>=2)
//    {
//        cout<<"ok"<<endl;
//    }
//    cout<<"size1:"<<sizeof(China::Dongjing)<<endl;
//    cout<<"size2:"<<sizeof(Japan::Dongjing)<<endl;
//    return 0;
//}
//运行结果：
//ok
//size1:4
//size2:1

//enum Colors : char { Red, Green, Blue };

enum Colors : char {
    Red,
    Green,
    Blue
};
int main()
{
    Colors c1=Green; //C++11以前的用法
    Colors c2=Colors::Green; //C++11扩展用法
    return 0;
}



