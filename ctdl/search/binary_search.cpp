#include<bits/stdc++.h>
using namespace std;
int bs(int a[], int n, int k){
    int l = 0,r = n-1,m;
    while(l <= r){
        m = (l+r)/2;
        if(k == a[m]) return m;
        else if(k < a[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}
void out(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
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
    sort(a,a+n);
    int k;
    cout << "Nhap k:";
    cin >> k;
    if(bs(a,n,k) != - 1) cout << "k co chi so " << bs(a,n,k) << " trong day";
    else cout << "Ko co k trong day";
}