#include<iostream>
using namespace std;
void round(const float& r, float &s, float &cv){
	s = 3.14*r*r;
	cv = 2*3.14*r;
}
int main(){
//	int a=5;
//	const int &a1=a;
//	cout<<a<<" "<<a1<<endl;
//	cout<<&a<<" "<<&a1<<endl;
//	a1 = 100;
//	cout<<a<<" "<<a1<<endl;
	float dt,cv,bk=5;
	round(bk,dt,cv);
	cout<<dt<<" "<<cv;
}

