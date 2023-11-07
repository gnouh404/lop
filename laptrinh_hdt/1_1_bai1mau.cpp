#include<bits/stdc++.h>
using namespace std;
class Vector{
    int n;
    float *a;
    public:
        Vector(){
            n = 1;
            a = new float;
            a = 0;
        }
        friend istream &operator>>(istream &cin, Vector &x){
            cout << "Nhap chieu cua vector:"; cin >> x.n;
            x.a = new float[x.n];
            for(int i = 0; i < x.n; i++){
                cout << "a" << i +1 << ":";
                cin >> x.a[i];
            }
            return cin;
        }
        void in(){
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
        }
        friend float operator*(Vector &u, Vector &v){
            Vector z;
            z.n = (u.n > v.n) ? u.n : v.n;
            z.a = new float[z.n];
            float kq;
            int lower = min(u.n, v.n);
            for(int i = 0; i < z.n; i++){
                if(i < lower) {
                    kq += u.a[i] * v.a[i];
                }
                else kq += 0;
            }
            return kq;
        }
        friend Vector operator*(int t, Vector &v){
            Vector k;
            k.n = v.n;
            k.a = new float[k.n];
            for(int i = 0; i < k.n; i++){
                k.a[i] = t * v.a[i];
            }
            return k;
        }
};
int main(){
    int m,n;
    Vector u,v;
    cin >> u;
    cout << "Nhap so nguyen n:";
    cin >> n;
    Vector k = n*u;
    cin >> v;
    cout << "Nhap so nguyen m:";
    cin >> m;
    Vector l = m*v;
    float x = k*l;
    cout << x;
}