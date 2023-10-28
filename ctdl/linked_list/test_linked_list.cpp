#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
    LIST<int> numbers;
    
    while (true)
    {
        int inp;
        if(cin >> inp){
            numbers.push_back(inp);
        }
        else{
            cin.clear();
            cin.ignore(1, '\n');
            break;
        }
    }
    // int position;
    // float value;
    // cout << "Nhap vi tri can chen:";
    // cin >> position;
    // cout << "Nhap gia tri can chen:";
    // cin >> value;
    // numbers.insert(value, position);
    // for(auto it = numbers.dau(); it != numbers.cuoi(); it++){
    //     cout << *it << " ";
    // }
    // cout << "\n" << numbers.size();
    // float k;
    // cout << "Nhap so k de kiem tra:";
    // cin >> k;
    // numbers.equal(k);
    // numbers.sapxep();
    // numbers.deletePrime();
    // numbers.delete_duplicate();
    numbers.check_3_even();
    for(auto it = numbers.dau(); it != numbers.cuoi(); it++){
        cout << *it << " ";
    }
    
}
