#include<iostream>
using namespace std;
// nhap tt hcn, in tt, tong dt 2 hcn, dung con tro doi tuong

class HCN{
	private: 
	float cd, cr;
	friend int main();
//	public:
		void nhap();
		void in();
		float dt(){
			return cd*cr;
		}
};
void HCN::nhap(){
	cout << "cd:"; cin >> cd;
	cout << "cr:"; cin >> cr;
}
void HCN::in(){
	cout << "cdai " << cd << " rong " << cr << " dien tich " << dt() << "\n";
}

int main(){
	HCN h1, *h2;
	cout << "NHap Hcn 1: \n";
	h1.nhap();
	cout << "NHap Hcn 2: \n";
	h2 = new HCN;
	h2->nhap();
	h1.in();
	h2->in();
	cout << "Tong dien tich la: " << h1.dt() + h2->dt();
	
}
