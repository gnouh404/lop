#include<iostream>
using namespace std;

int main(){
	int n, a, b, c, nc, ans, tmp;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b >> c;
		ans = a / b;
		nc = a / b;
		while (nc >= c){
			tmp = nc / c;
			ans += tmp;
			nc = nc % c;
			nc += tmp;
		}
		cout << ans << "\n";
	}
}
