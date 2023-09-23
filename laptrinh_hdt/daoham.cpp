//#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
class DaThuc{
	int bac;
	float *hs;
//	friend int main();
	public:
void nhap(char tenDT){
	cout<<"Nhap da thuc: "<<tenDT<<endl;
	do{
		cout<<"\nNhap bac cua da thuc: "; cin>>bac;//scanf("%d", n);
	}
	while(bac<0);
	hs = new float[bac+1];
	for(int i=0;i<=bac;i++){
		cout<<"Nhap hs thu "<<i<<":"; cin>>hs[i];//scanf("%d", &a[i])
	}
}
//input Dathuc P, float x .  output P(x)
double tinh(float x){
	double e=0;
	for(int i=0;i<=bac;i++){
		e = e+hs[i]*pow(x,i);
	}
	return e;
}

// ham in ra 1 da thuc
void in( char r){
	cout<< r <<" co cac he so la ";
	for(int i=0;i<=bac;i++){
		cout<< hs[i]<<" ";
	}
	cout<<"\n";
}

DaThuc daoham(){
	DaThuc Pd;
	Pd.bac = bac-1;
	Pd.hs = new float[Pd.bac +1]; // cap phat dong
	//Pn(x)=a0+a1x+a2x^2+...+anx^n
	//Pd=a1+2a2+3a3x^2+...+nanx^n-1
	for(int i=1;i<=bac;i++){
		Pd.hs[i-1] = hs[i]*i;
	}
	return Pd;
}
};

int main(){
	DaThuc P,Q,Pd,Qd;
	float d1,d2;
	P.nhap('P');
	Q.nhap('Q');
	P.in('P');
	Q.in('Q');
	Pd = P.daoham();
	cout<<"\nDao ham cua ";
	Pd.in('P');
	Qd = Q.daoham();
	cout<<"\nDao ham cua ";
	Pd.in('Q');
}
