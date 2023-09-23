#include<iostream>
using namespace std;
#include<algorithm>

int bs(int a[], int n, int x){
	int pos = -1;

	int left = 0;
	int right = n - 1;

	while (left <= right) {
	int mid = (left + right) / 2;
	if (a[mid] >= x ) {
		pos = mid;
		right = mid - 1;
	}
	}
	return pos;
}

void sapxep( int a[], int c[], int n){
	for ( int i=0 ; i < n - 1; i ++){
		for ( int j = i + 1; j < n ; j++){
			if ( a[i] > a[j] ){
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
}
int main(){
	int n,q;
	cin >> n >> q;
	int a[n], b[q];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> b[i];
	}
	int c[n];
	for (int i = 0; i < n; i++) {
		c[i] = i;
	}
	sapxep(a,c,n);
	
	for (int i = 0; i < q; i++) {
		int pos = bs(a, n, b[i]);
		if (pos == -1) {
			cout << 0 << endl;
		}
		else {
			cout << c[pos] << endl;
		}
	}

}
