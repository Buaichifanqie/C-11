#include <iostream>
#include <climits>

using namespace std;

int main()
{
    long long max = LLONG_MAX;
    long long min = LLONG_MIN;
    unsigned long long ullMax = ULLONG_MAX;

    cout << "Max Long Long value: " << max << endl
         << "Min Long Long value: " << min << endl
         << "Max unsigned Long Long value: " << ullMax << endl;
    return 0;
}

//低等级的int到高等级的int
char c=6;
long long d=c;
//标准int 到自定义的int
typedef  int aa;
aa bb=5;
int num=bb;
long long num1=bb;
//有符号的int 无符号的int（内存大小相同） 有符号==》无符号整形
unsigned int num2=num1;

