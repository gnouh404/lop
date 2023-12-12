#include<bits/stdc++.h>
using namespace std;

class MatHang{
    char *ma;
    short color;
    int so_luong;
    long gia;
    public:
        MatHang(){
            ma = NULL;
            color = -1;
            so_luong = -1;
            gia = -1;
        }
        MatHang(char *ma, short color, int so_luong, long gia){
            ma = new char[strlen(ma)]; 
            strcpy(this->ma, ma);
            this->color = color;
            this->so_luong = so_luong;
            this->gia = gia;
        }
        void nhap(){
            ma = new char[10];
            cout << "Nhap ma:";
            cin.getline(ma, 10);
            cout << "Nhap mau:";
            cin >> this->color;
            cout << "Nhap so luong:";
            cin >> this->so_luong;
            cout << "Nhap gia:";
            cin >> this->gia;
        }
        void xuat(){
            cout << "Ma:" << this->ma << " Mau:" << this->color << " So luong:" << this->so_luong << " Gia:" << this->gia << "\n";
        }
};

class Hang: public MatHang{
    string kich_co;
    public:
        Hang():MatHang(){
            kich_co = "-1";
        }
        Hang(string size):MatHang(){
            kich_co = size;
        }
        Hang(char *ma, short color, int so_luong, long gia, string size):MatHang(ma,color,so_luong,gia){
            kich_co = size;
        }
};

int main(){
    MatHang a;
    a.nhap();
    a.xuat();
}