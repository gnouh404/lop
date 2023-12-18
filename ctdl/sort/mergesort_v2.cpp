#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int i, int k, int j){
    int b[i+j];
    int left = i, right = k+1, t = i;
    while(left <= k && right <= j){
        if(a[left] < a[right]){
            b[t] = a[left];
            left = left + 1;
            t = t + 1;
        }
        else{
            b[t] = a[right];
            right = right + 1;
            t = t + 1;
        }
    }
    if(left > k){
        for(int r = right; r <= j; r++){
            b[t] = a[r];
            t++;
        }
    }
    else{
        for(int r = left; r <= k; r++){
            b[t] = a[r];
            t++;
        }
    }
    for(int r = i; r <= j; r++){
        a[r] = b[r];
    }
}
void mergesort(int a[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    mergesort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}