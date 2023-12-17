#include<bits/stdc++.h>
using namespace std;
void quicksort(int a[], int left, int right){
    if(left >= right) return; // co <= 1 phan tu
    // 2 phan tu
    else if(left == right + 1) {
        if(a[left] > a[right])
            swap(a[left], a[right]);
    }
    // >= 3 phan tu
    else{
        int pivot = a[right];
        int i = left - 1;
        for(int j = left; j < right; j++){
            if(a[j] <= pivot){
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i+1], a[right]);
        quicksort(a,left,i);
        quicksort(a,i+2,right);
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
    cout << "\nDay sap xep:";
    quicksort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}