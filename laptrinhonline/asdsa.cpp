#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],s=0,s1=0;
	for(int i =0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	int tbc = round(s/n);
	for(int i =0;i<n;i++){
		s1 += abs(tbc-a[i]);
	}
	cout<<s1;
}
