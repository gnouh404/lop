#include <bits/stdc++.h>
using namespace std;

class PTB2
{
    float a, b, c;

public:
    // PTB2()
    // {
    //     a = 1;
    //     b = c = 0;
    // }
    PTB2(float hs1 = 1, float hs2 = 0, float hs3 = 0)
    {
        a = hs1;
        b = hs2;
        c = hs3;
    }
    void xuat()
    {
        cout << a << " " << b << " " << c << "\n";
    }
};
int main()
{
    PTB2 A, B(-2, 7, 9), C(6, 5), D(-9);
    A.xuat();
    B.xuat();
    C.xuat();
    D.xuat();
}