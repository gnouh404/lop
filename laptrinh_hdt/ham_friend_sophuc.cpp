#include<iostream>
using namespace std;

class complex{
    float thuc,ao;
    friend void nhap(complex &p){
        cout << "Nhap phan thuc:";
        cin >> p.thuc;
        cout << "Nhap phan ao:";
        cin >> p.ao;  
    }

    friend void xuat(const complex &p){
        if (p.ao > 0 && p.thuc != 0) cout << p.thuc << " + " << p.ao <<"i";
        if(p.ao < 0 && p.thuc != 0) cout << p.thuc << p.ao << "i";
        if (p.ao == 0 && p.thuc != 0) cout << p.thuc;
        if (p.thuc == 0) cout << p.ao << "i";
    }
    
    friend void tong(const complex &p1, const complex &p2, complex &kq){
        kq.thuc = p1.thuc + p2.thuc;
        kq.ao = p1.ao + p2.ao;
        cout << "Tong 2 so phuc la:\n";
        if (kq.ao > 0 && kq.thuc != 0) cout << kq.thuc << " + " << kq.ao <<"i";
        if(kq.ao < 0 && kq.thuc != 0) cout << kq.thuc << kq.ao << "i";
        if (kq.ao == 0 && kq.thuc != 0) cout << kq.thuc;
        if (kq.thuc == 0) cout << kq.ao << "i";
    }
};

int main(){
    complex a,b,kq;
    nhap(a);
    cout << "\nSo phuc 1 co dang: ";
    xuat(a);
    cout << "\n";
    nhap(b);
    cout << "\nSo phuc 2 co dang: ";
    xuat(b);
    cout << "\n";
    cout << "\nTong 2 so phuc co dang: ";
    tong(a,b,kq);
}