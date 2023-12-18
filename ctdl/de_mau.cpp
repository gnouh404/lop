#include<bits/stdc++.h>
using namespace std;
void heapSort(int a[], int n);
int bs(int a[], int n, int k);
void quicksort(int a[], int left, int right){
    if(left >= right) return;
    else if(left + 1 == right){
        if(a[left] > a[right]) swap(a[left], a[right]);
    }
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
class dayso{
    int n;
    int *a;
    public:
    void nhap(){
        cout << "Nhap so phan tu:";
        cin >> n;
        a = new int[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
    void sapxep(){
        heapSort(a,n);
    }
    void qs(){
        quicksort(a,0,n-1);
    }
    void binary_search(){
        int k;
        cout << "\nNhap phan tu can tim:";
        cin >> k;
        if(bs(a,n,k) != -1) cout << "Phan tu can tim co chi so " << bs(a,n,k) << " trong day";
        else cout << "Ko co phan tu " << k << " trong day";
    }
    void out_arr(){
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
    }
};
void make_heap_node(int a[], int n, int i){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int max = i;
    if(left < n && a[left] > a[max]){
        max = left;
    }
    if(right < n && a[right] > a[max]){
        max = right;
    }
    if(max != i){
        swap(a[i], a[max]);
        make_heap_node(a,n,max);
    }
}
void make_heap(int a[], int n){
    for(int i = n/2 - 1; i >= 0; i--){
        make_heap_node(a,n,i);
    }
}
void heapSort(int a[], int n){
    make_heap(a,n);
    for(int i = n-1; i >= 0; i--){
        swap(a[0], a[i]);
        make_heap_node(a,i,0);
    }
}
int bs(int a[], int n, int k){
    int left = 0, right = n -1, mid;
    while(left <= right){
        mid = (left+right)/2;
        if(k == a[mid]) return mid;
        else if(k < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
int main(){
    dayso a;
    a.nhap();
    a.qs();
    a.out_arr();
    
}