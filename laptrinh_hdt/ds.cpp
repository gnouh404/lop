#include<bits/stdc++.h>
using namespace std;
int prime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return n > 1;
}
class daynguyen{
    int n;
    int *a;
    public:
    void nhap(){
        cout << "Nhap so phan tu:";
        cin >> n;
        a = new int[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
    friend void xuat(daynguyen &x){
        for(int i = 0; i < x.n; i++){
            cout << x.a[i] << " ";
        }
        cout << "\n";
    }
    friend ostream &operator<<(ostream &cout, daynguyen &x){
        int check = 0;
        for(int i = 0; i < x.n; i++){
            if(prime(x.a[i])){
                cout << x.a[i] << " ";
                check = 1;
            }
        }
        if(check == 0) cout << "Ko co so nguyen to trong day";
        return cout;
    }
};
int main(){
    daynguyen x;
    x.nhap();
    xuat(x);
    cout << x;
}