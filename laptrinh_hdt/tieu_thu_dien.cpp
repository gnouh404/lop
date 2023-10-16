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
            cout << "Nhap ngay:"; cin >> d.ngay;
            cout << "Nhap thang:"; cin >> d.thang;
            cout << "Nhap nam:"; cin >> d.nam;
            return cin;
        }
        friend ostream& operator<<(ostream &cout, const date &d){
            cout << d.ngay << "/" << d.thang << "/" << d.nam;
            return cout;
        }
};

class Person{
    protected:
    string hoten;
    date ngaysinh;
    string diachi;
    public:
        Person(string ht = "", date ngaysinh = date(11,10,2023), string dc = ""){
            hoten = ht;
            this->ngaysinh = ngaysinh;
            diachi = dc;
        }
        void nhap(){
            cout << "Nhap ho ten:"; getline(cin,hoten);
            cout << "Nhap ngay sinh:\n"; cin >> ngaysinh;
            cout << "Nhap dia chi:"; cin.ignore(); getline(cin,diachi);

        }
        void xuat(){
            cout << hoten << " " << ngaysinh << " " << diachi;
        }
        string gethoten(){
            return hoten;
        }
};

class Customer:public Person{
    string makhach;
    int csTruoc, csSau;
    public:
        Customer(string ma = "", string ht = "", date ngaysinh = date(1,1,2023), string dc = "", int truoc = 0, int sau = 0):
        Person(ht,ngaysinh,dc){
            makhach = ma;
            csTruoc = truoc;
            csSau = sau;
        }

        double tinhtien(){
            int sodien = csSau - csTruoc;
            double tien = 0;
            if(sodien <= 50) tien = sodien * 1678;
            else if(sodien <= 100) tien = 50 * 1678 + (sodien - 50)*1738;
            else{ 
                if(sodien <= 200) tien = 50 * 1678 + 50 * 1738 + (sodien-100) * 2014;
                else if(sodien <= 300) tien = 50 * 1678 + 50 * 1738 + 100 * 2014 + (sodien - 200) * 2536;
                else tien = 50 * 1678 + 50 *1738 + 100 * 2014 + 100 * 2536 + (sodien - 300) * 2834;
            }
            return tien;
        }
        void xuat(){
            cout << makhach << " "; Person::xuat(); cout << " " << tinhtien() << endl; 
        }
        void nhap(){
            cout << "Nhap ma khach:"; cin.ignore(); getline(cin, makhach);
            Person::nhap(); 
            cout << "Nhap so truoc, so sau:";
            cin >> csTruoc >> csSau;
        }
        
};

class App{
    int n;
    Customer *ctm;
    public:
        void nhap(){
            cout << "Nhap so khach hang:";
            cin >> n;
            ctm = new Customer[n];
            for(int i = 0; i < n; i++){
                ctm[i].nhap();
            }
        }
        void xuat(){
            for (int i = 0; i < n; i++)
            {
                ctm[i].xuat();
            }
        }
        void find(){
            string name;
            cin.ignore();
            cout << "Nhap ten khach hang can tim:";
            getline(cin, name);
            bool check = false;
            for(int i = 0; i < n; i++){
                if(name.compare(ctm[i].gethoten()) == 0) {
                    check = true;
                    ctm[i].xuat();
                }
            }
            if(check == false){
                    cout << "Ko tim thay khach hang " << name;
            }
        }
};       

int main(){
    App app;
    app.nhap();
    app.xuat();
    app.find();
}