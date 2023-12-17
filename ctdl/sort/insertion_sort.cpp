#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int k = a[i], pos = i - 1;
        while(pos >= 0 && k < a[pos]){
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = k;
    }
}