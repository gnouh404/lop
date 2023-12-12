#include<bits/stdc++.h>
#include "linked_list.cpp"
using namespace std;
int main(){
    LIST<int> a;
    LIST<int> b;
    cout << "Nhập các số nguyên (nhập -1 để kết thúc):" << endl;
            int num;
            while (true) {
                cin >> num;
                if (num == -1) {
                    break;
                }
            a.insertInOrder(num);
            }
    cout << "Nhập các số nguyên (nhập -1 để kết thúc):" << endl;
            
            while (true) {
                cin >> num;
                if (num == -1) {
                    break;
                }
            b.insertInOrder(num);
            }       
    LIST<int> even_listA = a.even_list(a);
    even_listA.in();
}