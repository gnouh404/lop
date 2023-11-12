#include<bits/stdc++.h>
using namespace std;
int nt(int n){
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            return 0;
        }
    }
    return n>1;
}
class dayso{
    int n;
    vector<int> a;
    public:
    dayso(){
        n = 0;
    }
    friend istream &operator>>(istream &cin, dayso &x){
        cout << "Nhap so phan tu cua day:";
        cin >> x.n;
        cout << "Nhap cac phan tu cua day:\n";
        for(int i = 0; i < x.n; i++){
            int k;
            cin >> k;
            x.a.push_back(k);
        }
        return cin;
    }
    friend ostream &operator<<(ostream &cout, const dayso &x){
        cout << "Day so la:";
        for(int i = 0; i < x.n; i++){
            cout << x.a[i] << " ";
        }
        return cout;
    }
    int tong(){
        int sum = 0;
        for(auto k : a){
            sum += k;
        }
        return sum;
    }
    float tong_so_nt(){
        int sum = 0;
        int dem = 0;
        for(auto k : a){
            if(nt(k)){
                sum += k;
                dem++;
            }
        }
        return (float)sum/dem;
    }
    int check_snt(){
        for(auto k : a){
            if(nt(k)){
                return true;
            }
        }
        return false;
    }
};
int main(){
    dayso x,y;
    cin >> x;
    cin >> y;
    cout << "\n";
    float res;
    res = 1/(float)(x.tong()-y.tong());
    cout << x.tong() << " " << y.tong() << " " << res;
    if(x.tong_so_nt() > y.tong_so_nt()){
        cout << "Day X co tbc cac so nguyen to lon hon day Y"; 
    }
    else if(x.tong_so_nt() == y.tong_so_nt()) cout << "Day X co tbc cac so nguyen to khong lon hon day Y";
    else cout << "Day Y co tbc cac so nguyen to lon hon day X";   
    
}