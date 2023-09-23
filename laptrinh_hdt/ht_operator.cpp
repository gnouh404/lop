#include<iostream>
#include<math.h>
using namespace std;

class HT {
	float x,y,r;
	public:
	friend istream & operator>>(istream &cin, HT &h){
		cin >> h.x >> h.y >> h.r;
		return cin;
	}
	friend ostream & operator << (ostream &cout, const HT &h){
		cout << h.x << " " << h.y << " " << h.r;
		return cout;	
	}
	float kc(){
		return sqrt(pow(x,2)+pow(y,2));
	}

	int kt(){
		HT h; 
		if( h.y > 0 && h.y >h.r) return 1;
		return 0;
	}	
};


class DSHT {
	HT *h;
	int n;
	public:
	friend istream &operator >> (istream &cin,  DSHT& lst){
		cout << "so hinh: "; cin >> lst.n;
		lst.h = new HT[lst.n];
		for (int i=0;i<lst.n;i++){
			cin>>lst.h[i];
		}
		return cin;
		}
	
	friend ostream & operator << (ostream &cout, const DSHT&lst){
		for (int i=0;i<lst.n;i++){
			cout << lst.h[i] << "\t";
		}
	return cout;
	}
	void xuly(){ 
	DSHT lst=*this;
	int dem=0;cout<<"\n cac diem thoa man\n";
	for(int i=0;i<lst.n;i++)
		if(lst.h[i].kt()==1)//if(kt(lst.h[i])==1)
		{
			dem++;
			cout<<lst.h[i];
		}
	cout<<"\nCo "<<dem<<" thoa man";
}
};
int main(){
	DSHT x;
	cin >> x;
	cout << x;
	x.xuly();
}
