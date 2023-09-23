#include<iostream>
using namespace std;
int bs(int a[], int n, int x){
	int l = 0, r = n-1,m;
	int res = 0;
	while (l<=r){
		m = (l+r)/2;
		if(a[m] <= x){
			res = m;
			r = m - 1;
		}
		else l = m +1;
	}
	if (res != 0 ) return res;
	else return -1;
}
int main(){
	int n,q;
	cin >> n >> q;
	int a[n], x[q];
	for (int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for ( int i = 0; i < q; i++){
		cin >> x[i];
	}
	for (int i = 0; i < q; i++){
		cout << bs(a,n,x[i]) + 1 << "\n";
	}
}
