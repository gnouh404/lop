#include<iostream>
#include<algorithm>
using namespace std;
typedef pair< int, int > key_index;
int n,q;
key_index a[100];
int b[100];
void nhap(){
	cin >> n >> q;
	for ( int i = 0; i < n; i++ ){
		int x;
		cin >> x;
		a[i] = key_index( x, i );
	}
	int b[q];
	for ( int i = 0; i < q; i++ ){
		cin >> b[i];
	}
}
int tim( int key){
	key_index tmp( key, 0);
	key_index * f= lower_bound(a, a+n, tmp);
    if(f-> first!= key) return -1;
    return f->second;
}
int main(){
	nhap();
	sort( a , a + n );
	for ( int i = 0; i < q; i++ ){
		cout << tim(b[i]) << "\n";
	}
	
}
