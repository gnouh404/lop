#include<iostream>
#include<math.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int a[n],b[m],dem[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	for(int j=0;j<m;j++){
		dem[j] = 0;
		for(int i=0;i<n;i++){
			if(a[i]<=b[j])
				dem[j]++;
		}
		cout<<dem[j]<<"\n";
	}	
}
