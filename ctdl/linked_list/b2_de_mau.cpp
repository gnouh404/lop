#include<bits/stdc++.h>
using namespace std;
class nhan_vien{
    string manv, hoten, gioitinh;
    int namsinh;
    float luong;
    public:
    friend istream &operator>>(istream &cin, nhan_vien &x){
        cout << "Ma nhan vien:"; getline(cin, x.manv);
        cout << "Ho ten:"; getline(cin, x.hoten);
        cout << "Gioi tinh:"; getline(cin, x.gioitinh);
        cout << "Nam sinh:"; cin >> x.namsinh;
        cout << "Luong:"; cin >> x.luong;
        cin.ignore();
        return cin;
    }
    friend ostream &operator<<(ostream &cout, nhan_vien &x){
        cout << "Ma nhan vien:" << x.manv << "\n";
        cout << "Ho ten:" << x.hoten << "\n";
        cout << "Gioi tinh:" << x.gioitinh << "\n";
        cout << "Nam sinh:" << x.namsinh << "\n";
        cout << "Luong:" << x.luong << "\n";
        return cout;
    }
    string get_manv(){return manv;}
    float get_luong(){return luong;}
};
class quanlynv:public nhan_vien{
    list<nhan_vien> a;
    int n;
    public:
    void create_list(){
    
        cout << "Nhap so nhan vien:";
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; i++){
            nhan_vien t;
            cin >> t;
            cout << "\n";
            a.push_back(t);
        }
    }
    void remove_staff(string& x){
        for(list<nhan_vien>::iterator it = a.begin(); it != a.end(); it++){
            if(it->get_manv().compare(x) == 0){
                a.erase(it);
                cout << "\nDa xoa nhan vien co ma " << x << "\n";
                return;
            }
        }
        
    }
    void in_luong(){
        for(auto &x:a){
            if(x.get_luong() > 2000000){
                cout << x;
                cout << "\n\n";
            }
        }
    }
    void in_ds(){
        for(auto &x:a){
            cout << x;
        }
    }
};
int main(){
    quanlynv x;
    string ma;
    x.create_list();
    x.in_ds();
    cout << "Nhap ma nv can xoa:";
    getline(cin, ma);
    x.remove_staff(ma);
    x.in_ds();
}
