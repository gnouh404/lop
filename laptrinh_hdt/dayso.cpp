#include<bits/stdc++.h>
using namespace std;

class thisinh{
    string ht, sbd, mon_thi;
    float diem;
    public:
    thisinh(){
        ht = sbd = mon_thi = "";
        diem = 0;
    }
    friend istream &operator>>(istream &cin, thisinh &x){
        cout << "Ho ten:"; getline(cin, x.ht);
        cout << "So bao danh:"; getline(cin, x.sbd);
        cout << "Mon thi:"; getline(cin, x.mon_thi);
        cout << "Diem:"; cin >> x.diem;
        cin.ignore();
        return cin;
    }
    void xuat(){
        cout << "Ho ten:" << ht << "\n";
        cout << "So bao danh:" << sbd << "\n";
        cout << "Mon thi:" << mon_thi << "\n";
        cout << "Diem:" << diem << "\n";
    }
    float get_diem(){return diem;}
};
void swap(thisinh &a, thisinh &b){
    thisinh tmp = a;
    a = b;
    b = tmp;
}
class dsts:public thisinh{
    int n;
    thisinh *ds;
    public:
    void nhap(){
        cout << "Nhap so thi sinh:"; cin >> n;
        cin.ignore();
        ds = new thisinh[n];
        for(int i = 0; i < n; i++){
            cin >> ds[i];
        }
    }
    void xuat(){
        for(int i = 0; i < n; i++){
            ds[i].xuat();
        }
    }
    void sort(){
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(ds[j].get_diem() < ds[i].get_diem()){
                    swap(ds[i], ds[j]);
                }
            }
        }
    }
};
int main(){
    dsts a;
    a.nhap();
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    a.xuat();
    a.sort();
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    a.xuat();
}