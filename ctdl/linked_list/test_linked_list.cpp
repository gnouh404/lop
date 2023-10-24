#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
    Don_list<float> numbers;
    float inp;
    while (cin >> inp)
    {
        if(inp == '#'){
            break;
        }
        else {
            numbers.push_back(inp);
        }
    }
    int position;
    float value;
    cout << "\nNhap vi tri can chen:";
    cin >> position;
    cout << "\nNhap gia tri can chen:";
    cin >> value;
    numbers.insert(value, position);
    for(auto it = numbers.dau(); it != numbers.cuoi(); it++){
        cout << *it << " ";
    }
}
