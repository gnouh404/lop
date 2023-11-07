#include <bits/stdc++.h>
using namespace std;
class NhanVien
{
    string manv, hoten;
    int namsinh;
    public:
        NhanVien(){
            manv = hoten = "";
            namsinh = 1111;
        }
        void nhap(){
            cout << "Nhap ma nhan vien:";
            getline(cin, manv);
            cout << "Nhap ho ten:";
            getline(cin, hoten);
            cout << "Nhap nam sinh:";
            cin >> namsinh;
        }
        void xuat(){
            cout << "Ma nhan vien:" << manv << " Ho ten:" << hoten << " Nam sinh:" << namsinh << "\n";
        }
        string get_ma(){return manv;}
        string get_hoten(){return hoten;}
        int get_ns(){return namsinh;}

};
class HD: public NhanVien{
    long tiencong;
    int ngaycong;
    public:
        void nhap(){
            NhanVien::nhap();
            cout << "Nhap tien cong:";
            cin >> tiencong;
            cout << "Nhap ngay cong:";
            cin >> ngaycong;
            cin.ignore();
        }
        float tinhluong(){
            return (float)(tiencong * ngaycong);
        }
        void xuat(){
            NhanVien::xuat();
            cout << "Tien cong:" << tiencong << " Ngay cong:" << ngaycong << "\n";
        }
        
};
bool sapxep(HD &a, HD &b){
    return a.tinhluong() > b.tinhluong();
}
int main(){
    int n;
    cout << "Nhap so nguoi nhan vien:";
    cin >> n;
    vector<HD> nv(n);
    cin.ignore();
    long long luong = 0;
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin cua nv thu " << i + 1 << ":\n";
        nv[i].nhap();
        luong += nv[i].tinhluong(); 
    }
    cout << "Tong tien tra cho nv hop dong la " << luong << "\n";
    string to_find;
    bool check = false;
    cout << "Nhap ho ten nv can tim:";
    getline(cin, to_find);
    for(auto &x : nv){
        if(to_find.compare(x.get_hoten()) == 0){
            x.xuat();
            check = true;
        }
    }
    if(!check) cout << "Ko tim thay nhan vien\n";
    int min = nv[0].get_ns();
    int index;
    for(int i = 1; i < n; i++){
        if(nv[i].get_ns() < min){
            min = nv[i].get_ns();
            index = i;
        }
    }
    cout << "Nhan vien HD tre nhat:\n";
    nv[index].xuat(); 
    sort(nv.begin(), nv.end(), sapxep);
    cout << "Danh sach nhan vien theo thu tu luong giam dan\n";
    for(auto &x : nv){
        x.xuat();
    }
}