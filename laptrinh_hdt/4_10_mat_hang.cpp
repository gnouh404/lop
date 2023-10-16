#include<bits/stdc++.h>
using namespace std;

class MatHang{
    char ma[20];
    short color;
    int so_luong;
    long gia;
    public:
        MatHang(){
            ma = '-1';
            color = -1;
            so_luong = -1;
            gia = -1;
        }
        MatHang(char ma, short color, int so_luong, long gia){
            this->ma = ma;
            this->color = color;
            this->so_luong = so_luong;
            this->gia = gia;
        }
        void nhap(){
            cout << "Nhap ma:";
            cin >> this->ma;
            cout << "Nhap mau:";
            cin >> this->color;
            cout << "Nhap so luong:";
            cin >> this->so_luong;
            cout << "Nhap gia:";
            cin >> this->gia;
        }
        void xuat(){
            cout << "Ma:" << this->ma << " Mau:" << this->color << " So luong:" << this->color << " Gia:" << this->gia << "\n";
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
        Hang(char ma, short color, int so_luong, long gia, string size):MatHang(ma,color,so_luong,gia){
            kich_co = size;
        }
}

int main(){

}