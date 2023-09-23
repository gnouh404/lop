#include <bits/stdc++.h>
using namespace std;

class Point
{
private:
    float x, y;

public:
    Point(float x, float y) : x(x), y(y) {}
    float get_x()
    {
        return this->x;
    }
    float get_y()
    {
        return this->y;
    }
};

class Line
{
private:
    Point start, end;

public:
    Line(Point start, Point end) : start(start), end(end)
    {
    }
    float length()
    {
        return sqrt(pow((start.get_x() - end.get_x()), 2) + pow((start.get_y() - end.get_y()), 2));
    }
    int is_on_line(Point point)
    {
        Line line1(start, point);
        Line line2(point, end);
        return (line1.length() + line2.length() - length());
    }
};

int main()
{
    Point C(0, 0), A(1, 1), B(-2, 3);
    Line X(A, B);
    cout << endl
         << X.length() << endl;
    if (X.is_on_line(C) == 0)
    {
        cout << "\nDiem C thuoc doan X\n";
    }
    else
        cout << "\nKO";
}