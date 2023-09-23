#include <bits/stdc++.h>
using namespace std;

class A
{
    int a1, a2;

public:
    A(int a1 = 0, int a2 = 10)
    {
        this->a1 = a1;
        this->a2 = a2;
    }
    void xuat()
    {
        cout << a1 << " " << a2 << endl;
    }
};
class B
{
    int b;
    A u, v;

public:
    B() : u(), v()
    {
        b = -100;
    }
    B(int x, int y) : u(), v(x, y)
    {
        b = 10;
    }
    B(int k1, int k2, int k3, int k4, int k5)
        : u(k2, k3), v(k4, k5)
    {
        b = k1;
    }
};