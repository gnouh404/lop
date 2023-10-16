#include<bits/stdc++.h>
using namespace std;

int main(){
    list<float> numbers;
    float input;
        cout << "\nNhap so:";
        while(cin>> input){
        if (input == '#'){
            break;
        }
        numbers.push_back(input);    
        }
    for(auto x:numbers){
        cout << x << " ";
    }
    
}