#include <bits/stdc++.h>
using namespace std;

class TD
{
    float x, y;

public:
    TD()
    {
        x = y = 0;
    }
    TD(float hd, float td)
    {
        x = hd;
        y = td;
    }
    void xuat()
    {
        cout << x << " " << y << "\n";
    }
};

int main()
{
    TD O, A(1, 1);
    O.xuat();
    A.xuat();
}