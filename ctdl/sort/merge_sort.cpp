#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int n, int l, int m, int r);
void mergeSort(int a[], int n, int l, int r){
    int m;
    while(l < r){
        m = (l + r) / 2;
        mergeSort(a, n, l, m);
        mergeSort(a, n, m + 1, r);
        merge(a,n,l,m,r);
    }
}
void merge(int a[], int n, int l, int m, int r){
    int b[n];
    int i, j, k;
    k = 0;
    i = l;
    j = m + 1;
    while(i <= m && m + 1 <= r){
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= m) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(int i = r; i >= l; i--) a[i] = b[--k];
}