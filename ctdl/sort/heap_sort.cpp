#include<bits/stdc++.h>
using namespace std;
void out(int a[], int n);
void make_heap_node(int a[], int n, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < n  && a[left] > a[max]){
        max = left;
    }
    if(right < n && a[right] > a[max]){
        max = right;
    }
    if(max != i){
        swap(a[i],a[max]);
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
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        make_heap_node(a,i,0);
        cout << "i =" << i << "  "; out(a,n);
    }
}
void out(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n\n";
}
int main(){
    int n;
    cin >> n;
    int *a;
    a = new int[n];
    for(int i = 0; i < n; i++){
        cin >>a[i];
    }
    heapSort(a,n);
    out(a,n);

}