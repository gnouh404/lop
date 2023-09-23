#include<iostream>
#include<stdlib.h>
using namespace std;

struct matrix{
	int n;
	int **a;

}mt;
//istream &operator>>(istream &ob, istream &oj2)
//istream &operator>>(istream &inp, matrix &a):cong thuc
void nhap(const char &name, matrix &x){
	cout << "Nhap thong so ma tran: " <<endl;
	do{
		cout<< "\nNhap n cua ma tran: "; cin>>x.n;
	}while(x.n<=0);
	x.a = new int*[x.n];
	for(int i = 0; i<x.n; i++)
   		x.a[i] = new int[x.n];
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			a[i][j] = 0;
	
	for(int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
	{
		cout << name << i << j <<":"; cin>>x.a[i][j];
	}
	cout<< "\n";
}
istream &operator>>(istream &inp, matrix &x){
	do{
		cout<< "\nNhap n cua ma tran: "; inp>>x.n;
	}while(x.n<=0);
	x.a = new int*[x.n];
	for(int i = 0; i<x.n; i++)
   		x.a[i] = new int[x.n];
	
	for(int i=0;i<x.n;i++)
		for(int j=0;j<x.n;j++)
	{
		 inp>>x.a[i][j];
	}
	cout<< "\n";
	return inp;
}

ostream &operator<<(ostream &out, const matrix &x){
	for(int i=0;i<x.n;i++){
		for(int j=0;j<x.n;j++){
			out<< x.a[i][j] <<" ";
		}
		out<< "\n";
	}
	return out;
}
//struct ps{
//	int ts,ms;
//};
//istream operator>>(istream &inp, ps &p){
//	isp>>p.ts>>p.ms
//}
void in(const char &name ,const matrix &x){
	for(int i=0;i<x.n;i++){
		for(int j=0;j<x.n;j++){
			cout<< x.a[i][j] <<" ";
		}
		cout<< "\n";
	}
	cout<< "\n\n";
}

matrix operator+(const matrix &A, const matrix &B){
	matrix C;
	if(A.n!=B.n) cout<<"KO cong duoc";
	else{
		C.n = A.n;
		C.a = new int*[A.n];
		for(int i = 0; i<C.n; i++)
   			C.a[i] = new int[A.n];	
		for(int i=0;i<C.n;i++)
			for(int j=0;j<C.n;j++){
				C.a[i][j] = A.a[i][j] + B.a[i][j];
			}
//		cout<< "Tong 2 ma tran co dang: "<<endl;
//	for(int i=0;i<A.n;i++){
//		for(int j=0;j<A.n;j++){
//			cout<< C.a[i][j] <<" ";
//		}
//		cout<< "\n";
//	}
}
	return C;
}

matrix operator*(const matrix &A, const matrix &B){
	matrix D;
	if(A.n!=B.n) cout<<"KO nhan duoc";
	else{
		//cap phat dong
		D.n = A.n;
		D.a = new int*[A.n];
		for(int i = 0; i<D.n; i++)
   			D.a[i] = new int[A.n];
		// luu cac phan tu cua tich 2 ma tran	   	
		for(int i=0;i<D.n;i++)
		{
			for(int j=0;j<D.n;j++)
			{
					for(int k=0;k<D.n;k++){
						D.a[i][j] += A.a[i][k] * B.a[k][j];
					}
			}
		}
		
}
	return D;
}

int main(){
	matrix A,B,C,D;
	cout << "Nhap thong so ma tran:\n";
	cout << "Nhap thong so cua ma tran A:\n";
	cin >> A;
	cout << "Ma tran A co dang:\n";
	cout << A;
	cout << "Nhap thong so cua ma tran B:\n";
	cin >> B;
	cout << "Ma tran B co dang:\n";
	cout << B;
	cout << "\n";
	C = A+B;
	cout << "Tong 2 ma tran co dang:\n";
	cout << C;
	cout << "\n";
	D = A*B;
	cout << "Tich 2 ma tran co dang:\n";
	cout << D;
//	nhan(A,B,D);
//	cout<< "Tich 2 ma tran co dang:\n";
//	in('d', D);
}
