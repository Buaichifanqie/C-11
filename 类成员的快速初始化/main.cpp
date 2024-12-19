#include<iostream>
#include<string>
using namespace std;
class Init
{
public:
    Init(int x, int y, int z) :a(x), b(y), c(z) {}

    int a = 1;
    int b = 2;
    int c = 3;
};

int main()
{
    Init tmp(10, 20, 30);
    cout << "a: " << tmp.a << ", b: " << tmp.b << ", c: " << tmp.c << endl;
    return 0;
}

