#include<bits/stdc++.h>
using namespace std;

class date{
    int ngay,thang,nam;
    public:
        date(int d=11, int m=10, int y=2023){
            ngay = d;
            thang = m;
            nam = y;
        }
        friend istream& operator>>(istream &cin, date &d){
            cout << "Nhap ngay thang nam: ";
            cin >> d.ngay >> d.thang >> d.nam;
            cin.ignore();
            return cin;
        }
        friend ostream& operator<<(ostream &cout, const date &d){
            cout << d.ngay << "/" << d.thang << "/" << d.nam;
            return cout;
        }
};

class nguoi{
    protected:
    string hoten;
    date ngaysinh;
    string diachi;
    public:
        nguoi(){
            hoten = diachi = "";
        }
        void nhap(){
            cout << "Nhap ho ten:"; getline(cin,hoten);
            cout << "Nhap ngay sinh:"; cin >> ngaysinh;
            cout << "Nhap dia chi:"; cin.ignore(); getline(cin,diachi);

        }
        void xuat(){
            cout << hoten << "\n" << ngaysinh << "\n" << diachi;
        }
        string gethoten(){ return hoten; }
        string getdiachi(){ return diachi; }
        date getngaysinh(){return ngaysinh;}
        ~nguoi(){} 
};

class Customer:public nguoi{
    string makhach;
    int csTruoc, csSau;
    public:
        Customer():nguoi(){
            makhach = "";
            csTruoc = csSau = 0;
        }

        friend istream &operator>>(istream &cin, Customer &c){
            c.nguoi::nhap();
            cout << "\tNhap ma khach hang:"; getline(cin, c.makhach);
            cout << "\tNhap chi so truoc:"; cin>> c.csTruoc;
            cout << "\tNhap chi so sau:"; cin >> c.csSau;
            cin.ignore();
            return cin;
        }
        friend ostream &operator<<(ostream &cout, Customer &c){
            c.nguoi::xuat();
            cout << "Ma khach hang:" << c.makhach << "\n";
            do{
                cout << "Chi so truoc:" << c.csTruoc << "\n";
                cout << "Chi so sau:" << c.csSau << "\n";
            }while(c.csSau > c.csTruoc);
            return cout;   
        }

        double tiendien(){
            int sodien = csSau - csTruoc;
            double tien = 0;
            if(sodien > 300){
                tien += (double)((sodien - 300)* 2834);
                sodien = 300;
            }
            if(sodien > 200){
                tien += (double)((sodien - 200)* 2536);
                sodien = 200;
            }
            if(sodien > 100){
                tien += (double)((sodien - 100)* 2014);
                sodien = 100;
            }
            if(sodien > 50){
                tien += (double)((sodien - 50)* 1734);
                sodien = 50;
            }
            if (sodien > 0){
                tien += (double)(sodien * 2834);
                sodien = 0;
            }
            return tien;
        }
        string getHoten() {return nguoi::gethoten();}
        date getngaysinh() {return nguoi::getngaysinh();}
        string getDiachi() {return nguoi::getdiachi();}
        string getMaKH() {return makhach;}
        int getCST() {return csTruoc;}
        int getCSS() {return csSau;}
        ~Customer(){}
        
};

       

int main(){
    int n;
    cout << "So khach hang : "; cin >> n; cin.ignore();
    
    vector<Customer> kh(n);
    for (int i = 0; i < n; i++){
        cout << "Nhap thong tin khach hang thu " << i + 1 << ":\n";
        cin >> kh[i];
    }

    string tofind_hoten;
    cout << "Nhap ho ten khach hang muon tim : "; getline(cin, tofind_hoten);
    bool timthay = false;
    for (auto x:kh) {
        if (tofind_hoten.compare(x.getHoten())==0) {
            cout << "Tim thay khach hang: \n";
            cout << "\tMa khach hang : " << x.getMaKH() << "\n";
            cout << "\tDien tieu thu : " << x.getCSS()-x.getCST() << "\n";
            cout << "\tSo tien dien phai tra : " << (unsigned long long)round(x.tiendien()) << "\n";
            timthay = true;
        }
    }
    if (!timthay) cout << "Khong tim thay khach hang!\n";

    vector<int> thongke(5, 0);
    for (auto x:kh) {
        int sd = x.getCSS()-x.getCST();
        if (sd>300) thongke[4]++;
        else if (sd>200) thongke[3]++;
        else if (sd>100) thongke[2]++;
        else if (sd>50) thongke[1]++;
        else thongke[0]++;
    }
    cout << "Thong ke theo bac su dung dien: \n";
    for(int i=0; i<5; i++) {
        cout << i+1 << " | " << thongke[i] << "\n"; 
    } 
    
}