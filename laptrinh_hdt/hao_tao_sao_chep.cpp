#include <bits/stdc++.h>
using namespace std;

class A
{
    int a1;
    int *a2;

public:
    A(int m = 0, int n = 1)
    {
        a1 = m;
        a2 = new int;
        *a2 = n;
    }
    void biendoi()
    {
        a1 = 10;
        *a2 = 100;
    }
    void xuat()
    {
        cout << a1 << " " << *a2 << endl;
    }
    void operator=(const A &ob)
    {
        a1 = ob.a1;
        a2 = new int;
        *a2 = *(ob.a2);
    }
    // ham tao sao chep
    A(const A &ob)
    {
        a1 = ob.a1;
        a2 = new int;
        *a2 = *(ob.a2);
    }
};
int main()
{
    A x(5, -5);
    A y = x; // ham tao sao chep
    x.xuat();
    y.xuat();
    x.biendoi();
    x.xuat();
    y.xuat();
}