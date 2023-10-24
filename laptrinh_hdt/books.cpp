#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string maxb;
    string tensach;
    string tacgia;

public:
    Book()
    {
        maxb = tensach = tacgia = "";
    }
    void nhap()
    {
        do
        {
            cout << "Nhap ma xuat ban:";
            getline(cin, maxb);
        } while (maxb.length() > 12 || maxb.length() < 12);
        cout << "Nhap ten sach:";
        getline(cin, tensach);
        cout << "Nhap ten tac gia:";
        getline(cin, tacgia);
    }
    void xuat()
    {
        cout << "Ma xuat ban:" << maxb << "\n";
        cout << "Ten sach:" << tensach << "\n";
        cout << "Ten tac gia:" << tacgia << "\n";
    }
    string gettacgia() { return tacgia; }
    
    friend bool find(string name, Book &a)
    {
        if (name.compare(a.tacgia) == 0)
        {
            return true;
        }
        return false;
            
    }
};

int main()
{
    int n;
    cout << "Nhap so dau sach:";
    cin >> n;
    cin.ignore();
    vector<Book> books(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin cua dau sach thu " << i + 1 << ":\n";
        books[i].nhap();
    }
    string to_find;
    bool check = false;
    cout << "Nhap ten tac gia can tim:";
    getline(cin, to_find);
    for (int i = 0; i < n; i++){
        if(find(to_find, books[i])){
            books[i].xuat();
            check = true;
        }
    }
    if(!check) cout << "\nKo tim thay ten tac gia";
}
