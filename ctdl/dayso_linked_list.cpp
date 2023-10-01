#include <bits/stdc++.h>
#include "slist.cpp"
using namespace std;

int main(){
    slist<float> numbers;
    float input;
    cout << "\nNhap so:\n";
    while(cin>>input){
        if(input == '#'){
            break;
        }
        else{
            numbers.push_back(input);
        }    
    }
    cout << "\nDay so duoc tao la:\n";
    for(auto x : numbers){
        cout << x << " ";
    }
    int position;
    cout << "\nNhap vi tri can them vao trong danh sach:\n";
    cin >> position;
    numbers.insert(3,3);
    cout << "\nDanh sach sau khi chen them:\n";
    for(auto x : numbers){
        cout << x << " ";
    }
}
