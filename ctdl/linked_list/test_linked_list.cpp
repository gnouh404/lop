#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
    LIST<float> numbers;
    float inp;
    while (cin >> inp)
    {
        if(inp != '#'){
            cin.ignore();
            numbers.push_back(inp);
        }
        else {
            break;
        }
    }
    int position;
    float value;
    cout << "Nhap vi tri can chen:";
    cin >> position;
    cout << "Nhap gia tri can chen:";
    cin >> value;
    numbers.insert(value, position);
    numbers.in();
}
