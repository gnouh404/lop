#include <bits/stdc++.h>
using namespace std;

class KhachHang
{
    string makhach;
    string hoten;
    string diachi;
    int trc;
    int sau;

public:
    KhachHang()
    {
        makhach = hoten = "";
        trc = sau = 0;
    }
    void nhap()
    {
        cout << "Nhap ma khach hang:";
        getline(cin, makhach);
        cout << "Nhap ho ten:";
        getline(cin, hoten);
        do
        {
            cout << "Nhap so thang truoc:";
            cin >> trc;
            cout << "Nhap so thang sau:";
            cin >> sau;
            cin.ignore();
        } while (sau < trc);
    }
    void xuat()
    {
        cout << "\tMaKH: " << makhach << "\n";
        cout << "\tHoten: " << hoten << "\n";
        cout << "\tDiachi: " << diachi << "\n";
        cout << "\tThang truoc: " << trc << "\n";
        cout << "\tThang sau: " << sau << "\n";
    }
    double tinhtien()
    {
        return (double)(sau - trc) * 3000;
    }
    string gethoten() { return hoten; }
    ~KhachHang() {}
};

class Uutien : public KhachHang
{
    int coupon;

public:
    Uutien() : KhachHang()
    {
        coupon = 0;
    }
    void nhap()
    {
        KhachHang::nhap();
        do
        {
            cout << "Nhap ma giam gia:";
            cin >> coupon;
            cin.ignore();
        } while (coupon < 0 || coupon > 2);
    }
    void xuat()
    {
        KhachHang::xuat();
        cout << "Ma giam gia:";
        coupon == 0 ? cout << "Khong giam gia" : coupon == 1 ? cout << "5%"
                                                             : cout << "10%";
        cout << "\n";
    }
    double sauuutien()
    {
        return (KhachHang::tinhtien() * (1 - (coupon * 0.05)));
    }
    string getHoten() { return KhachHang::gethoten(); }
    ~Uutien() {}
};
bool sapxep(Uutien a, Uutien b){
    return a.sauuutien() > b.sauuutien();
}
int main()
{
    int n;
    cout << "Nhap so khach hang: ";
    cin >> n;
    cin.ignore();
    vector<Uutien> dskh(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin khach hang #" << i + 1 << ":\n";
        dskh[i].nhap();
    }
    
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
                if(dskh[i].sauuutien() < dskh[j].sauuutien()){
                    Uutien tmp = dskh[i];
                        dskh[i] = dskh[j];
                        dskh[j] = tmp;
                }
        }
    }
    for(auto kh : dskh){
        kh.xuat();
    }

    string tofind_hoten;
    bool timthay = false;
    cout << "Nhap ten khach hang can tim: "; getline(cin, tofind_hoten);
    for (int i=0; i<n; i++) {
        if (tofind_hoten.compare(dskh[i].getHoten())==0) {
            cout << "Tim thay khach hang #" << i+1 << ":\n";
            dskh[i].xuat();
            timthay = true;
        }
    }
    if (!timthay) cout << "Khong tim thay khach hang!";
}