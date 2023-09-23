#include<bits/stdc++.h>
using namespace std;

int dautien(int a[], int n, int x){
	int res = -1, l = 0, r = n - 1, m;
	while( l <= r ){
		m = ( l + r ) / 2;
		if ( a[m] == x){
			res = m + 1;
			r = m - 1;
		}
		else if( a[m] < x){
			l = m + 1;
		}
		else r = m - 1;
	}
	return res;
}
int main() {
    int n,q;
    scanf("%d %d", &n, &q);
    int a[n], b[q];
    for(int i=0;i<n;i++) {
    	scanf("%d", a+i);
	}
    for(int j=0;j<q;j++) {
    	scanf("%d", b+j); 
    }
	for (int j = 0; j < q; j++){
		if ( dautien(a,n,b[j]) == -1){
			cout << 0 << "\n";
		}
		else cout << dautien(a,n,b[j]);
	}

} 
