//#include <iostream>
//#include <cassert>
//#include <cstring>
//
//using namespace std;
//
//// 创建一个指定大小的 char 类型数组
//char* createArray(int size)
//{
//    // 通过断言判断数组大小是否大于0
//    assert(size > 0);    // 必须大于0, 否则程序中断
//    char* array = new char[size];
//    return array;
//}
//
//int main()
//{
//    // 传入合理的大于0的大小，比如100，这里可以根据实际需求调整
//    char* buf = createArray(100);
//    // 使用strncpy进行有长度限制的字符串复制，防止缓冲区溢出
//    strncpy(buf, "hello, world!", sizeof("hello, world!") - 1);
//    buf[sizeof("hello, world!") - 1] = '\0';  // 确保字符串以'\0'结尾
//    cout << "buf = " << buf << endl;
//    delete[] buf;
//    return 0;
//}

// assert.cpp
#include <iostream>
using namespace std;

int main()
{
    static_assert(sizeof(long) == 4, "错误, 不是32位平台...");
    cout << "64bit Linux 指针大小: " << sizeof(char*) << endl;
    cout << "64bit Linux long 大小: " << sizeof(long) <<endl;

    return 0;
}

//通过g++编译程序：
//$g++ assert.cpp -std=c++11
//assert.cpp: In function ‘int main()’:
//assert.cpp:6:5: error: static assertion failed: 错误, 不是32位平台...
//static_assert(sizeof(long) == 4, "错误, 不是32位平台...");

//由于使用的Linux是64位的，因此在编译阶段静态断言检测条件失败，
//提示的错误信息就是我们给静态断言指定的第二个参数对应的那个字符串。
//如果我们将静态断言的条件判断修改一下：
//static_assert(sizeof(long) == 8, "错误, 不是64位平台...");
//然后在进行编译:
//SHELL
//$ g++ assert.cpp -std=c++11
//编译通过，得到可执行程序a.out，然后执行这个程序可以看到如下输出：
//SHELL
//$ ./a.out
//64bit Linux 指针大小: 8
//64bit Linux long 大小: 8
//静态断言条件判断为true，程序就可以继续向下执行了。

