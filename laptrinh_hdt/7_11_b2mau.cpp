#include<bits/stdc++.h>
using namespace std;
class ngaythang{
    int ngay, thang, nam;
    public:
    ngaythang(int ngay = 1, int thang = 1, int nam = 1){
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    void nhap(){
        cout << "Nhap ngay, thang, nam(dd/mm/yy):";
        cin >> ngay >> thang >> nam;
        cin.ignore();
    }
    void xuat(){
        cout << ngay << "/" << thang << "/" << nam << "\n";
    }
    int getngay(){return ngay;}
    int getthang(){return thang;}
    int getnam(){return nam;}
};
class nguoi{
    string hoten;
    ngaythang ngaysinh;
    string diachi;
    public:
    void nhap(){
        cout << "\nNhap ho ten:";
        getline(cin, hoten);
        ngaysinh.nhap();
        cout << "Nhap dia chi:";
        getline(cin, diachi);
    }
    void xuat(){
        cout << "Ho ten:" << hoten << " Dia chi:" << diachi;
        cout << "\nNgay sinh:";
        ngaysinh.xuat(); 
    }
    string gethoten(){return hoten;}

};
class KHTT:public nguoi{
    string makh;
    int cstrc, cssau;
    public:
    void nhap(){
        nguoi::nhap();
        cout << "Nhap ma khach hang:";
        getline(cin, makh);
        cout << "Nhap chi so truoc, chi so sau:";
        cin >> cstrc >> cssau;
        cin.ignore();
    }
    void xuat(){
        cout << "\nMa khach hang:" << makh << "\n";
        nguoi::xuat();
        cout << "So dien tieu thu:" << sodientieuthu() << " So tien phai tra:" << tinhtien() <<  "\n";
    }
    int sodientieuthu(){return cssau - cstrc;}
    double tinhtien(){
        int sodien = cssau - cstrc;
        double tien = 0;
        if(sodien > 400){
            tien += (double)((sodien - 400)*2927);
            sodien = 400;
        }
        if(sodien > 300){
            tien += (double)((sodien - 300)*2834);
            sodien = 300;
        }
        if(sodien > 200){
            tien += (double)((sodien - 200)*2536);
            sodien = 200;
        } 
        if(sodien > 100){
            tien += (double)((sodien - 100)*2014);
            sodien = 100;
        }
        if(sodien > 50){
            tien += (double)((sodien - 50)*1734);
            sodien = 50;
        }
        if(sodien > 0){
            tien += (double)(sodien * 1678);
            sodien = 0;
        }
        return tien;
    }
};
int main(){
    int n;
    cout << "Nhap so khach hang:";
    cin >> n;
    cin.ignore();
    vector<KHTT> kh(n);
    for(int i = 0; i < n; i++){
        kh[i].nhap();
    }
    // for(auto &x : kh){
    //     x.xuat();
    // }
    string to_find;
    bool check = false;
    cout << "Nhap ten khach hang can tim:";
    getline(cin, to_find);
    for(int i = 0; i < n; i++){
        if(to_find.compare(kh[i].gethoten()) == 0){
            kh[i].xuat();
            check = true;
        }
    }
    if(!check) cout << "\nKo tim thay khach hang\n";
    vector<int> thongke(6, 0);
    for(auto x:kh){
        int sd = x.sodientieuthu();
        if(sd > 400) thongke[5]++;
        else if(sd > 300) thongke[4]++;
        else if(sd > 200) thongke[3]++;
        else if(sd > 100) thongke[2]++;
        else if(sd > 50) thongke[1]++;
        else thongke[0]++;
    }
    cout << "\nThong ke so khach hang theo bac dien tieu thu:\n";
    for(int i = 0; i < 6; i++){
        cout << "Bac " << i + 1 << " | " <<  thongke[i] << "\n";
    }
}