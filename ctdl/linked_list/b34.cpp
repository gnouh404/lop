#include <bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;

int main()
{
    LIST<int> a;
    LIST<int> b;
    cout << "Nhap cac phan tu cho ds a:";
    while (true)
    {
        int inp;
        if(cin >> inp){
            a.push_back(inp);
        }
        else{
            cin.clear();
            cin.ignore(1, '\n');
            break;
        }
    }
    cout << "Nhap cac phan tu cho ds b:";
    while (true)
    {
        int inp;
        if(cin >> inp){
            b.push_back(inp);
        }
        else{
            cin.clear();
            cin.ignore(1, '\n');
            break;
        }
    }
    LIST<int> mergedlist = a.merge(a,b);
    mergedlist.in();
    LIST<int> evenlist = a.even_list(a);
    LIST<int> oddlist = a.odd_list(a);
    evenlist.in();
    cout << "\n";
    oddlist.in();
}
