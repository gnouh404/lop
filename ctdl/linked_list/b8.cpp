#include <bits/stdc++.h>
#include "so.cpp"
using namespace std;

int main()
{
    dayso<int> lst_so;
    while(true){
        cout<<"\nMenu:"<<endl;
        cout<<"1. Tao danh sach so(dung nhap khi gap dau #)."<<endl;
        cout<<"2. Them 1 phan tu vao danh sach."<<endl;
        cout<<"3. Nhap 1 so k va kiem tra xem co so nao trong day bang k khong."<<endl;
        cout<<"4. Kiem tra co 3 so chan canh nhau trong day khong."<<endl;
        cout<<"5. Sap xep danh sach theo thu tu tang dan."<<endl;
        cout<<"6. Xoa tat ca cac so nguyen to trong danh sach."<<endl;
        cout<<"7. Xoa cac phan tu trung lap trong danh sach."<<endl;
        cout<<"8. Xem danh sach."<<endl;
        cout<<"9. Thoat."<<endl;
        int n;
        cout << "\nXin moi nhap:";
        cin >> n;
        switch(n){
            case 1:{
                lst_so.create_list();
                break;
            }
            case 2:{
                lst_so.add();
                break;
            }
            case 3:{
                lst_so.check_equal();
                break;
            }
            case 4:{
                lst_so.check_3_even();
                break;
            }
            case 5:{
                lst_so.sort();
                break;
            }
            case 6:{
                lst_so.delete_prime();
                break;
            }
            case 7:{
                lst_so.delete_duplicate();
                break;
            }
            case 8:{
                lst_so.display();
                break;
            }
            case 9:{
                return 0;
            }
            default:{
                cout << "\nLua chon khong hop le";
            }
                
        }
    }
    return 0;
}
