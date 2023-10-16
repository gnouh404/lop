#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
    Don_list<float> numbers;
    numbers.push_front(1);
    cout << numbers.front() << " " << numbers.back();
}
