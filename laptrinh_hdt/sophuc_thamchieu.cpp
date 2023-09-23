#include<iostream>
using namespace std;
struct sophuc{
	float thuc,ao;
};
void nhap(sophuc &p){
	cout<<"nhap phan thuc: "; cin>>p.thuc;
	cout<<"nhap phan ao: "; cin>>p.ao;
}
void xuat(const sophuc &p){
	if(p.ao > 0) 
	cout<<p.thuc<<"+"<<p.ao<<"i"<<endl;
	else 
	cout<<p.thuc<<p.ao<<"i"<<endl;
}
void tong(const sophuc &p1, const sophuc &p2, sophuc &kq){
	kq.thuc = p1.thuc +p2.thuc;
	kq.ao = p1.ao + p2.ao;
	cout<<"Tong 2 so phuc la "<<kq.thuc<<"+"<<kq.ao<<"i";
}
void hieu(const sophuc &p1, const sophuc &p2, sophuc &kq){
	kq.thuc = p1.thuc - p2.thuc;
	kq.ao = p1.ao - p2.ao;
	if (kq.ao>0) 
	cout<<"Hieu 2 so phuc la "<<kq.thuc<<"+"<<kq.ao<<"i";
	else 
	cout<<"Hieu 2 so phuc la "<<kq.thuc<<kq.ao<<"i";
}
void nhan(const sophuc &p1, const sophuc &p2, sophuc &kq){
	kq.thuc = p1.thuc*p2.thuc - p1.ao*p2.ao;
	kq.ao = p1.thuc*p2.ao + p1.ao*p2.thuc;
	if (kq.ao>0) cout<<"Tich 2 so phuc la "<<kq.thuc<<"+"<<kq.ao<<"i";
	else cout<<"Tich 2 so phuc la "<<kq.thuc<<kq.ao<<"i";
}
void chia(const sophuc &p1, const sophuc &p2, sophuc &kq){
	kq.thuc = (p1.thuc*p2.thuc + p1.ao*p2.ao)/(p2.thuc*p2.thuc + p2.ao*p2.ao);
	kq.ao = (p1.ao*p2.thuc - p1.thuc*p2.ao)/(p2.thuc*p2.thuc + p2.ao*p2.ao);
	if (kq.ao>0) cout<<kq.thuc<<"+"<<kq.ao<<"i";
	else cout<<kq.thuc<<kq.ao<<"i";
}
int main(){
	sophuc c1,c2,c3,kq;
	nhap(c1);
	xuat(c1);
	nhap(c2);
	xuat(c2);
	nhap(c3);
	xuat(c3);
	tong(c1,c2,kq);
	hieu(c1,c2,kq);
	nhan(c1,c2,kq);
	chia(c1,c2,kq);
}
