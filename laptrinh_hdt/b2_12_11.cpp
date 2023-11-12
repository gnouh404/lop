#include<bits/stdc++.h>
using namespace std;
class nguoi{
    string hoten;
    int ns;
    public:
    nguoi(){
        hoten = "";
        ns = 2023;
    }
    void nhap(){
        cout << "Nhap ho ten:";
        getline(cin, hoten);
        cout << "Nhap nam sinh:";
        cin >> ns;
    }
    void xuat(){
        cout << "Ho ten:" << hoten << " Nam sinh:" << ns << " ";
    }
    string gethoten(){return hoten;}
    int getns(){return ns;}
};
class BenhNhan:public nguoi{
    char benh;
    public:
    void nhap(){
        nguoi::nhap();
        cout << "Nhap benh cua benh nhan:";
        cin >> benh;
        cin.ignore();
    }
    void xuat(){
        nguoi::xuat();
        benh == 'A' ? cout << "Benh: A\n" : benh == 'B' ? cout << "Benh:B\n" : benh == 'C' ? cout << "Benh:C\n" : benh == 'D' ? cout << "Benh:D\n" : cout << "";
    }
    char get_benh(){return benh;} 
};
int main(){
    int n;
    cout << "Nhap so benh nhan:";
    cin >> n;
    cin.ignore();
    vector<BenhNhan> a(n);
    for(int i = 0; i < n; i++){
        a[i].nhap();
    }
    vector<int> thongke(4,0);
    for(auto x : a){
        if(x.get_benh() == 'A') thongke[0]++;
        else if(x.get_benh() == 'B') thongke[1]++;
        else if(x.get_benh() == 'C') thongke[2]++;
        else thongke[3]++;
    }
    cout << "\nThong ke cac loai benh:\n";
    cout << "Loai A | " << thongke[0] << "\n";
    cout << "Loai B | " << thongke[1] << "\n";
    cout << "Loai C | " << thongke[2] << "\n";
    cout << "Loai D | " << thongke[3] << "\n";
    int min = a[0].getns();
    int index;
    for(int i = 0; i < n; i++){
        if(a[i].get_benh() == 'D'){
            if(a[i].getns() > min){
                index = i;
            }
        }
    }
    cout << "\nBenh nhan it tuoi nhat mac loai benh D la:\n";
    a[index].xuat();
}
