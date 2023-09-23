#include<bits/stdc++.h>
using namespace std;
struct v{
	int n;
	int *a;
};

istream &operator>>(istream &inp, v &x){
	cout<<"Nhap chieu cua vector:"; inp>>x.n;
	x.a = new int[x.n];
	for(int i=0;i<x.n;i++){
		cout<<"Nhap phan tu thu "<<i+1<<":"; inp>>x.a[i];
	}
	cout<<"\n";
	return inp;
}

ostream &operator<<(ostream &out, const v &x){
	for(int i=0;i<x.n;i++){
		out<<x.a[i]<<" ";
	}
	return out<<"\n";
}
v operator+(const v &x, const v &y){
	v z;
	z.n =  ( x.n>y.n )? x.n:y.n;
	int lower =  ( x.n < y.n)? x.n : y.n;
	z.a = new int[z.n];
	for(int i =0;i<z.n;i++){
		if(i<lower){
			z.a[i] = x.a[i] + y.a[i];
		}
		else{
			if( x.n == lower) z.a[i] = y.a[i];
			else z.a[i] = x.a[i];
		}
	}
//	for(int i =lower;i<z.n;i++){
//		if(x.n == lower) z.a[i] = y.a[i];
//		else z.a[i] = x.a[i];
//	}
	return z;
}
int nhan(const v &x, const v &y){
	int s = 0;
	int higher = ( x.n > y.n)? x.n : y.n;
	int lower = ( x.n < y.n )? x.n : y.n;
	 
	for ( int i=0 ; i<higher; i++){
		if(i<lower){
			s += x.a[i] * y.a[i];
		}
		else{
			if (x.n == lower) x.a[i] = 0;
			else y.a[i] = 0;
		}
	}
	return s;
}

v nhan_vt(const int &k, v &l){
	v u;
	u.n = l.n;
	u.a = new int[u.n];
	for ( int i=0; i<u.n; i++){
		u.a[i] = k * l.a[i];
	}
	return u;
}
int main(){
	int k;
	v x,y,z,u;
	cin >> x;
	cout << x;
	cout << "\n";
	cin >> y;
	cout << y;
	z = x+y;
	cout << "\n";
	cout << z;
	cout << "\n";
	cout << nhan(x,y);
	cout << "\n";
	cout << "Nhap so can nhan voi vector:"; cin >> k;
	cout << "\n";
	cout << nhan_vt(k,x);
	
}
